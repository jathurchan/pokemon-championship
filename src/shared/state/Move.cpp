#include "Move.hpp"

namespace state {
    
    Move::Move() = default;
    
    Move::Move(model::Move modelMove)
    {
        this->name = modelMove.GetName();
        this->basePP = modelMove.GetPP();
        currentPP = basePP;
        this->priority = modelMove.HasPriority();
        this->power = modelMove.GetPower();
        this->aura = Aura(*modelMove.GetAura());
        this->type = modelMove.GetType();
    }

    Move::~Move() = default;

    std::string Move::GetName()
    {
        return name;
    }

    int Move::GetBasePP()
    {
        return basePP;
    }

    int Move::GetCurrPP()
    {
        return currentPP;
    }

    int Move::GetPower()
    {
        return power;
    }

    StatName Move::GetStatName()
    {
        return aura.GetStatName();
    }

    float Move::GetMultiplier()
    {
        return aura.GetMultiplier();
    }
    
    bool Move::GetSelfTarget()
    {
        return aura.GetSelfTarget();
    }

    bool Move::HasPriority()
    {
        return priority;
    }

    void Move::DecrementPP()
    {
        --currentPP;
    }
}
