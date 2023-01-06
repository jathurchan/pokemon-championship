#include <iostream>
#include "ToggleButton.hpp"

namespace render {

    std::unordered_map<unsigned int , std::vector<ToggleButton*>> ToggleButton::toggleButtonMap;

    ToggleButton::ToggleButton() = default;
    ToggleButton::~ToggleButton() = default;

    void ToggleButton::renderActivate(sf::Time time, sf::View *view) {
        setToggleGroup(parameters[1].asInt());
        this->sprite->changeTexture(parameters[0].asString());
        for (auto buttonPtr : toggleButtonMap[toggleGroup]) {
            if (buttonPtr != this)
                buttonPtr->renderDeactivate();
        }
    }

    void ToggleButton::renderHold(sf::Time time) {}

    void ToggleButton::renderDeactivate() {
        sprite->changeTexture(sprite->getFileName());
        active = false;
        canBePressed = true;
    }

    void ToggleButton::setToggleGroup(unsigned int toggleGroup) {
        this->toggleGroup = toggleGroup;
        if (std::find(toggleButtonMap[toggleGroup].begin(), toggleButtonMap[toggleGroup].end(), this) == toggleButtonMap[toggleGroup].end()) {
            toggleButtonMap[toggleGroup].push_back(this);
        }
    }
}