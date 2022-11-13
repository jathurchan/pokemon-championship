#include "CustomText.hpp"
#include <utility>
#include "ResourceHolder.hpp"

/*
 * Creates an instance of sf::Text and implement different method to interact with it.
 */

namespace client {

    /*
     * Default constructor.
     * Creates an empty CustomText.
     */
    CustomText::CustomText() = default;

    /*
     * Constructs the CustomText.
     * Instanciates a new sf::Text and sets its string and style, as well as its font using by loading it from the Resource Holder .
     */
    CustomText::CustomText(std::string fontName, std::string textString, sf::Text::Style style) {
        text.setFont(ResourceHolder::getInstance().getFont(std::move(fontName)));
        text.setString(textString);
        text.setStyle(style);
    }

    /*
     * Sets the character size of the text as a ratio of the view used.
     */
    //ALWAYS CALL BEFORE setPosition BECAUSE IT IS NOT JUST A SCALE FACTOR
    void CustomText::setCharacterSize (sf::View view, float ratio) {
        if (ratio!=0)
            text.setCharacterSize(view.getSize().x/ratio);
    }

    /*
     * Sets the position of the text as a ratio of the used size on X and Y.
     * Using 0 set its position to 0 on the axis.
     */
    void CustomText::setPosition (sf::View& view, float ratioX, float ratioY) {
        float x=0, y=0;
        if (ratioX!=0)
            x=view.getSize().x/ratioX;
        if (ratioY!=0)
            y=view.getSize().y/ratioY;
        text.setPosition(x,y);
    }

    /*
     * Sets the origin of the text as a ratio of the text size.
     * Using 0 set its position to 0 on the axis.
     */
    //ALWAYS CALL AFTER setCharacterSize BECAUSE IT IS NOT JUST A SCALE FACTOR
    void CustomText::setOrigin (float ratioX, float ratioY) {
        float x=0,y=0;
        if (ratioX!=0)
            x=text.getLocalBounds().width/ratioX;
        if (ratioY!=0)
            y=text.getLocalBounds().height/ratioY;
        text.setOrigin(text.getLocalBounds().left+x,text.getLocalBounds().top+y);
    }

    /*
     * Sets the color of the text using the RGBA code argument.
     */
    void CustomText::setColor(int8_t red, int8_t green, int8_t blue, int8_t alpha) {
        sf::Color color(red, green, blue, alpha);
        text.setFillColor(color);
    }

    /*
     * Changes the content of the text.
     */
    void CustomText::changeText(std::string newString) {
        text.setString(newString);
    }

    /*
     * Returns the sf::Text.
     */
    sf::Text CustomText::getText () {
        return text;
    }
}