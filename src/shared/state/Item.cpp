#include "Item.hpp"

namespace state {

    Item::Item (model::Item* modelItem)
    {
        this->name = modelItem->GetName();
        this->threshold = modelItem->GetTrigger()->GetThreshold();
        this->permanent = threshold == 100;
        this->triggerStat = (StatName)modelItem->GetTrigger()->GetStat();
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
        return triggerStat;
    }

    int Item::GetThreshold ()
    {
        return threshold;
    }

    model::Aura* Item::GetAura ()
    {
        return aura;
    }

    bool Item::IsPermanent ()
    {
        return permanent;
    }
    
}

