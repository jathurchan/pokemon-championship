#include "Creature.hpp"

#define NMOVES 4

namespace model {
    Creature::Creature (Json::Value val, std::unordered_map<std::string, Move*> moveDependencies, std::unordered_map<std::string, Type*> typeDependencies){
        for (int i = 0; i < 4; i++)
            this->stats[i] = val["stats"][i].asInt();

        for (int i = 0; i < NMOVES; i++)
            this->moves[i] = moveDependencies[val["moves"][i].asString()];
        
        this->type = typeDependencies[val["type"].asString()];
    }

    std::string Creature::GetName() {
        return this->name;
    }

    int* Creature::GetStats() {
        return this->stats;
    }

    Move** Creature::GetMoves() {
        return this->moves;
    }

    Type* Creature::GetType() {
        return this->type;
    }
}