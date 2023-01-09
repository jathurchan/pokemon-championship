#include "TextBox.hpp"

namespace render {

    TextBox::TextBox() = default;
    TextBox::~TextBox() = default;

    void TextBox::renderActivate(sf::Time time, sf::View *view) {
        savedTime = time;
        this->sprite->changeTexture(parameters[0].asString());
        this->text->changeText(text->getText().getString() + "|");
    }

    void TextBox::renderHold(sf::Time time) {
        if (time >= savedTime + sf::seconds(parameters[1].asFloat()) && isReleased) {
            if (((std::string) text->getText().getString()).back() == '|') {
                std::string tmp = (std::string) text->getText().getString();
                tmp.pop_back();
                text->changeText(tmp);
                savedTime = time;
            }
            else {
                text->changeText(text->getText().getString() + "|");
                savedTime = time;
            }
        }
    }

    void TextBox::renderDeactivate() {
        if (((std::string) text->getText().getString()).back() == '|') {
            std::string tmp = (std::string) text->getText().getString();
            tmp.pop_back();
            text->changeText(tmp);
        }
        sprite->changeTexture(sprite->getFileName());
        active = false;
        canBePressed = true;
    }
}