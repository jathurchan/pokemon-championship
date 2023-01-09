
#include <boost/test/unit_test.hpp>
#include <state.hpp>
#include <model.hpp>
#include <iostream>

#define HP state::StatName::hp
#define ATK state::StatName::atk
#define DEF state::StatName::def
#define SPD state::StatName::spd

using namespace std;

BOOST_AUTO_TEST_SUITE( TestMove )

    model::Model model("defaultCreatures", "defaultItems");
    model::Move modelMove(*model.GetCreature("Aquis")->GetMoves().at(0));

    BOOST_AUTO_TEST_CASE( test_Move_0 )
    {
        state::Move move(&modelMove);
        BOOST_CHECK_EQUAL(move.GetName(), "WaterSpray");

        BOOST_CHECK_EQUAL(move.GetBasePP(), 5);
        BOOST_CHECK_EQUAL(move.GetCurrPP(), 5);
        move.DecrementPP();
        BOOST_CHECK_EQUAL(move.GetCurrPP(), 4);

        BOOST_TEST(move.GetAura()->GetValue() == -0.15f, boost::test_tools::tolerance(0.001));
        BOOST_CHECK_EQUAL(move.GetPower(), 90);
        BOOST_CHECK_EQUAL(move.GetAura()->GetName(), "DefDebuf");
        BOOST_CHECK_EQUAL(move.GetAura()->TargetsSelf(), false);
        BOOST_CHECK_EQUAL(move.GetAura()->GetTargetStat(), DEF);
        BOOST_CHECK_EQUAL(move.HasPriority(), true);
        BOOST_CHECK_EQUAL(move.GetType()->GetName(), "Water"); 
    }

BOOST_AUTO_TEST_SUITE_END()


/* vim: set sw=2 sts=2 et : */
