#include <model.hpp>
#include <state.hpp>
#include <iostream>

int main(int argc,char* argv[])
{
    std::cout << "It Works !" << std::endl;

    model::Model model("testCreatures", "testItems");

    std::cout << "Parsed successfully!" << std::endl;

    state::Trainer* trainerA = new state::Trainer("Rémi");
    state::Trainer* trainerB = new state::Trainer("Alex");

    std::cout << trainerA->GetName() << std::endl;
    std::cout << trainerB->GetName() << std::endl;

    state::Battle battle(trainerA, trainerB, 100);

    std::array<model::Creature*, 6> pokemon = {model.GetCreature("FireSheep"), model.GetCreature("DisGrass"), model.GetCreature("Aquis"), model.GetCreature("FireSheep"), model.GetCreature("DisGrass"), model.GetCreature("Aquis")};
    std::array<model::Creature*, 6> fakemon = {model.GetCreature("Aquis"), model.GetCreature("FireSheep"),model.GetCreature("FireSheep"), model.GetCreature("DisGrass"), model.GetCreature("DisGrass"), model.GetCreature("Aquis")};

    trainerA->GetParty()->LoadFromModel(pokemon);
    trainerB->GetParty()->LoadFromModel(fakemon);

    std::array<std::pair<int, model::Item*>, 3> order({std::pair<int, model::Item*>(0, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(1, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(2, model.GetItem(""))});


    trainerA->GetParty()->SetParticipatingTeam(order);
    /*trainerA->GetParty()->SetParticipatingTeam({0,1,2});
    trainerB->GetParty()->SetParticipatingTeam({1,2,3});

    std::cout << trainerA->GetName() << std::endl;
    std::cout << trainerA->GetParty()->GetActiveCreature()->GetName() << std::endl;
    std::cout << trainerB->GetName() << std::endl;
    std::cout << trainerB->GetParty()->GetActiveCreature()->GetName() << std::endl;*/

    trainerA->GetActiveCreature()->RemoveItem();

    state::PendingMove pMove1 = state::PendingMove();
    state::PendingMove pMove2 = state::PendingMove();
    state::PendingMove pMove3 = state::PendingMove();
    state::PendingMove pMove4 = state::PendingMove();
    pMove1.procSpeed = 200;
    pMove2.procSpeed = 220;
    pMove3.procSpeed = 180;
    pMove4.procSpeed = 210;
    battle.PushQueue(pMove1);
    battle.PushQueue(pMove2);
    battle.PushQueue(pMove3);
    battle.PushQueue(pMove4);
    printf("%d\n", battle.PopQueue().procSpeed);
    printf("%d\n", battle.PopQueue().procSpeed);
    printf("%d\n", battle.PopQueue().procSpeed);
    printf("%d\n", battle.PopQueue().procSpeed);
    printf("%d\n", battle.PopQueue().procSpeed);

    delete(trainerA);
    delete(trainerB);


    return 0;
}