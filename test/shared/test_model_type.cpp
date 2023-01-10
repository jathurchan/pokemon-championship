#include <boost/test/unit_test.hpp>
#include <model.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE( TestModelType )

    model::Model model("testCreatures", "testItems");
    model::Type fire = *model.GetCreature("FireSheep")->GetType();

    BOOST_AUTO_TEST_CASE( test_type_getName )
    {
        BOOST_CHECK_EQUAL(fire.GetName(), "Fire");
    }

    BOOST_AUTO_TEST_CASE( test_type_getFactor )
    {
        BOOST_CHECK_EQUAL(fire.GetFactor("Grass"), 2.f);
        BOOST_CHECK_EQUAL(fire.GetFactor("Water"), .5f);
        BOOST_CHECK_EQUAL(fire.GetFactor("uNdEfInEd"), 1.f);
    }

BOOST_AUTO_TEST_SUITE_END()
