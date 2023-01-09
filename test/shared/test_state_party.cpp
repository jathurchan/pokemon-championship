
#include <boost/test/unit_test.hpp>
#include <state.hpp>
#include <model.hpp>
#include <iostream>

#define HP state::StatName::hp

using namespace std;

BOOST_AUTO_TEST_SUITE( TestParty )

    model::Model model("defaultCreatures", "defaultItems");
    std::array<std::string, 6> pokemon = {"FireSheep", "DisGrass", "Aquis", "FireSheep", "DisGrass", "Aquis"};
    std::array<int, 3> order = {0,1,2};
    state::Party party;

    BOOST_AUTO_TEST_CASE( test_Init )
    {
        party.LoadFromModel(&model, pokemon);

        BOOST_CHECK_EQUAL(party.SetBannedCreature(6), false);
        BOOST_CHECK_EQUAL(party.SetBannedCreature(2), true);
        BOOST_CHECK_EQUAL(party.SetBannedCreature(3), true);

        party.SetParticipatingTeam(order);

        BOOST_CHECK_EQUAL(party.GetName(0), "FireSheep");
        BOOST_CHECK_EQUAL(party.GetName(1), "DisGrass");
        BOOST_CHECK_EQUAL(party.GetName(2), "Aquis");
    }

    BOOST_AUTO_TEST_CASE( test_GivingResources )
    {
        party.GiveItem(model.GetItem("Healing_Flask"), 0);
        BOOST_CHECK_EQUAL(party.GetRemainingItems(), 1);
        party.GiveItem(model.GetItem("Healing_Flask"), 1);
        BOOST_CHECK_EQUAL(party.GetRemainingItems(), 0);
        party.GiveItem(model.GetItem("Healing_Flask"), 2);
        BOOST_CHECK_EQUAL(party.GetRemainingItems(), 0);

        BOOST_CHECK_EQUAL(party.GetItem(0)->GetName(), "Healing_Flask");
        BOOST_CHECK_EQUAL(party.GetItem(1)->GetName(), "Healing_Flask");
        BOOST_CHECK_EQUAL(party.GetItem(2), nullptr);


    }

    BOOST_AUTO_TEST_CASE( test_States )
    {
        BOOST_CHECK_EQUAL(party.GetActiveCreature()->GetName(), "FireSheep");

        BOOST_CHECK_EQUAL(party.SetCreatureActive(3), false);

        BOOST_CHECK_EQUAL(party.SetCreatureActive(1), true);
        BOOST_CHECK_EQUAL(party.GetActiveCreature()->GetName(), "DisGrass");

        party.SetCreatureActive(1);
        party.GetActiveCreature()->UpdateState(state::CreatureState::ko);
        BOOST_CHECK_EQUAL(party.SetCreatureActive(2), true); 
        BOOST_CHECK_EQUAL(party.SetCreatureActive(1), false);   // Creature is ko, cannot become active  
    }


BOOST_AUTO_TEST_SUITE_END()


/* vim: set sw=2 sts=2 et : */
