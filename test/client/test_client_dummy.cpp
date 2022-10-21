
#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>
#include <SFML/Graphics.hpp>

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestSFML)
{
  {
    ::sf::Texture texture;
    BOOST_CHECK(texture.getSize() == ::sf::Vector2<unsigned int> {});
  }
}
