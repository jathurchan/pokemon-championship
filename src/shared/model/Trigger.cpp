#include "Trigger.hpp"

namespace model {
    Trigger::Trigger (Json::Value val){
        this->stat = val["stat"].asInt();
        this->threshold = val["threshold"].asInt();
    }

    std::string Trigger::GetName() {
        return this->name;
    }

    int Trigger::GetStat() {
        return this->stat;
    }

    int Trigger::GetThreshold() {
        return this->threshold;
    }
}
