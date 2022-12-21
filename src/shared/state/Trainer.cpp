#include "Trainer.hpp"

state::Trainer::Trainer(std::string name)
{
    this->name = name;
    //this->party = new Party();
}

state::Trainer::~Trainer()
{
    delete(party); 
}

void state::Trainer::SetState(TrainerState newState)
{
    this->trainerState = newState;
}

std::string state::Trainer::GetName()
{
    return name;
}

state::Party state::Trainer::GetParty()
{
    return *party;
}
