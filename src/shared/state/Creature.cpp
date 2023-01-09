#include "Creature.hpp"
#include <iostream>

namespace state {
    
    Creature::Creature(model::Creature *modelCreature)
    {
        this->name = modelCreature->GetName();
        this->type = modelCreature->GetType();
        this->creatureState = CreatureState::sub;  
        this->item = nullptr;      
        InitStats(modelCreature->GetStats());
        InitMoves(modelCreature->GetMoves());
    }

    Creature::~Creature()
    {
        RemoveItem();
    }    

    void Creature::InitStats(std::array<int, 4> stats)
    {
        this->stats[0] = Stat(StatName::hp,  stats[0]);
        this->stats[1] = Stat(StatName::atk, stats[1]);
        this->stats[2] = Stat(StatName::def, stats[2]);
        this->stats[3] = Stat(StatName::spd, stats[3]);
    }

    void Creature::InitMoves(std::array<model::Move*, 4> moves)
    {
        this->moves[0] = Move(moves[0]);
        this->moves[1] = Move(moves[1]);
        this->moves[2] = Move(moves[2]);
        this->moves[3] = Move(moves[3]);

    }

    std::string Creature::GetName()
    {
        return name;
    }

    int Creature::GetStatBase(StatName statName)
    {
        return stats[statName].GetBase();
    }

    int Creature::GetStatCurrent(StatName statName)
    {
        return stats[statName].GetCurrent();
    }

    Move* Creature::GetMove(int moveIndex)
    {
        return &moves[moveIndex];
    }

    Item* Creature::GetItem()
    {
        return item;
    }

    CreatureState Creature::GetState()
    {
        return creatureState;
    }

    void Creature::Reset()
    {
        for(size_t i = 1; i < stats.size(); i++)
        {
            stats[i].Update(stats[i].GetBase());
        }
    }

    void Creature::ReceiveDamage(int rawDamage, model::Type *type)
    {
        int totalDamage = rawDamage * type->GetFactor(this->type->GetName()) - this->stats[state::def].GetCurrent() / 5;
        if (totalDamage < 1)
            totalDamage = 1;
        this->stats[state::hp].Update(this->stats[state::hp].GetCurrent() - totalDamage);
        std::cout << name << " takes " << totalDamage << " damage";
        if (this->stats[state::hp].GetCurrent() <= 0)
        {
            creatureState = CreatureState::ko;
            std::cout << " and dies";
        }
        std::cout << ". " << name << " now has " << stats[state::hp].GetCurrent() << " hp.\n";
    }

    void Creature::ApplyAura(model::Aura *aura)
    {
        int targetStat = aura->GetTargetStat();
        int bonus = this->stats[targetStat].GetBase() * aura->GetValue();
        this->stats[targetStat].Update(this->stats[targetStat].GetCurrent() + bonus);
        std::cout << this->GetName() << " receives " << aura->GetName() << " modifying its stat " << aura->GetTargetStat() <<  " by " << bonus << "\n";
    }

    void Creature::UpdateState(CreatureState newState)
    {
        if(creatureState != CreatureState::ko)
        {
            if(newState == CreatureState::sub)
            {
                Reset();
            }

            if(newState == CreatureState::active)
            {
                if(item!=nullptr && item->GetThreshold() == 100)
                {
                    UseItem();                   
                }
            }
            creatureState = newState;
        }
        else
        {
            std::cout << "This creature is ko. CreatureState cannot be changed" << std::endl;
        }
    }

    void Creature::GiveItem(model::Item* modelItem)
    {
        if(this->item == nullptr)
        {
            this->item = new state::Item(modelItem);
        }
        else
        {
            std::cout <<"Action not allowed (An item is alreay equipped)" << std::endl;;    
        }
    }

    void Creature::UseItem()
    {
        Stat* affected = &stats[item->GetStatName()];
        affected->Update(affected->GetCurrent() + (affected->GetBase() * item->GetMultiplier()));
    }

    void Creature::RemoveItem()
    {
        if(item != nullptr)
        {
            delete item;
            item = nullptr;
        }
        else
        {
            std::cout << "Action not allowed (No Item equipped)" << std::endl;  
        }
    }

    model::Type* Creature::GetType()
    {
        return type;
    }

}
