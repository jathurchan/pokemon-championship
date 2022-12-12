#include <iostream>
#include <utility>
#include "CustomButton.hpp"

namespace render {

    std::unordered_map<std::string,std::function<void(CustomButton&)>> buttonActionsMap = {
            {"test", &CustomButton::test}
    };

    CustomButton::CustomButton() = default;

    CustomButton::CustomButton(CustomSprite *sprite, std::string buttonFunction) {
        this->sprite = sprite;
        this->buttonFunction = std::move(buttonFunction);
    }

    /*
     * Checks whether the position is inside the visible part of the sprite.
    */
    bool CustomButton::isInSprite(sf::Vector2f position) {
        return (sprite->getSprite().getGlobalBounds().contains(position.x, position.y) &&
                sprite->getImagePtr()->getPixel((int) (sprite->getSprite().getOrigin().x -
                                                       (sprite->getSprite().getPosition().x - position.x) /
                                                       sprite->getSprite().getScale().x),
                                                (int) (sprite->getSprite().getOrigin().y -
                                                       (sprite->getSprite().getPosition().y - position.y) /
                                                       sprite->getSprite().getScale().y)).a != 0);
    }

    void CustomButton::action() {
        buttonActionsMap[buttonFunction](*this);
    }

    bool CustomButton::isActive() {
        return active;
    }

    void CustomButton::test() {
        std::cout << "CA MAAAAAAAAAAARCHE" << std::endl;
    }
}