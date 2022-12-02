#include "CustomButton.hpp"
#include <SFML/Graphics.hpp>
#include <utility>
#include <iostream>
#include "ResourceHolder.hpp"
#include <chrono>

namespace client {

    CustomButton::CustomButton() {}

    CustomButton::CustomButton(std::string fileName, bool smooth, Json::Value parameters) : CustomSprite(std::move(fileName), smooth) {
        this->parameters = std::move(parameters);
    }

    CustomButton* CustomButton::clickedOnButtonAction() {
        return nullptr;
    }

    CustomButton* CustomButton::clickedOnButtonTimed() {
        return nullptr;
    }

    CustomButton* CustomButton::clickedOnButtonDisable() {
        return nullptr;
    }

    void CustomButton::setView(sf::View* view) {
        this->view = view;
    }

    void CustomButton::setActiveButton(CustomButton *listPtr) {
        this->activeButtonPtr=listPtr;
    }
}