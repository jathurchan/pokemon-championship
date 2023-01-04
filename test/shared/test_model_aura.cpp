#include <boost/test/unit_test.hpp>
#include <model.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE( TestModelAura )

    model::Model model("defaultCreatures", "defaultItems");
    model::Aura defBuf = *(model.GetCreature("defaultCreatures/DisGrass")->GetMoves()[0]->GetAura());

    BOOST_AUTO_TEST_CASE( test_aura_getName )
    {
        BOOST_CHECK_EQUAL(defBuf.GetName(), "defaultAuras/DefBuf");
    }

    BOOST_AUTO_TEST_CASE( test_aura_getTargetStat )
    {
        BOOST_CHECK_EQUAL(defBuf.GetTargetStat(), 2);   //DEF
    }

    BOOST_AUTO_TEST_CASE( test_aura_getValue )
    {
        BOOST_CHECK_EQUAL(defBuf.GetValue(), 1.15f);
    }

    BOOST_AUTO_TEST_CASE( test_aura_TargetsSelf )
    {
        BOOST_CHECK_EQUAL(defBuf.TargetsSelf(), true);
    }


BOOST_AUTO_TEST_SUITE_END()
