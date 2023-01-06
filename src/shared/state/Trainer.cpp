#include "Trainer.hpp"


namespace state {
    

    Trainer::Trainer()
    {

    }

    Trainer::Trainer(std::string name)
    {
        this->name = name;
    }

    Trainer::~Trainer()
    {
        
    }

    void Trainer::SetState(TrainerState newState)
    {
        this->trainerState = newState;
    }

    std::string Trainer::GetName()
    {
        return name;
    }

    Party* Trainer::GetParty()
    {
        return &party;
    }

    TrainerState Trainer::GetState()
    {
        return trainerState;
    }

    Creature* Trainer::GetActiveCreature()
    {
        return &party.GetActiveCreature();
    }
}