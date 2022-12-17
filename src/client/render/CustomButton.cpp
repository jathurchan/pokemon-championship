#include <iostream>
#include <utility>
#include <memory>
#include "CustomButton.hpp"
#include "PushButton.hpp"

namespace render {

    CustomButton::CustomButton() = default;
    CustomButton::~CustomButton() = default;

    void CustomButton::create(CustomSprite *sprite, std::string renderFunction, std::string engineFunction, Json::Value parameters) {
        this->sprite = sprite;
        this->renderFunction = std::move(renderFunction);
        this->engineFunction = std::move(engineFunction);
        this->parameters = std::move(parameters);
    }

    // Si qq a du temps à perdre, je le laisse s'amuser à faire ca sans switch/case
    std::shared_ptr<CustomButton> CustomButton::buttonFactory (ButtonsName buttonName) {
        switch (buttonName) {
            case Push_Button:
                return std::make_shared<PushButton>();
            default:
                return nullptr;
        }
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

    std::string CustomButton::getEngineFunction() {
        return engineFunction;
    }

    void CustomButton::setReleased(bool status) {
        isReleased = status;
    }

    bool CustomButton::getCanBePressed() {
        return canBePressed;
    }

    void CustomButton::setCanBePressed(bool status) {
        canBePressed = status;
    }
}
