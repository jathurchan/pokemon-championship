#include "Creature.hpp"
#include <iostream>

#define NMOVES 4

namespace model {
    Creature::Creature (char* name, Json::Value val, std::unordered_map<std::string, Move*> moveDependencies, std::unordered_map<std::string, Type*> typeDependencies)
    {
        this->name = name;

        for (int i = 0; i < 4; i++)
            this->stats[i] = val["stats"][i].asInt();

        for (int i = 0; i < NMOVES; i++)
            this->moves[i] = moveDependencies[val["moves"][i].asString()];
        
        this->type = typeDependencies[val["type"].asString()];
    }

    std::string Creature::GetName() {
        return this->name;
    }

    std::array<int, 4> Creature::GetStats() {
        return this->stats;
    }

    std::array<Move*, 4> Creature::GetMoves() {
        return this->moves;
    }

    Type* Creature::GetType() {
        return this->type;
    }
}
