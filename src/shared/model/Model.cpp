#include <sys/stat.h>
#include <fstream>
#include <set>
#include <memory>
#include "Model.hpp"

#define CREATURE 0
#define EFFECT 1
#define ITEM 2
#define MOVE 3
#define TRIGGER 4
#define TYPE 5

namespace model {
    Model::Model(std::string creaturePackage, std::string itemPackage) {
        std::set<std::string> creatureDependencies; creatureDependencies.insert(creaturePackage);
        std::set<std::string> itemDependencies; itemDependencies.insert(itemPackage);
        std::set<std::string> moveDependencies;
        std::set<std::string> typeDependencies;
        std::set<std::string> effectDependencies;
        std::set<std::string> triggerDependencies;


        /***************/
        /* PARSE FILES */
        /***************/
        Json::Value* jsonCreature;
        Json::Value* jsonItem;
        Json::Value* jsonMoves;
        Json::Value* jsonTypes;
        Json::Value* jsonEffects;
        Json::Value* jsonTriggers;

        jsonCreature = parseFiles(creatureDependencies, CREATURE);

        jsonItem = parseFiles(itemDependencies, ITEM);

        fetchDependencies(jsonCreature, 1, moveDependencies, "Moves");
        int moveDepSize = moveDependencies.size();
        jsonMoves = parseFiles(moveDependencies, MOVE);

        fetchDependencies(jsonCreature, 1, typeDependencies, "Types");
        fetchDependencies(jsonMoves, moveDepSize, typeDependencies, "Types");
        jsonTypes = parseFiles(typeDependencies, TYPE);

        fetchDependencies(jsonItem, 1, effectDependencies, "Effects");
        fetchDependencies(jsonMoves, moveDepSize, effectDependencies, "Effects");
        jsonEffects = parseFiles(effectDependencies, EFFECT);

        fetchDependencies(jsonItem, 1, triggerDependencies, "Triggers");
        jsonTriggers = parseFiles(triggerDependencies, TRIGGER);


        /***************/
        /* BUILD MODEL */
        /***************/
        buildMap(triggerDependencies, jsonTriggers, TRIGGER);
        buildMap(effectDependencies, jsonEffects, EFFECT);
        buildMap(typeDependencies, jsonTypes, TYPE);
        buildMap(moveDependencies, jsonMoves, MOVE);
        buildMap(itemDependencies, jsonItem, ITEM);
        buildMap(creatureDependencies, jsonCreature, CREATURE);

        /*****************/
        /* DELETE ARRAYS */
        /*****************/
        delete[] jsonCreature;
        delete[] jsonItem;
        delete[] jsonMoves;
        delete[] jsonTypes;
        delete[] jsonEffects;
        delete[] jsonTriggers;
    }

    void Model::dispAll() {
        for(std::pair<std::string,Creature*> pair : this->creatures) {
            printf("%s\n", pair.first.c_str());
        }
        printf("\n");
        for(std::pair<std::string,Item*> pair : this->items) {
            printf("%s\n", pair.first.c_str());
        }
        printf("\n");
        for(std::pair<std::string,Move*> pair : this->moves) {
            printf("%s\n", pair.first.c_str());
        }
        printf("\n");
        for(std::pair<std::string,Type*> pair : this->types) {
            printf("%s\n", pair.first.c_str());
        }
        printf("\n");
        for(std::pair<std::string,Effect*> pair : this->effects) {
            printf("%s\n", pair.first.c_str());
        }
        printf("\n");
        for(std::pair<std::string,Trigger*> pair : this->triggers) {
            printf("%s\n", pair.first.c_str());
        }
    }

    Json::Value* Model::parseFiles(std::set<std::string> dependenciesName, int expectedType) {
        int i = 0;
        int depSize = dependenciesName.size();
        Json::Value* jsonArr = new Json::Value[depSize];
        for(std::string name : dependenciesName) {
            struct stat buffer;
            name += ".json";
            if (stat (name.c_str(), &buffer) != 0)
                throw std::invalid_argument("File not found.");

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
                throw std::invalid_argument(err);
            }

            json.removeMember("Type");

            jsonArr[i++] = json;
        }
        return jsonArr;
    }

    void Model::fetchDependencies(Json::Value* dependencySources, size_t sourceLen, std::set<std::string> &dependencyTarget, std::string type) {
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

    void Model::buildMap(std::set<std::string> dependenciesNames, Json::Value* dependencies, int type) {
        switch(type) {
            case CREATURE:
                this->buildCreatureMap(dependenciesNames, dependencies);
                break;
            case ITEM:
                this->buildItemMap(dependenciesNames, dependencies);
                break;
            case MOVE:
                this->buildMoveMap(dependenciesNames, dependencies);
                break;
            case TYPE:
                this->buildTypeMap(dependenciesNames, dependencies);
                break;
            case EFFECT:
                this->buildEffectMap(dependenciesNames, dependencies);
                break;
            case TRIGGER:
                this->buildTriggerMap(dependenciesNames, dependencies);
                break;
        }
    }

    void Model::buildCreatureMap(std::set<std::string> dependenciesNames, Json::Value* dependencies) {
        int i = 0;
        char* name = new char[128];
        for(std::string depName : dependenciesNames) {
            Json::Value dependency = dependencies[i++];
            for(Json::ValueIterator element = dependency.begin(); element != dependency.end(); element++) {
                sprintf(name, "%s/%s", depName.c_str(), element.name().c_str());
                this->creatures[name] = new Creature(dependency[element.name()], this->moves, this->types);
            }
        }
        delete[] name;
    }
    void Model::buildItemMap(std::set<std::string> dependenciesNames, Json::Value* dependencies) {
        int i = 0;
        char* name = new char[128];
        for(std::string depName : dependenciesNames) {
            Json::Value dependency = dependencies[i++];
            for(Json::ValueIterator element = dependency.begin(); element != dependency.end(); element++) {
                sprintf(name, "%s/%s", depName.c_str(), element.name().c_str());
                this->items[name] = new Item(dependency[element.name()], this->effects, this->triggers);
            }
        }
        delete[] name;
    }
    void Model::buildMoveMap(std::set<std::string> dependenciesNames, Json::Value* dependencies) {
        int i = 0;
        char* name = new char[128];
        for(std::string depName : dependenciesNames) {
            Json::Value dependency = dependencies[i++];
            for(Json::ValueIterator element = dependency.begin(); element != dependency.end(); element++) {
                sprintf(name, "%s/%s", depName.c_str(), element.name().c_str());
                this->moves[name] = new Move(dependency[element.name()], this->types, this->effects);
            }
        }
        delete[] name;
    }
    void Model::buildTypeMap(std::set<std::string> dependenciesNames, Json::Value* dependencies) {
        int i = 0;
        char* name = new char[128];
        for(std::string depName : dependenciesNames) {
            Json::Value dependency = dependencies[i++];
            for(Json::ValueIterator element = dependency.begin(); element != dependency.end(); element++) {
                sprintf(name, "%s/%s", depName.c_str(), element.name().c_str());
                this->types[name] = new Type(dependency[element.name()]);
            }
        }
        delete[] name;
    }
    void Model::buildEffectMap(std::set<std::string> dependenciesNames, Json::Value* dependencies) {
        int i = 0;
        char* name = new char[128];
        for(std::string depName : dependenciesNames) {
            Json::Value dependency = dependencies[i++];
            for(Json::ValueIterator element = dependency.begin(); element != dependency.end(); element++) {
                sprintf(name, "%s/%s", depName.c_str(), element.name().c_str());
                this->effects[name] = new Effect(dependency[element.name()]);
            }
        }
        delete[] name;
    }
    void Model::buildTriggerMap(std::set<std::string> dependenciesNames, Json::Value* dependencies) {
        int i = 0;
        char* name = new char[128];
        for(std::string depName : dependenciesNames) {
            Json::Value dependency = dependencies[i++];
            for(Json::ValueIterator element = dependency.begin(); element != dependency.end(); element++) {
                sprintf(name, "%s/%s", depName.c_str(), element.name().c_str());
                this->triggers[name] = new Trigger(dependency[element.name()]);
            }
        }
        delete[] name;
    }
}
