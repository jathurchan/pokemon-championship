#include <boost/test/unit_test.hpp>
#include <model.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE( TestModelCreature )

    model::Model model("defaultCreatures", "defaultItems");
    model::Creature fireSheep = *model.GetCreature("defaultCreatures/FireSheep");

    BOOST_AUTO_TEST_CASE( test_creature_getName )
    {
        BOOST_CHECK_EQUAL(fireSheep.GetName(), "defaultCreatures/FireSheep");
    }

    BOOST_AUTO_TEST_CASE( test_creature_getStats )
    {
        std::array<int, 4> stats = fireSheep.GetStats();
        BOOST_CHECK_EQUAL(stats[0], 70);
        BOOST_CHECK_EQUAL(stats[1], 150);
        BOOST_CHECK_EQUAL(stats[2], 110);
        BOOST_CHECK_EQUAL(stats[3], 70);
    }

    BOOST_AUTO_TEST_CASE( test_creature_getMoves )
    {
        std::array<model::Move*, 4> moves = fireSheep.GetMoves();
        BOOST_CHECK_EQUAL(moves[0]->GetName(), "defaultMoves/FireBall");
        BOOST_CHECK_EQUAL(moves[1]->GetName(), "defaultMoves/Punch");
        BOOST_CHECK_EQUAL(moves[2]->GetName(), "defaultMoves/Charge");
        BOOST_CHECK_EQUAL(moves[3]->GetName(), "defaultMoves/HeadButt");
    }

    BOOST_AUTO_TEST_CASE( test_creature_getType )
    {
        BOOST_CHECK_EQUAL(fireSheep.GetType()->GetName(), "defaultTypes/Fire");
    }

BOOST_AUTO_TEST_SUITE_END()
