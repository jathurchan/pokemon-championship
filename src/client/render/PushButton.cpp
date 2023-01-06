#include "PushButton.hpp"


namespace render {

    PushButton::PushButton() = default;
    PushButton::~PushButton() = default;

    void PushButton::renderActivate(sf::Time time, sf::View* view) {
        this->view = view;
        startTime = time;
        this->sprite->changeTexture(parameters[0].asString());
        this->text->move(*view, parameters[2].asFloat(), parameters[3].asFloat());
    }

    void PushButton::renderHold(sf::Time time) {
        if (time >= startTime+sf::seconds(parameters[1].asFloat()) && isReleased)
            renderDeactivate();
    }

    void PushButton::renderDeactivate() {
        sprite->changeTexture(sprite->getFileName());
        this->text->move(*view, -parameters[2].asFloat(), -parameters[3].asFloat());
        active = false;
        canBePressed = true;
    }
}