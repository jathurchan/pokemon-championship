#include <boost/test/unit_test.hpp>
#include <model.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE( TestModelItem )

    model::Model model("testCreatures", "testItems");
    model::Item healingFlask = *model.GetItem("Healing_Flask");

    BOOST_AUTO_TEST_CASE( test_item_getName )
    {
        BOOST_CHECK_EQUAL(healingFlask.GetName(), "Healing_Flask");
        BOOST_CHECK_EQUAL(model.GetItem(""), nullptr);
    }

    BOOST_AUTO_TEST_CASE( test_item_getAura )
    {
        BOOST_CHECK_EQUAL(healingFlask.GetAura()->GetName(), "Heal");
    }

    BOOST_AUTO_TEST_CASE( test_item_getTrigger )
    {
        model::Trigger trigger = *healingFlask.GetTrigger();
        BOOST_CHECK_EQUAL(trigger.GetName(), "");       //unimplemented
        BOOST_CHECK_EQUAL(trigger.GetStat(), 0);        //HP
        BOOST_CHECK_EQUAL(trigger.GetThreshold(), 50);  //50%
    }

BOOST_AUTO_TEST_SUITE_END()
