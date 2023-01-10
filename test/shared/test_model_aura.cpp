#include <boost/test/unit_test.hpp>
#include <model.hpp>
#include <state.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE( TestModelAura )

    model::Model model("testCreatures", "testItems");
    model::Aura defBuf = *(model.GetCreature("DisGrass")->GetMoves()[0]->GetAura());

    BOOST_AUTO_TEST_CASE( test_aura_getName )
    {
        BOOST_CHECK_EQUAL(defBuf.GetName(), "DefBuf");
    }

    BOOST_AUTO_TEST_CASE( test_aura_getTargetStat )
    {
        BOOST_CHECK_EQUAL(defBuf.GetTargetStat(), state::StatName::def);
    }

    BOOST_AUTO_TEST_CASE( test_aura_getValue )
    {
        BOOST_TEST(defBuf.GetValue() == 0.15f, boost::test_tools::tolerance(0.001));
    }

    BOOST_AUTO_TEST_CASE( test_aura_TargetsSelf )
    {
        BOOST_CHECK_EQUAL(defBuf.TargetsSelf(), true);
    }


BOOST_AUTO_TEST_SUITE_END()
