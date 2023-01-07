#include "Battle.hpp"

namespace state 
{

    Battle::Battle(Trainer *trainerA, Trainer *trainerB, int actionTimeout)
    {
        this->trainers[0] = trainerA;
        this->trainers[1] = trainerB;
        this->actionTimeout = actionTimeout;
    }

    Battle::~Battle()
    {

    }

    BattleState Battle::GetState()
    {
        return state;
    }

    int Battle::GetTurn()
    {
        return turn;
    }

    Trainer* Battle::GetTrainerA()
    {
        return trainers[0];
    }

    Trainer* Battle::GetTrainerB()
    {
        return trainers[1];
    }

    void Battle::PushQueue(PendingMove pMove)
    {
        this->actionQueue.push(pMove);
    }

    PendingMove Battle::PopQueue()
    {
        PendingMove out;
        if (actionQueue.size())
        {
            out = actionQueue.top();
            this->actionQueue.pop();
        }
        else
        {
            out.procSpeed = 0;
        }
        return out;
    }
}
