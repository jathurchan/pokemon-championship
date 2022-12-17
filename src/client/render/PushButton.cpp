#include "PushButton.hpp"

#include <utility>

namespace render {

    PushButton::PushButton() = default;
    PushButton::~PushButton() = default;

    void PushButton::renderActivate(sf::Time time) {
        startTime = time;
        this->sprite->changeTexture(parameters[0].asString());
    }

    void PushButton::renderHold(sf::Time time) {
        if (time >= startTime+sf::seconds(parameters[1].asFloat()) && isReleased)
            renderDeactivate();
    }

    void PushButton::renderDeactivate() {
        sprite->changeTexture(sprite->getFileName());
        active = false;
        canBePressed = true;
    }
}