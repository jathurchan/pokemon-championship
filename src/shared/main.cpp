#include <model.hpp>
#include <state.hpp>
#include <iostream>

int main(int argc,char* argv[])
{
    std::cout << "It Works !" << std::endl;

    model::Model model("defaultCreatures", "defaultItems");

    std::cout << "Parsed successfully!" << std::endl;
    
    model.DispAll();

    state::Trainer* trainerA = new state::Trainer("Rémi");
    state::Trainer* trainerB = new state::Trainer("Alex");

    std::cout << trainerA->GetName() << std::endl;
    std::cout << trainerB->GetName() << std::endl;

    state::Battle battle(trainerA, trainerB, 100);

    std::array<std::string, 6> pokemon = {"defaultCreatures/FireSheep", "defaultCreatures/DisGrass", "defaultCreatures/Aquis", "defaultCreatures/FireSheep", "defaultCreatures/DisGrass", "defaultCreatures/Aquis"};
    std::array<std::string, 6> fakemon = {"defaultCreatures/Aquis", "defaultCreatures/FireSheep", "defaultCreatures/FireSheep", "defaultCreatures/DisGrass", "defaultCreatures/DisGrass", "defaultCreatures/Aquis"};

    trainerA->GetParty()->LoadFromModel(&model, pokemon);
    trainerB->GetParty()->LoadFromModel(&model, fakemon);

    trainerA->GetParty()->SetParticipatingTeam({0,1,2});
    trainerB->GetParty()->SetParticipatingTeam({1,2,3});

    std::cout << trainerA->GetName() << std::endl;
    std::cout << trainerA->GetParty()->GetActiveCreature()->GetName() << std::endl;
    std::cout << trainerB->GetName() << std::endl;
    std::cout << trainerB->GetParty()->GetActiveCreature()->GetName() << std::endl;    

    delete(trainerA);
    delete(trainerB);

    return 0;
}