#include "Move.hpp"

namespace model {
    Move::Move (Json::Value val, std::unordered_map<std::string, Type*> typeDependencies, std::unordered_map<std::string, Effect*> effectDependencies) {
        this->power = val["power"].asInt();
        this->type = typeDependencies[val["type"].asString()];
        this->powerPoints = val["max"].asInt();
        this->priority = val["priority"].asBool();
        this->effect = effectDependencies[val["effect"].asString()];
    }

    std::string Move::GetName() {
        return this->name;
    }

    int Move::GetPower() {
        return this->power;
    }

    Type* Move::GetType() {
        return this->type;
    }

    int Move::GetPP() {
        return this->powerPoints;
    }

    bool Move::HasPriority() {
        return this->priority;
    }

    Effect* Move::GetEffect() {
        return this->effect;
    }
}
