#include "Move.hpp"

namespace model {
    Move::Move (Json::Value val, std::unordered_map<std::string, Type*> typeDependencies, std::unordered_map<std::string, Effect*> effectDependencies) {
        this->power = val["power"].asInt();
        this->type = typeDependencies[val["type"].asString()];
        this->charges = val["max"].asInt();
        this->priority = val["priority"].asBool();
        this->effect = effectDependencies[val["effect"].asString()];
    }
}
