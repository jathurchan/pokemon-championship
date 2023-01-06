#include "Item.hpp"

namespace model {

    Item::Item() {
        this->name = "None";
        this->trigger = new Trigger();
        this->aura = new Aura();
    }
    
    Item::Item (char* name, Json::Value val, std::unordered_map<std::string, Aura*> auraDependencies, std::unordered_map<std::string, Trigger*> triggerDependencies) {
        this->name = name;
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
