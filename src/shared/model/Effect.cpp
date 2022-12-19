#include "Effect.hpp"

namespace model {
    Effect::Effect (Json::Value val){
        this->targetSelf = val["targetSelf"].asBool();
        this->targetStat = val["stat"].asInt();
        this->value = val["value"].asFloat();
    }

    std::string Effect::GetName() {
        return this->name;
    }

    float Effect::GetValue() {
        return this->value;
    }

    bool Effect::TargetsSelf() {
        return this->targetSelf;
    }

    int Effect::GetTargetStat() {
        return this->targetStat;
    }
}
