#include "CustomButton.hpp"

namespace render {

    /*
     * Checks whether the position is inside the visible part of the sprite.
    */
    bool CustomButton::isInSprite(sf::Vector2f position) {
        return (sprite.getGlobalBounds().contains(position.x, position.y) &&
                imagePtr->getPixel((int) (sprite.getOrigin().x - (sprite.getPosition().x-position.x)/sprite.getScale().x),
                                   (int) (sprite.getOrigin().y - (sprite.getPosition().y-position.y)/sprite.getScale().y)).a != 0);
    }

}