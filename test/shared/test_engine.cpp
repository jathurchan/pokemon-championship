#include <boost/test/unit_test.hpp>
#include <engine.hpp>
#include <state.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE( TestEngine )

    BOOST_AUTO_TEST_CASE( test_game )
    {
        model::Model model("defaultCreatures", "defaultItems");

        state::Trainer* trainerA = new state::Trainer("Ash");
        state::Trainer* trainerB = new state::Trainer("Bash");

        std::array<std::string, 6> pokemon = {"FireSheep", "DisGrass", "Aquis", "FireSheep", "DisGrass", "Aquis"};
        std::array<std::string, 6> fakemon = {"Aquis", "FireSheep", "FireSheep", "DisGrass", "DisGrass", "Aquis"};

        trainerA->GetParty()->LoadFromModel(&model, pokemon);
        trainerB->GetParty()->LoadFromModel(&model, fakemon);

        engine::Command commandA;
        engine::Command commandB;

        state::Battle* battle = new state::Battle(trainerA, trainerB, 100);
        engine::Engine engine;

        commandA = engine::BanCommand(0, 2);
        commandA = engine::BanCommand(0, 4);
        engine.Execute(commandA, commandB, battle);

        commandA = engine::BuildCommand(0, {std::pair<int, model::Item*>(2, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(0, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(5, model.GetItem(""))});
        commandA = engine::BuildCommand(0, {std::pair<int, model::Item*>(3, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(0, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(1, model.GetItem(""))});
        engine.Execute(commandA, commandB, battle);

        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetName(), "Aquis");
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetName(), "DisGrass");

        delete trainerA;
        delete trainerB;
        delete battle;
    }
BOOST_AUTO_TEST_SUITE_END()