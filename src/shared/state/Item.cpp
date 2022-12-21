#include "Item.hpp"

namespace state {

    Item::Item () = default;

    Item::Item (model::Item modelItem)
    {
        this->name = modelItem.GetName();
        this->threshold = modelItem.GetTrigger()->GetThreshold();
        this->permanent = (threshold < 100) ? false : true;
        this->aura = Aura(*modelItem.GetAura());
    }

    Item::~Item () = default;

    std::string Item::GetName ()
    {
        return name;
    }

    StatName Item::GetStatName ()
    {
        return aura.GetStatName();
    }

    int Item::GetThreshold ()
    {
        return threshold;
    }

    float Item::GetMultiplier ()
    {
        return aura.GetMultiplier();
    }

    bool Item::IsPermanent ()
    {
        return permanent;
    }
    
}

