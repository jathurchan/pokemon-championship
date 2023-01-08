
#include <boost/test/unit_test.hpp>
#include <state.hpp>
#include <model.hpp>
#include <iostream>

#define HP state::StatName::hp

using namespace std;

BOOST_AUTO_TEST_SUITE( TestStats )

    model::Model model("defaultCreatures", "defaultItems");
    state::Creature aquis(model.GetCreature("defaultCreatures/Aquis"));
    state::Item* item = new state::Item(model.GetItem("defaultItems/Healing_Flask"));
    
    BOOST_AUTO_TEST_CASE( test_stateCreature )
    {
        BOOST_CHECK_EQUAL(aquis.GetName(), "defaultCreatures/Aquis");        
        BOOST_CHECK_EQUAL(aquis.GetState(), state::CreatureState::sub );
    }


    BOOST_AUTO_TEST_CASE( test_Stat )
    {
        BOOST_CHECK_EQUAL(aquis.GetStatBase(HP), 100);
        BOOST_CHECK_EQUAL(aquis.GetStatCurrent(HP), 100);

        BOOST_CHECK_EQUAL(aquis.GetMove(0)->GetName(), "defaultMoves/WaterSpray");

        BOOST_CHECK_EQUAL(aquis.GetType()->GetName(), "defaultTypes/Water");
        BOOST_CHECK_EQUAL(aquis.GetType()->GetFactor("Fire"), 2);
        BOOST_CHECK_EQUAL(aquis.GetType()->GetFactor("Grass"), 0.5);
        BOOST_CHECK_EQUAL(aquis.GetType()->GetFactor("OtherType"), 1);

        aquis.UpdateState(state::CreatureState::active);
        BOOST_CHECK_EQUAL(aquis.GetState(), state::CreatureState::active);

        aquis.UpdateState(state::CreatureState::ko);
        BOOST_CHECK_EQUAL(aquis.GetState(), state::CreatureState::ko);

        aquis.UpdateState(state::CreatureState::sub);
        BOOST_CHECK_EQUAL(aquis.GetState(), state::CreatureState::ko);

        aquis.GiveItem(model.GetItem("defaultItems/Healing_Flask"));
        BOOST_CHECK_EQUAL(aquis.GetItem()->GetName(), item->GetName());
        aquis.GiveItem(model.GetItem("defaultItems/Berserker_Shell"));
        BOOST_CHECK_EQUAL(aquis.GetItem()->GetName(), item->GetName());
        
        aquis.RemoveItem();
        BOOST_CHECK_EQUAL(aquis.GetItem(), nullptr);
        
        delete item;
    }


BOOST_AUTO_TEST_SUITE_END()


/* vim: set sw=2 sts=2 et : */
