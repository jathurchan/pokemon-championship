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

    void Creature::UpdateState(CreatureState newState)
    {
        if(creatureState != CreatureState::ko)
        {
            creatureState = newState;
            if(newState == CreatureState::sub)
            {
                Reset();
            }
        }
        else
        {
            std::cout << "This creature is ko. CreatureState connt be changed" << std::endl;
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
