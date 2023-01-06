#include "Creature.hpp"

namespace state {

    Creature::Creature()
    {

    }
    
    Creature::Creature(model::Creature *modelCreature)
    {
        this->name = modelCreature->GetName();
        this->type = modelCreature->GetType();
        this->creatureState = CreatureState::sub;        
        InitStats(modelCreature->GetStats());
        InitMoves(modelCreature->GetMoves());
    }

    Creature::~Creature()
    {
        
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
        this->moves[0] = Move(*moves[0]);
        this->moves[1] = Move(*moves[1]);
        this->moves[2] = Move(*moves[2]);
        this->moves[3] = Move(*moves[3]);

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
        creatureState = newState;
        if(newState == CreatureState::sub)
        {
            Reset();
        }
    }

    void Creature::GiveItem(Item* item)
    {
        this->item = item;
    }

    void Creature::UseItem()
    {
        Stat* affected = &stats[item->GetStatName()];
        affected->Update(affected->GetCurrent() + (affected->GetBase() * item->GetMultiplier()));
    }

    void Creature::RemoveItem()
    {
        delete(item);
    }

    model::Type* Creature::GetType()
    {
        return type;
    }

}
