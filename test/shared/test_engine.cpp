#include <boost/test/unit_test.hpp>
#include <engine.hpp>
#include <state.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE( TestEngine )

    model::Model model("defaultCreatures", "defaultItems");

    state::Trainer* trainerA = new state::Trainer("Shell");
    state::Trainer* trainerB = new state::Trainer("Bash");

    std::array<std::string, 6> pokemon = {"FireSheep", "DisGrass", "Aquis", "FireSheep", "DisGrass", "Aquis"};
    std::array<std::string, 6> fakemon = {"Aquis", "FireSheep", "FireSheep", "DisGrass", "DisGrass", "Aquis"};

    engine::Engine engine;
    
    BOOST_AUTO_TEST_CASE( test_game )
    {
        BOOST_CHECK_EQUAL(trainerA->GetName(), "Shell");
        BOOST_CHECK_EQUAL(trainerB->GetName(), "Bash");

        trainerA->GetParty()->LoadFromModel(&model, pokemon);
        trainerB->GetParty()->LoadFromModel(&model, fakemon);
    }

    state::Battle* battle = new state::Battle(trainerA, trainerB, 100);

    BOOST_AUTO_TEST_CASE( test_game )
    {
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetName(), "Shell");
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetName(), "Bash");
    }
    
    engine::Command* commandA = new engine::BanCommand(0, 2);
    engine::Command* commandB = new engine::BanCommand(1, 4);

    BOOST_AUTO_TEST_CASE( test_BanCommand )
    {
        engine.Execute(commandA, commandB, battle);
        delete commandA;
        delete commandB;
    }

    BOOST_AUTO_TEST_CASE( test_BuildCommand )
    {
        commandA = new engine::BuildCommand(0, {std::pair<int, model::Item*>(2, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(0, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(5, model.GetItem(""))});
        commandB = new engine::BuildCommand(1, {std::pair<int, model::Item*>(3, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(0, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(1, model.GetItem(""))});
        engine.Execute(commandA, commandB, battle);
        delete commandA;
        delete commandB;
        
    }

    BOOST_AUTO_TEST_CASE( test_MoveCommand )
    {
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetName(), "Aquis");
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetName(), "DisGrass");

        commandA = new engine::MoveCommand(0, 0);
        commandB = new engine::MoveCommand(1, 0);
        engine.Execute(commandA, commandB, battle);
        delete commandA;
        delete commandB;

        delete trainerA;
        delete trainerB;
        delete battle;
    }
BOOST_AUTO_TEST_SUITE_END()
