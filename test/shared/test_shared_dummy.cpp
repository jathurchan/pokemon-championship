
#include <boost/test/unit_test.hpp>

namespace utf = boost::unit_test;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_SUITE(s1)

    BOOST_AUTO_TEST_CASE(test1)
    {
        BOOST_TEST(true);
    }

    BOOST_AUTO_TEST_CASE(test2, * utf::disabled())
    {
        BOOST_TEST(false);
    }

BOOST_AUTO_TEST_SUITE_END()

/* vim: set sw=2 sts=2 et : */
