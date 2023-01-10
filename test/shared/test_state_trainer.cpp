#include <boost/test/unit_test.hpp>
#include <engine.hpp>
#include <state.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE( TestEngine )

    model::Model model("testCreatures", "testItems");

    state::Trainer* trainerA = new state::Trainer("Shell");
    std::array<std::string, 6> pokemon = {"FireSheep", "DisGrass", "Aquis", "FireSheep", "DisGrass", "Aquis"};

    engine::Engine engine;
    
    BOOST_AUTO_TEST_CASE( test_game )
    {
        trainerA->GetParty()->LoadFromModel(&model, pokemon);
        BOOST_CHECK_EQUAL(trainerA->GetActiveCreature(), nullptr);
        BOOST_CHECK_EQUAL(trainerA->GetName(), "Shell");
        trainerA->SetState(state::TrainerState::won);
        BOOST_CHECK_EQUAL(trainerA->GetState(), state::TrainerState::won);
    
        delete trainerA;
    }
    
BOOST_AUTO_TEST_SUITE_END()
