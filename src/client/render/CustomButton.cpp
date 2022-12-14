#include <iostream>
#include <utility>
#include "CustomButton.hpp"

namespace render {

    std::unordered_map<std::string,std::function<void(CustomButton&)>> buttonActiveActionsMap = {

    };

    std::unordered_map<std::string,std::function<void(CustomButton&)>> buttonHoldActionsMap = {

    };

    std::unordered_map<std::string,std::function<void(CustomButton&)>> buttonDisactiveActionsMap = {

    };

    CustomButton::CustomButton() = default;

    CustomButton::CustomButton(CustomSprite *sprite, std::string buttonFunctionActive, std::string buttonFunctionHold, std::string buttonFunctionDisactive) {
        this->sprite = sprite;
        this->buttonFunctions.at(0) = std::move(buttonFunctionActive);
        this->buttonFunctions.at(1) = std::move(buttonFunctionHold);
        this->buttonFunctions.at(2) = std::move(buttonFunctionDisactive);
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

    bool CustomButton::isActive() {
        return active;
    }

    void CustomButton::setActive(bool status) {
        active = status;
    }

    int CustomButton::getStateFunctionIndex() {
        return stateFunctionIndex;
    }
}