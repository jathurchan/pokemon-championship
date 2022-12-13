#include "Item.hpp"

namespace model {
        Item::Item (Json::Value val, std::unordered_map<std::string, Effect*> effectDependencies, std::unordered_map<std::string, Trigger*> triggerDependencies){
        this->trigger = triggerDependencies[val["trigger"].asString()];
        this->effect = effectDependencies[val["effect"].asString()];
    }
}