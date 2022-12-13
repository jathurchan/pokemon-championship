#include "Trigger.hpp"

namespace model {
    Trigger::Trigger (Json::Value val){
        this->stat = val["stat"].asInt();
        this->threshold = val["threshold"].asInt();
    }
}
