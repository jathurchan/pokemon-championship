
#include <boost/test/unit_test.hpp>
#include <state.hpp>
#include <model.hpp>
#include <iostream>

#define HP state::StatName::hp
#define ATK state::StatName::atk
#define DEF state::StatName::def
#define SPD state::StatName::spd

using namespace std;

BOOST_AUTO_TEST_SUITE( TestStats )

    model::Model model("defaultCreatures", "defaultItems");
    model::Creature aquis = *model.GetCreature("Aquis");
    
    BOOST_AUTO_TEST_CASE( test_modelCreature )
    {
        BOOST_CHECK_EQUAL(aquis.GetName(), "Aquis");
    }


    BOOST_AUTO_TEST_CASE( test_Stat )
    {
        state::Stat currentStat(HP, aquis.GetStats()[HP]);
        BOOST_CHECK_EQUAL(currentStat.GetBase(), 100);
        BOOST_CHECK_EQUAL(currentStat.GetCurrent(), 100);
        currentStat.Update(120);
        BOOST_CHECK_EQUAL(currentStat.GetBase(), 100);
        BOOST_CHECK_EQUAL(currentStat.GetCurrent(), 120);
        
        currentStat.Update(-120);
        BOOST_CHECK_EQUAL(currentStat.GetBase(), 100);
        BOOST_CHECK_EQUAL(currentStat.GetCurrent(), 0);
        
        currentStat = state::Stat(ATK, aquis.GetStats()[ATK]);
        BOOST_CHECK_EQUAL(currentStat.GetStatName(), ATK);
    }


BOOST_AUTO_TEST_SUITE_END()


/* vim: set sw=2 sts=2 et : */
