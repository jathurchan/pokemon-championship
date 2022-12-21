#include "Aura.hpp"

namespace state {

    Aura::Aura() = default;

    Aura::Aura(model::Aura modelAura)
    {
        this->statName = (StatName)modelAura.GetTargetStat();
        this->multiplier = modelAura.GetValue();
        this->selfTarget = modelAura.TargetsSelf();
    }

    Aura::~Aura()
    {

    }

    StatName Aura::GetStatName()
    {
        return statName;
    }

    float Aura::GetMultiplier()
    {
        return multiplier;
    }
    
    bool Aura::GetSelfTarget()
    {
        return selfTarget;
    }
}