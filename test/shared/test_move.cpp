
#include <boost/test/unit_test.hpp>
#include <state.hpp>
#include <model.hpp>
#include <iostream>

#define HP state::StatName::hp
#define ATK state::StatName::atk
#define DEF state::StatName::def
#define SPD state::StatName::spd

using namespace std;

BOOST_AUTO_TEST_SUITE( TestMoves )

    model::Model model("defaultCreatures", "defaultItems");
    model::Creature aquis = *model.GetCreature("defaultCreatures/Aquis");

    
    BOOST_AUTO_TEST_CASE( test_modelCreature )
    {
        BOOST_CHECK_EQUAL(aquis.GetName(), "defaultCreatures/Aquis");
    }


    BOOST_AUTO_TEST_CASE( test_Move_0 )
    {
        state::Move move(*aquis.GetMoves()[0]);
        BOOST_CHECK_EQUAL(move.GetName(), "100");
    }

    BOOST_AUTO_TEST_CASE( test_ATK )
    {
        state::Stat atk(ATK, aquis.GetStats()[ATK]);
        BOOST_CHECK_EQUAL(atk.GetBase(), 90);
    }

    BOOST_AUTO_TEST_CASE( test_DEF )
    {
        state::Stat def(DEF, aquis.GetStats()[DEF]);
        BOOST_CHECK_EQUAL(def.GetBase(), 80);
    }

    BOOST_AUTO_TEST_CASE( test_SPD )
    {
        state::Stat spd(SPD, aquis.GetStats()[SPD]);
        BOOST_CHECK_EQUAL(spd.GetBase(), 130);
    }

BOOST_AUTO_TEST_SUITE_END()


/* vim: set sw=2 sts=2 et : */
