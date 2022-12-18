#include "TextBox.hpp"

namespace render {

    TextBox::TextBox() = default;
    TextBox::~TextBox() = default;

    void TextBox::renderActivate(sf::Time time, sf::View *view) {
        this->view = view;
        savedTime = time;
        this->sprite->changeTexture(parameters[0].asString());
        this->text->move(*view, parameters[2].asFloat(), parameters[3].asFloat());
    }

    void TextBox::renderHold(sf::Time) {

    }

    void TextBox::renderDeactivate() {

    }
}