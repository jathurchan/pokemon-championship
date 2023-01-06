#include <boost/test/unit_test.hpp>
#include <model.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE( TestModel )

    model::Model empty = model::Model();
    model::Model model("defaultCreatures", "defaultItems");

    BOOST_AUTO_TEST_CASE( test_model_getCreature )
    {
        BOOST_CHECK_EQUAL(model.GetCreature("defaultCreatures/FireSheep")->GetName(), "defaultCreatures/FireSheep");
    }

    BOOST_AUTO_TEST_CASE( test_model_getItem )
    {
        BOOST_CHECK_EQUAL(model.GetItem("defaultItems/Healing_Flask")->GetName(), "defaultItems/Healing_Flask");
    }

BOOST_AUTO_TEST_SUITE_END()
