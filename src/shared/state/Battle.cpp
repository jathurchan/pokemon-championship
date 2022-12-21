#include "Battle.hpp"

// Constructors

state::Battle::Battle(std::string trainerA, std::string trainerB, int actionTimeout)
{
  this->trainerA = new Trainer(trainerA);
  this->trainerB = new Trainer(trainerB);
  this->actionTimeout = actionTimeout;
  this->numberOfBans = numberOfBans;
  this->participatingSize = participatingSize;
  this->numberOfItems = numberOfItems;

  Init();
}

// Destructors

state::Battle::~Battle()
{
  delete(trainerA);
  delete(trainerB);
}

// Init

void state::Battle::Init()
{
  turn = 0;
  this->state = BattleState::waitState;
}

// Methods

void state::Battle::Update()
{

}

// Getters

state::Trainer &state::Battle::GetTrainerA()
{
  return *trainerA;
}

state::Trainer &state::Battle::GetTrainerB()
{
  return *trainerB;
}

int state::Battle::GetNumberOfBans()
{
  return numberOfBans;
}

int state::Battle::GetParticipatingSize()
{
  return participatingSize;
}

int state::Battle::GetNumberOfItems()
{
  return numberOfItems;
}

int state::Battle::GetTurn()
{
  return turn;
}

