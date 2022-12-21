#include "Aura.hpp"

namespace model {
    Aura::Aura (Json::Value val){
        this->targetSelf = val["targetSelf"].asBool();
        this->targetStat = val["stat"].asInt();
        this->value = val["value"].asFloat();
    }

    std::string Aura::GetName() {
        return this->name;
    }

    float Aura::GetValue() {
        return this->value;
    }

    bool Aura::TargetsSelf() {
        return this->targetSelf;
    }

    int Aura::GetTargetStat() {
        return this->targetStat;
    }
}
