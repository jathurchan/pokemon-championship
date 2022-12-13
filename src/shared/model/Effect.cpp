#include "Effect.hpp"

namespace model {
    Effect::Effect (Json::Value val){
        this->targetSelf = val["targetSelf"].asBool();
        this->targetStat = val["stat"].asInt();
        this->operation = val["operation"].asInt();
        this->value = val["value"].asFloat();
    }
}
