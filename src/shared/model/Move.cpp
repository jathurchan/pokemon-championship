#include "Move.hpp"

namespace model {
    Move::Move (char* name, Json::Value val, std::unordered_map<std::string, Type*> typeDependencies, std::unordered_map<std::string, Aura*> auraDependencies) {
        this->name = name;
        this->power = val["power"].asInt();
        this->type = typeDependencies[val["type"].asString()];
        this->powerPoints = val["max"].asInt();
        this->priority = val["priority"].asBool();
        this->aura = auraDependencies[val["aura"].asString()];
    }

    std::string Move::GetName() {
        return name;
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

    Aura* Move::GetAura() {
        return this->aura;
    }
}
