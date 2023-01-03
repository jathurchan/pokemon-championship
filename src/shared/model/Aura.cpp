#include "Aura.hpp"

namespace model {
    Aura::Aura (char* name, Json::Value val) {
        this->name = name;
        this->targetSelf = val["targetSelf"].asBool();
        this->targetStat = val["stat"].asInt();
        this->value = val["value"].asFloat();
    }

    Aura::Aura () {
        this->name = "nullAura";
        this->targetSelf = false;
        this->targetStat = 0;
        this->value = 1.f;
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
