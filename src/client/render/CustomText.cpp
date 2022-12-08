#include "CustomText.hpp"

/*
 * Creates an instance of sf::Text and implement different method to interact with it.
 */

namespace render {

    /*
     * Default constructor.
     * Creates an empty CustomText.
     */
    CustomText::CustomText() = default;

    /*
     * Constructs the CustomText.
     * Instanciates a new sf::Text and sets its string and style, as well as its font using by loading it from the Resource Holder .
     */
    CustomText::CustomText(const std::string& fontName, const std::string& textString, sf::Text::Style style) {
        text.setFont(*ResourceHolder::getInstance().getFont(fontName));
        text.setString(textString);
        text.setStyle(style);
    }

    /*
     * Changes the content of the text.
     */
    void CustomText::changeText(const std::string& newString) {
        text.setString(newString);
    }

    //ALWAYS CALL BEFORE setPosition
    void CustomText::setCharacterSize(sf::View &view, unsigned int size) {
        text.setCharacterSize(size);
        text.setScale(view.getSize().x/800, view.getSize().x/800);
    }

    //ALWAYS CALL AFTER setCharacterSize
    void CustomText::setXOrigin (float originX) {
        text.setOrigin(text.getLocalBounds().left+(originX+10) * text.getLocalBounds().width/20, 0);
    }

    void CustomText::setPosition (sf::View& view, float posX, float posY) {
        text.setPosition((posX+100) * view.getSize().x/200,
                         (posY+100) * view.getSize().y/200);
    }

    /*
     * Sets the color of the text using the RGBA code argument.
     */
    void CustomText::setColor(int8_t red, int8_t green, int8_t blue, int8_t alpha) {
        text.setFillColor(sf::Color(red, green, blue, alpha));
    }

    void CustomText::move(sf::View &view, float posX, float posY) {
        text.move((posX+100) * view.getSize().x/200,
                  (posY+100) * view.getSize().y/200);
    }

    /*
     * Returns the sf::Text.
     */
    sf::Text& CustomText::getText () {
        return text;
    }

}