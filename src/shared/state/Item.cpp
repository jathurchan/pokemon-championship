#include "Item.hpp"

namespace state {

    Item::Item ()
    {

    }

    Item::Item (model::Item* modelItem)
    {
        this->name = modelItem->GetName();
        this->threshold = modelItem->GetTrigger()->GetThreshold();
        this->permanent = (threshold < 100) ? false : true;
        this->aura = modelItem->GetAura();
    }

    Item::~Item ()
    {
        
    }

    std::string Item::GetName ()
    {
        return name;
    }

    StatName Item::GetStatName ()
    {
        return (state::StatName) aura->GetTargetStat();
    }

    int Item::GetThreshold ()
    {
        return threshold;
    }

    float Item::GetMultiplier ()
    {
        return aura->GetValue();
    }

    bool Item::IsPermanent ()
    {
        return permanent;
    }
    
}

