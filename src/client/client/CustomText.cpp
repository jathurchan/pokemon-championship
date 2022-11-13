#include "CustomText.hpp"
#include <iostream>
#include "ResourceHolder.hpp"

namespace client {

    CustomText::CustomText() = default;

    CustomText::CustomText(std::string fontName, std::string textString, sf::Text::Style style) {
        text.setFont(ResourceHolder::getInstance().getFont(fontName));
        text.setString(textString);
        text.setStyle(style);
    }

    void CustomText::setCharacterSize (sf::View view, float ratio) {
        if (ratio!=0)
            text.setCharacterSize(view.getSize().x/ratio);
    }

    void CustomText::setPosition (sf::View& view, float ratioX, float ratioY) {
        float x=0, y=0;
        if (ratioX!=0)
            x=view.getSize().x/ratioX;
        if (ratioY!=0)
            y=view.getSize().y/ratioY;
        text.setPosition(x,y);
    }

    //ALWAYS CALL AFTER setCharacterSize BECAUSE IT IS NOT JUST A SCALE FACTOR
    void CustomText::setOrigin (float ratioX, float ratioY) {
        float x=0,y=0;
        if (ratioX!=0)
            x=text.getLocalBounds().width/ratioX;
        if (ratioY!=0)
            y=text.getLocalBounds().height/ratioY;
        text.setOrigin(text.getLocalBounds().left+x,text.getLocalBounds().top+y);
    }

    void CustomText::changeText(std::string newString) {
        text.setString(newString);
    }

    sf::Text CustomText::getText () {
        return text;
    }
}