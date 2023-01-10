
#include <boost/test/unit_test.hpp>
#include <state.hpp>
#include <model.hpp>
#include <iostream>

#define HP state::StatName::hp

using namespace std;

BOOST_AUTO_TEST_SUITE( TestParty )

    model::Model model("testCreatures", "testItems");
    std::array<model::Creature*, 6> pokemon = {model.GetCreature("FireSheep"), model.GetCreature("DisGrass"), model.GetCreature("Aquis"), model.GetCreature("FireSheep"), model.GetCreature("DisGrass"), model.GetCreature("Aquis")};
    std::array<std::pair<int, model::Item*>, 3> order({std::pair<int, model::Item*>(0, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(1, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(2, model.GetItem(""))});
    std::array<std::pair<int, model::Item*>, 3> order_fail({std::pair<int, model::Item*>(0, model.GetItem("Berserker_Shell")), std::pair<int, model::Item*>(1, model.GetItem("Healing_Flask")), std::pair<int, model::Item*>(2, model.GetItem("Berserker_Shell"))});
    state::Party party;

    BOOST_AUTO_TEST_CASE( test_Init )
    {
        party.LoadFromModel(pokemon);

        BOOST_CHECK_EQUAL(party.SetBannedCreature(6), false);

        BOOST_CHECK_EQUAL(party.SetBannedCreature(2), true);
        BOOST_REQUIRE_EQUAL(party.SetParticipatingTeam(order), false);

        BOOST_CHECK_EQUAL(party.SetBannedCreature(3), true);
        BOOST_REQUIRE_EQUAL(party.SetParticipatingTeam(order_fail), false);

        BOOST_CHECK_EQUAL(party.SetBannedCreature(3), true);
        BOOST_REQUIRE_EQUAL(party.SetParticipatingTeam(order), true);


        BOOST_CHECK_EQUAL(party.GetName(0), "FireSheep");
        BOOST_CHECK_EQUAL(party.GetName(1), "DisGrass");
        BOOST_CHECK_EQUAL(party.GetName(2), "Aquis");

        BOOST_CHECK_EQUAL(party.GetItem(0)->GetName(), "Berserker_Shell");
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
