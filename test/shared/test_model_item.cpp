#include <boost/test/unit_test.hpp>
#include <model.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE( TestModelItem )

    model::Model model("defaultCreatures", "defaultItems");
    model::Item healingFlask = *model.GetItem("Healing_Flask");
    model::Item none = *model.GetItem("");

    BOOST_AUTO_TEST_CASE( test_item_getName )
    {
        BOOST_CHECK_EQUAL(healingFlask.GetName(), "Healing_Flask");
        BOOST_CHECK_EQUAL(none.GetName(), "None");
    }

    BOOST_AUTO_TEST_CASE( test_item_getAura )
    {
        BOOST_CHECK_EQUAL(healingFlask.GetAura()->GetName(), "Heal");
        BOOST_CHECK_EQUAL(none.GetAura()->GetName(), "nullAura");
    }

    BOOST_AUTO_TEST_CASE( test_item_getTrigger )
    {
        model::Trigger trigger = *healingFlask.GetTrigger();
        BOOST_CHECK_EQUAL(trigger.GetName(), "");       //unimplemented
        BOOST_CHECK_EQUAL(trigger.GetStat(), 0);        //HP
        BOOST_CHECK_EQUAL(trigger.GetThreshold(), 50);  //50%
    }

BOOST_AUTO_TEST_SUITE_END()
