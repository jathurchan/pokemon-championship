#include <sys/stat.h>
#include <fstream>
#include "Model.hpp"

#define CREATURE 0
#define AURA 1
#define ITEM 2
#define MOVE 3
#define TRIGGER 4
#define TYPE 5

namespace model {

    Model::Model() {
        
    }
    
    Model::Model(std::string creaturePackage, std::string itemPackage) {
        std::set<std::string> creatureDependencies; creatureDependencies.insert(creaturePackage);
        std::set<std::string> itemDependencies; itemDependencies.insert(itemPackage);
        std::set<std::string> moveDependencies;
        std::set<std::string> typeDependencies;
        std::set<std::string> auraDependencies;
        std::set<std::string> triggerDependencies;


        /***************/
        /* PARSE FILES */
        /***************/
        Json::Value* jsonCreature;
        Json::Value* jsonItem;
        Json::Value* jsonMoves;
        Json::Value* jsonTypes;
        Json::Value* jsonAuras;
        Json::Value* jsonTriggers;

        jsonCreature = ParseFiles(creatureDependencies, CREATURE);

        jsonItem = ParseFiles(itemDependencies, ITEM);

        FetchDependencies(jsonCreature, 1, moveDependencies, "Moves");
        int moveDepSize = moveDependencies.size();
        jsonMoves = ParseFiles(moveDependencies, MOVE);

        FetchDependencies(jsonCreature, 1, typeDependencies, "Types");
        FetchDependencies(jsonMoves, moveDepSize, typeDependencies, "Types");
        jsonTypes = ParseFiles(typeDependencies, TYPE);

        FetchDependencies(jsonItem, 1, auraDependencies, "Auras");
        FetchDependencies(jsonMoves, moveDepSize, auraDependencies, "Auras");
        jsonAuras = ParseFiles(auraDependencies, AURA);

        FetchDependencies(jsonItem, 1, triggerDependencies, "Triggers");
        jsonTriggers = ParseFiles(triggerDependencies, TRIGGER);


        /***************/
        /* BUILD MODEL */
        /***************/
        BuildMap(triggerDependencies, jsonTriggers, TRIGGER);
        BuildMap(auraDependencies, jsonAuras, AURA);
        BuildMap(typeDependencies, jsonTypes, TYPE);
        BuildMap(moveDependencies, jsonMoves, MOVE);
        BuildMap(itemDependencies, jsonItem, ITEM);
        BuildMap(creatureDependencies, jsonCreature, CREATURE);

        /*****************/
        /* DELETE ARRAYS */
        /*****************/
        delete[] jsonCreature;
        delete[] jsonItem;
        delete[] jsonMoves;
        delete[] jsonTypes;
        delete[] jsonAuras;
        delete[] jsonTriggers;
    }

    Model::~Model() {
        for(std::pair<std::string, Creature*> creature : this->creatures) {
            delete creature.second;
        }
        for(std::pair<std::string, Item*> item : this->items) {
            delete item.second;
        }
        for(std::pair<std::string, Move*> move : this->moves) {
            delete move.second;
        }
        for(std::pair<std::string, Type*> type : this->types) {
            delete type.second;
        }
        for(std::pair<std::string, Aura*> aura : this->auras) {
            delete aura.second;
        }
        for(std::pair<std::string, Trigger*> trigger : this->triggers) {
            delete trigger.second;
        }
    }

    Creature* Model::GetCreature(std::string name) {
        return creatures[name];
    }

    Item* Model::GetItem(std::string name) {
        return items[name];
    }

    void Model::DispAll() {
        for(std::pair<std::string,Creature*> pair : this->creatures) {
            printf("%s\n", pair.second->GetName().c_str());
        }
        printf("\n");
        for(std::pair<std::string,Item*> pair : this->items) {
            printf("%s\n", pair.second->GetName().c_str());
        }
        printf("\n");
        for(std::pair<std::string,Move*> pair : this->moves) {
            printf("%s\n", pair.second->GetName().c_str());
        }
        printf("\n");
        for(std::pair<std::string,Type*> pair : this->types) {
            printf("%s\n", pair.second->GetName().c_str());
        }
        printf("\n");
        for(std::pair<std::string,Aura*> pair : this->auras) {
            printf("%s\n", pair.second->GetName().c_str());
        }
        printf("\n");
        for(std::pair<std::string,Trigger*> pair : this->triggers) {
            printf("%s\n", pair.first.c_str());
        }
    }

    Json::Value* Model::ParseFiles(std::set<std::string> dependenciesName, int expectedType) {
        int i = 0;
        int depSize = dependenciesName.size();
        Json::Value* jsonArr = new Json::Value[depSize];
        for(std::string name : dependenciesName) {
            struct stat buffer;
            name += ".json";
            if (stat (name.c_str(), &buffer) != 0) {
                std::string err = "File not found : " + name;
                throw std::runtime_error(err);
            }

            std::fstream file;
            Json::CharReaderBuilder builder;
            Json::Value json {};
            std::string err {};

            file.open(name, std::fstream::in);
            Json::parseFromStream(builder, file, &json, &err);
            file.close();

            if (json["Type"].asInt() != expectedType) {
                char err[64];
                sprintf(err, "File isn't of expected type. expected : %d. parsed : %d.", expectedType, json["Type"].asInt());
                throw std::runtime_error(err);
            }

            json.removeMember("Type");

            jsonArr[i++] = json;
        }
        return jsonArr;
    }

    void Model::FetchDependencies(Json::Value* dependencySources, size_t sourceLen, std::set<std::string> &dependencyTarget, std::string type) {
        for(size_t i = 0; i < sourceLen; i++) {
            Json::Value val = dependencySources[i]["Dependencies"][type];
            for(Json::ValueIterator element = val.begin(); element != val.end(); element++) {
                dependencyTarget.insert(val[element.index()].asString());
            }
            dependencySources[i]["Dependencies"].removeMember(type);
            if(dependencySources[i]["Dependencies"].size() <= 0) {
                dependencySources[i].removeMember("Dependencies");
            }
        }
    }

    void Model::BuildMap(std::set<std::string> dependenciesNames, Json::Value* dependencies, int type) {
        switch(type) {
            case CREATURE:
                this->BuildCreatureMap(dependenciesNames, dependencies);
                break;
            case ITEM:
                this->BuildItemMap(dependenciesNames, dependencies);
                break;
            case MOVE:
                this->BuildMoveMap(dependenciesNames, dependencies);
                break;
            case TYPE:
                this->BuildTypeMap(dependenciesNames, dependencies);
                break;
            case AURA:
                this->BuildAuraMap(dependenciesNames, dependencies);
                break;
            case TRIGGER:
                this->BuildTriggerMap(dependenciesNames, dependencies);
                break;
        }
    }

    void Model::BuildCreatureMap(std::set<std::string> dependenciesNames, Json::Value* dependencies) {
        int i = 0;
        char* name = new char[128];
        for(std::string depName : dependenciesNames) {
            Json::Value dependency = dependencies[i++];
            for(Json::ValueIterator element = dependency.begin(); element != dependency.end(); element++) {
                sprintf(name, "%s", element.name().c_str());
                this->creatures[name] = new Creature(name, dependency[element.name()], this->moves, this->types);
            }
        }
        delete[] name;
    }
    void Model::BuildItemMap(std::set<std::string> dependenciesNames, Json::Value* dependencies) {
        int i = 0;
        char* name = new char[128];
        for(std::string depName : dependenciesNames) {
            Json::Value dependency = dependencies[i++];
            for(Json::ValueIterator element = dependency.begin(); element != dependency.end(); element++) {
                sprintf(name, "%s", element.name().c_str());
                this->items[name] = new Item(name, dependency[element.name()], this->auras, this->triggers);
            }
        }
        delete[] name;
        this->items[""] = new Item((char*)"None", this->triggers[""], this->auras[""]);
    }
    void Model::BuildMoveMap(std::set<std::string> dependenciesNames, Json::Value* dependencies) {
        int i = 0;
        char* name = new char[128];
        for(std::string depName : dependenciesNames) {
            Json::Value dependency = dependencies[i++];
            for(Json::ValueIterator element = dependency.begin(); element != dependency.end(); element++) {
                sprintf(name, "%s", element.name().c_str());
                this->moves[name] = new Move(name, dependency[element.name()], this->types, this->auras);
            }
        }
        delete[] name;
    }
    void Model::BuildTypeMap(std::set<std::string> dependenciesNames, Json::Value* dependencies) {
        int i = 0;
        char* name = new char[128];
        for(std::string depName : dependenciesNames) {
            Json::Value dependency = dependencies[i++];
            for(Json::ValueIterator element = dependency.begin(); element != dependency.end(); element++) {
                sprintf(name, "%s", element.name().c_str());
                this->types[name] = new Type(name, dependency[element.name()]);
            }
        }
        delete[] name;
        this->types[""] = new Type();
    }
    void Model::BuildAuraMap(std::set<std::string> dependenciesNames, Json::Value* dependencies) {
        int i = 0;
        char* name = new char[128];
        for(std::string depName : dependenciesNames) {
            Json::Value dependency = dependencies[i++];
            for(Json::ValueIterator element = dependency.begin(); element != dependency.end(); element++) {
                sprintf(name, "%s", element.name().c_str());
                this->auras[name] = new Aura(name, dependency[element.name()]);
            }
        }
        delete[] name;
        this->auras[""] = new Aura();
    }
    void Model::BuildTriggerMap(std::set<std::string> dependenciesNames, Json::Value* dependencies) {
        int i = 0;
        char* name = new char[128];
        for(std::string depName : dependenciesNames) {
            Json::Value dependency = dependencies[i++];
            for(Json::ValueIterator element = dependency.begin(); element != dependency.end(); element++) {
                sprintf(name, "%s", element.name().c_str());
                this->triggers[name] = new Trigger(dependency[element.name()]);
            }
        }
        delete[] name;
        this->triggers[""] = new Trigger();
    }
}
