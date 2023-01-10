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

    void Creature::SetStatCurrent(int value, StatName statName)
    {
        stats[statName].Update(value);
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
        bool itemTrigger = false;
        int th = 100;
        if (item)
        {
            itemTrigger = item->GetStatName() == hp;
            th = this->item->GetThreshold();
        }
        int totalDamage = rawDamage * type->GetFactor(this->type->GetName()) - this->stats[state::def].GetCurrent() / 5;
        if (totalDamage < 1)
            totalDamage = 1;
        
        if (this->stats[hp].GetCurrent() * 100 <= this->stats[hp].GetBase() * th) //(currHP/maxHP <= Threshold/100)
            itemTrigger = false;
        this->stats[hp].Update(this->stats[hp].GetCurrent() - totalDamage);
        if (this->stats[hp].GetCurrent() * 100 > this->stats[hp].GetBase() * th) //(currHP/maxHP > Threshold/100)
            itemTrigger = false;

        std::cout << name << " takes " << totalDamage << " damage";
        if (this->stats[hp].GetCurrent() <= 0)
        {
            creatureState = CreatureState::ko;
            std::cout << " and dies.\n";
            return;
        } else if (itemTrigger)
        {
            std::cout << " and triggers " << item->GetName();
            UseItem();
            RemoveItem();
        }
        std::cout << ". " << name << " now has " << stats[state::hp].GetCurrent() << " hp.\n";
    }

    void Creature::ApplyAura(model::Aura *aura)
    {
        StatName stat = (StatName)aura->GetTargetStat(); // targetStat
        bool itemTrigger = false;
        int th = 100;
        if (item)
        {
            itemTrigger = item->GetStatName() == (StatName)stat;
            th = this->item->GetThreshold();
        }

        int bonus = this->stats[stat].GetBase() * aura->GetValue();
        if (!bonus) return;

        if ((this->stats[stat].GetCurrent() * 100 <= this->stats[stat].GetBase() * th) ^ (th > 100)) // currStat/maxStat <= treshold/100 XOR threshold > 100
            itemTrigger = false;
        this->stats[stat].Update(this->stats[stat].GetCurrent() + bonus);
        if ((this->stats[stat].GetCurrent() * 100 > this->stats[stat].GetBase() * th) ^ (th > 100)) // currStat/maxStat > treshold/100 XOR threshold > 100
            itemTrigger = false;

        std::cout << this->GetName() << " receives " << aura->GetName() << " modifying its stat " << aura->GetTargetStat() <<  " by " << bonus << " for a total of " << this->stats[stat].GetCurrent();
        if (itemTrigger)
        {
            std::cout << " and triggers " << item->GetName() << ".\n";
            UseItem();
            RemoveItem();
            return;
        }
        std::cout << ".\n";
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
    }

    void Creature::GiveItem(model::Item* modelItem)
    {
        if(this->item == nullptr)
        {
            this->item = new state::Item(modelItem);
        }
        else
        {
            std::cout <<"Action not allowed (An item is alreay equipped)\n";    
        }
    }

    void Creature::UseItem()
    {
        ApplyAura(item->GetAura());
    }

    void Creature::RemoveItem()
    {
        if(item)
        {
            delete item;
            item = nullptr;
        }
    }

    model::Type* Creature::GetType()
    {
        return type;
    }

}
