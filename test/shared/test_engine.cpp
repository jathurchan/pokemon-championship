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
        trainerA->GetParty()->LoadFromModel(&model, pokemon);
        trainerB->GetParty()->LoadFromModel(&model, fakemon);
    }

    state::Battle* battle = new state::Battle(trainerA, trainerB, 100);
    
    engine::Command* commandA;
    engine::Command* commandB;

    BOOST_AUTO_TEST_CASE( test_BanCommands_fail )
    {
        commandA = new engine::BanCommand(0, 30);
        commandB = new engine::BanCommand(1, 4);
        engine.Execute(commandA, commandB, battle);
        delete commandA;
        delete commandB;
    }
    BOOST_AUTO_TEST_CASE( test_BanCommands )
    {
        commandA = new engine::BanCommand(0, 2);
        commandB = new engine::BanCommand(1, 4);
        engine.Execute(commandA, commandB, battle);
        delete commandA;
        delete commandB;
    }

    BOOST_AUTO_TEST_CASE( test_BuildCommand1_fail )
    {
        commandA = new engine::BuildCommand(0, {std::pair<int, model::Item*>(4, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(0, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(5, model.GetItem(""))});
        commandB = new engine::BuildCommand(1, {std::pair<int, model::Item*>(4, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(0, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(1, model.GetItem(""))});
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), false);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature(), nullptr);
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature(), nullptr);
    }

    BOOST_AUTO_TEST_CASE( test_BuildCommand2_fail )
    {
        commandA = new engine::BuildCommand(0, {std::pair<int, model::Item*>(2, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(0, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(5, model.GetItem(""))});
        commandB = new engine::BuildCommand(1, {std::pair<int, model::Item*>(2, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(0, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(1, model.GetItem(""))});
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), false);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature(), nullptr);
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature(), nullptr);
    }

    BOOST_AUTO_TEST_CASE( test_BuildCommand1_2_fail )
    {
        commandA = new engine::BuildCommand(0, {std::pair<int, model::Item*>(4, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(0, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(5, model.GetItem(""))});
        commandB = new engine::BuildCommand(1, {std::pair<int, model::Item*>(2, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(0, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(1, model.GetItem(""))});
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), false);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature(), nullptr);
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature(), nullptr);
    }

    BOOST_AUTO_TEST_CASE( test_BuildCommand_success )
    {
        commandA = new engine::BuildCommand(0, {std::pair<int, model::Item*>(2, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(0, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(5, model.GetItem(""))});
        commandB = new engine::BuildCommand(1, {std::pair<int, model::Item*>(4, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(0, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(1, model.GetItem(""))});
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), true);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetName(), "Aquis");
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetName(), "DisGrass");
    }

    BOOST_AUTO_TEST_CASE( test_MoveCommand_success )
    {
        commandA = new engine::MoveCommand(0, 0);
        commandB = new engine::MoveCommand(1, 0);
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), true);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetStatCurrent(state::hp), 28);
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetStatCurrent(state::hp), 119);

        commandA = new engine::MoveCommand(0, 3);
        commandB = new engine::MoveCommand(1, 0);
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), true);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetStatCurrent(state::hp), 0);
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetStatCurrent(state::hp), 82);
    }

    BOOST_AUTO_TEST_CASE( test_MoveCommand_fail_ko )
    {
        commandA = new engine::MoveCommand(0, 0);
        commandB = new engine::MoveCommand(1, 0);
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), false);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetStatCurrent(state::hp), 0);
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetStatCurrent(state::hp), 82);
    }

    BOOST_AUTO_TEST_CASE( test_ChangeCommand_success )
    {
        commandA = new engine::ChangeCommand(0, 1);
        commandB = new engine::MoveCommand(1, 0);
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), true);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetStatCurrent(state::hp), 69);
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetStatCurrent(state::hp), 82);
    }

    BOOST_AUTO_TEST_CASE( test_ChangeCommand_fail_already_active )
    {
        commandA = new engine::ChangeCommand(0, 1);
        commandB = new engine::MoveCommand(1, 2);
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), false);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetStatCurrent(state::hp), 69);
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetState(), state::CreatureState::active);
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetName(), "FireSheep");
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetStatCurrent(state::hp), 82);
    }

    BOOST_AUTO_TEST_CASE( test_ChangeCommand_fail_ko )
    {
        commandA = new engine::ChangeCommand(0, 0);
        commandB = new engine::MoveCommand(1, 2);
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), false);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetStatCurrent(state::hp), 69);
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetState(), state::CreatureState::active);
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetName(), "FireSheep");
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetStatCurrent(state::hp), 82);
    }

    BOOST_AUTO_TEST_CASE( test_ChangeCommand_revert )
    {
        commandA = new engine::ChangeCommand(0, 2);
        commandB = new engine::MoveCommand(1, 0);
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), false);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetStatCurrent(state::hp), 69);
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetState(), state::CreatureState::active);
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetName(), "FireSheep");
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetStatCurrent(state::hp), 82);
    }

    BOOST_AUTO_TEST_CASE( test_Item_trigger_hp )
    {
        commandA = new engine::MoveCommand(0, 2);
        commandB = new engine::MoveCommand(1, 3);
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), true);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetStatCurrent(state::hp), 56);
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetItem(), nullptr);
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetStatCurrent(state::hp), 78);
    }

    BOOST_AUTO_TEST_CASE( test_Item_trigger_other )
    {
        commandA = new engine::ChangeCommand(0, 2);
        commandB = new engine::ChangeCommand(1, 1);
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), true);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetName(), "Aquis");
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetName(), "Aquis");
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetItem()->GetName(), "Berserker_Shell");

        commandA = new engine::MoveCommand(0, 0);
        commandB = new engine::MoveCommand(1, 0);
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), true);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetStatCurrent(state::atk), 108);
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetItem(), nullptr);
    }

    BOOST_AUTO_TEST_CASE( test_skip_dead )
    {
        commandA = new engine::MoveCommand(0, 0);
        commandB = new engine::MoveCommand(1, 0);
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), true);
        delete commandA;
        delete commandB;

        commandA = new engine::MoveCommand(0, 0);
        commandB = new engine::MoveCommand(1, 0);
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), true);
        delete commandA;
        delete commandB;

        commandA = new engine::MoveCommand(0, 1);
        commandB = new engine::MoveCommand(1, 0);
        BOOST_CHECK_EQUAL(engine.Execute(commandA, commandB, battle), true);
        delete commandA;
        delete commandB;
        BOOST_CHECK_EQUAL(battle->GetTrainerB()->GetActiveCreature()->GetStatCurrent(state::hp), 20);
        BOOST_CHECK_EQUAL(battle->GetTrainerA()->GetActiveCreature()->GetState(), state::ko);

        delete trainerA;
        delete trainerB;
        delete battle;
    }
    
BOOST_AUTO_TEST_SUITE_END()
