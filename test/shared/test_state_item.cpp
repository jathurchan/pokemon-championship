#include <boost/test/unit_test.hpp>
#include <model.hpp>
#include <state.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE( TestModelItem )

    model::Model model("defaultCreatures", "defaultItems");

    state::Item healingFlask(model.GetItem("defaultItems/Healing_Flask"));

    BOOST_AUTO_TEST_CASE( test_item_getName )
    {
        BOOST_CHECK_EQUAL(healingFlask.GetName(), "defaultItems/Healing_Flask");


        BOOST_CHECK_EQUAL(healingFlask.GetThreshold() , 50);
        BOOST_TEST(healingFlask.GetMultiplier() == 1.3f, boost::test_tools::tolerance(0.001));
        BOOST_CHECK_EQUAL(healingFlask.GetStatName() , state::StatName::hp);
        BOOST_CHECK_EQUAL(healingFlask.IsPermanent() , false);
    }

BOOST_AUTO_TEST_SUITE_END()