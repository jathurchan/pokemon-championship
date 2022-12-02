#include <iostream>
#include <utility>
#include "CustomButtonWithText.hpp"
#include "CustomButton.hpp"

namespace client {

    CustomButtonWithText::CustomButtonWithText() = default;

    CustomButtonWithText::CustomButtonWithText(std::string fileName, bool smooth, Json::Value parameters) : CustomButton(std::move(fileName), smooth, std::move(parameters)) {}

    CustomText& CustomButtonWithText::getText() {
        return text;
    }

    CustomButtonWithText* CustomButtonWithText::clickedOnButtonAction() {
        return normalButtonWithTextAction();
    }

    CustomButtonWithText* CustomButtonWithText::clickedOnButtonTimed() {
        currentTime = ResourceHolder::getInstance().getClkTime();
        if (currentTime >= startTime+sf::seconds(parameters[1].asFloat()))
            return normalButtonWithTextTimed();
        return this;
    }

    CustomButtonWithText* CustomButtonWithText::clickedOnButtonDisable() {
        this->changeTexture(fileName);
        pressed = false;
        return normalButtonDisable();
    }

    CustomButtonWithText* CustomButtonWithText::normalButtonWithTextAction() {
        if (!pressed) {
            this->changeTexture(parameters[0].asString());
            text.move(*view,parameters[2].asFloat(), parameters[3].asFloat());
            pressed = true;
            startTime = ResourceHolder::getInstance().getClkTime();
            currentTime = ResourceHolder::getInstance().getClkTime();
        }
        return this;
    }

    CustomButtonWithText* CustomButtonWithText::normalButtonWithTextTimed() {
        return clickedOnButtonDisable();
    }

    CustomButtonWithText* CustomButtonWithText::normalButtonDisable() {
        text.move(*view,-parameters[2].asFloat(), -parameters[3].asFloat());
        return nullptr;
    }
}