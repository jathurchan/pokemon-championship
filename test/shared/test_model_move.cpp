#include <boost/test/unit_test.hpp>
#include <model.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE( TestModelMove )

    model::Model model("defaultCreatures", "defaultItems");
    model::Move thorns = *(model.GetCreature("DisGrass")->GetMoves()[0]);

    BOOST_AUTO_TEST_CASE( test_move_getName )
    {
        BOOST_CHECK_EQUAL(thorns.GetName(), "Thorns");
    }

    BOOST_AUTO_TEST_CASE( test_move_getAura )
    {
        BOOST_CHECK_EQUAL(thorns.GetAura()->GetName(), "DefBuf");
    }

    BOOST_AUTO_TEST_CASE( test_move_getPP )
    {
        BOOST_CHECK_EQUAL(thorns.GetPP(), 3);
    }

    BOOST_AUTO_TEST_CASE( test_move_getPower )
    {
        BOOST_CHECK_EQUAL(thorns.GetPower(), 110);
    }

    BOOST_AUTO_TEST_CASE( test_move_hasPriority )
    {
        BOOST_CHECK_EQUAL(thorns.HasPriority(), false);
    }

    BOOST_AUTO_TEST_CASE( test_move_getType )
    {
        BOOST_CHECK_EQUAL(thorns.GetType()->GetName(), "Grass");
    }

BOOST_AUTO_TEST_SUITE_END()
