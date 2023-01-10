#include <boost/test/unit_test.hpp>
#include <model.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE( TestModel )

    model::Model* model;

    BOOST_AUTO_TEST_CASE( test_model_load_fail )
    {
        BOOST_CHECK_THROW(model = new model::Model("uNdEfInEd__FIle", "testItems"), std::runtime_error);
        delete model;
        BOOST_CHECK_THROW(model = new model::Model("testItems", "testItems"), std::runtime_error);
        delete model;
    }
    BOOST_AUTO_TEST_CASE( test_model_load_success )
    {
        model = new model::Model;
        delete model;
        model = new model::Model("testCreatures", "testItems");
        BOOST_CHECK(true);
    }

    BOOST_AUTO_TEST_CASE( test_model_getCreature )
    {
        BOOST_CHECK_EQUAL(model->GetCreature("FireSheep")->GetName(), "FireSheep");
    }

    BOOST_AUTO_TEST_CASE( test_model_getItem )
    {
        BOOST_CHECK_EQUAL(model->GetItem("Healing_Flask")->GetName(), "Healing_Flask");
    }

BOOST_AUTO_TEST_SUITE_END()
