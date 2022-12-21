#include "Item.hpp"

namespace model {

    Item::Item() = default;
    
    Item::Item (Json::Value val, std::unordered_map<std::string, Aura*> auraDependencies, std::unordered_map<std::string, Trigger*> triggerDependencies)
    {
        this->trigger = triggerDependencies[val["trigger"].asString()];
        this->aura = auraDependencies[val["aura"].asString()];
    }

    std::string Item::GetName() {
        return name;
    }

    Trigger* Item::GetTrigger() {
        return trigger;
    }

    Aura* Item::GetAura() {
        return aura;
    }
}
