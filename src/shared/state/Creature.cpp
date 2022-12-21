#include "Creature.hpp"

namespace state {

    Creature::Creature() = default;
    
    Creature::Creature(model::Creature modelCreature)
    {
        this->name = modelCreature.GetName();
        
        InitStats(modelCreature.GetStats());
        InitMoves(modelCreature.GetMoves());
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

    CreatureState Creature::GetState()
    {
        return creatureState;
    }

    void Creature::UpdateState(CreatureState newState)
    {
        creatureState = newState;
    }
}
