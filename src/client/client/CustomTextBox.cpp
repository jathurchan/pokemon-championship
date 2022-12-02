#include <iostream>
#include "CustomTextBox.hpp"

namespace client {

    CustomTextBox::CustomTextBox(std::string fileName, bool smooth, Json::Value parameters) : CustomButtonWithText(std::move(fileName), smooth, std::move(parameters)) {}

    CustomTextBox* CustomTextBox::clickedOnButtonAction() {
        if (!pressed) {
            this->changeTexture(parameters[0].asString());
            this->text.changeText(text.getText().getString() + "|");
            pressed = true;
            startTime = ResourceHolder::getInstance().getClkTime();
            currentTime = ResourceHolder::getInstance().getClkTime();
            return this;
        }
        return nullptr;
    }

    CustomTextBox *CustomTextBox::clickedOnButtonTimed() {
        if (((std::string) text.getText().getString()).back() == '|') {
            std::string tmpText = (std::string) text.getText().getString();
            tmpText.pop_back();
            text.changeText(tmpText);
            startTime = ResourceHolder::getInstance().getClkTime();
        }
        else {
            text.changeText(text.getText().getString() + "|");
            startTime = ResourceHolder::getInstance().getClkTime();
        }
        return this;
    }

    CustomTextBox* CustomTextBox::clickedOnButtonDisable() {
        if (((std::string) text.getText().getString()).back() == '|') {
            std::string tmpText = (std::string) text.getText().getString();
            tmpText.pop_back();
            text.changeText(tmpText);
        }
        return nullptr;
    }

}