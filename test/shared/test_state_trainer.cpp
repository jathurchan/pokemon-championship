#include <boost/test/unit_test.hpp>
#include <engine.hpp>
#include <state.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE( TestEngine )

    model::Model model("testCreatures", "testItems");

    state::Trainer* trainerA = new state::Trainer("Shell");
    std::array<model::Creature*, 6> pokemon = {model.GetCreature("FireSheep"), model.GetCreature("DisGrass"), model.GetCreature("Aquis"), model.GetCreature("FireSheep"), model.GetCreature("DisGrass"), model.GetCreature("Aquis")};

    engine::Engine engine;
    
    BOOST_AUTO_TEST_CASE( test_game )
    {
        trainerA->GetParty()->LoadFromModel(pokemon);
        BOOST_CHECK_EQUAL(trainerA->GetActiveCreature(), nullptr);
        BOOST_CHECK_EQUAL(trainerA->GetName(), "Shell");
        trainerA->SetState(state::TrainerState::won);
        BOOST_CHECK_EQUAL(trainerA->GetState(), state::TrainerState::won);
    
        delete trainerA;
    }
    
BOOST_AUTO_TEST_SUITE_END()
