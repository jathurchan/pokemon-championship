#include "Move.hpp"

namespace state {
    
    Move::Move()
    {
        
    }
    
    Move::Move(model::Move* modelMove)
    {
        this->name = modelMove->GetName();
        this->basePP = modelMove->GetPP();
        currentPP = basePP;
        this->priority = modelMove->HasPriority();
        this->power = modelMove->GetPower();
        this->aura = modelMove->GetAura();
        this->type = modelMove->GetType();
    }

    Move::~Move()
    {
        
    }

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

    bool Move::HasPriority()
    {
        return priority;
    }

    void Move::DecrementPP()
    {
        --currentPP;
    }

    void Move::IncrementPP()
    {
        ++currentPP;
    }

    model::Type* Move::GetType ()
    {
        return type;
    }

    model::Aura* Move::GetAura()
    {
        return aura;
    }
}
