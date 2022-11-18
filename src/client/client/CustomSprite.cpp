#include "CustomSprite.hpp"
#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"

/*
 * Creates an instance of sf::Sprite and implement different method to interact with it.
 */

namespace client {

    /*
     * Default constructor.
     * Creates an empty CustomSprite.
     */
    CustomSprite::CustomSprite() = default;

    /*
     * Constructs the CustomSprite.
     * Instantiates a new sf::Sprite by loading its texture from the Resource Holder.
     * Enable the smooth filter of the texture depending on the smooth argument. Disables it by default.
     */
    CustomSprite::CustomSprite(std::string fileName, bool smooth) {

        imagePtr = ResourceHolder::getInstance().getImage(fileName);
        texturePtr = ResourceHolder::getInstance().getTexture(fileName);
        texturePtr->setSmooth(smooth);
        sprite.setTexture(*texturePtr);
    }

    /*
     * Sets the scale of the sprite as a ratio of the view size on Y.
     * Can flip the image on X and Y or crops it on X as a ratio of the full size.
     */
    void CustomSprite::setScale(sf::View& view, float ratio, bool invertedX, bool invertedY, float ratioCropX) {
        float x,y;
        if (invertedX)
            x = -(float) view.getSize().y / (float) texturePtr->getSize().y/ratio*ratioCropX;
        else
            x = (float) view.getSize().y / (float) texturePtr->getSize().y/ratio*ratioCropX;
        if (invertedY)
            y = -(float) view.getSize().y / (float) texturePtr->getSize().y/ratio;
        else
            y = (float) view.getSize().y / (float) texturePtr->getSize().y/ratio;

        sprite.setScale(x,y);
    }

    /*
     * Sets the position of the sprite as a ratio of the view size on X and Y.
     * Using 0 set its position to 0 on the axis.
     */
    void CustomSprite::setPosition(sf::View& view, float ratioX, float ratioY) {
        float x=0, y=0;
        if (ratioX!=0)
            x=view.getSize().x/ratioX;
        if (ratioY!=0)
            y=view.getSize().y/ratioY;
        sprite.setPosition(x,y);
    }

    /*
     * Sets the origin of the sprite as a ratio of the sprite size.
     * Using 0 set its position to 0 on the axis.
     */
    void CustomSprite::setOrigin(float ratioX, float ratioY) {
        float x=0,y=0;
        if (ratioX!=0)
            x = (float) texturePtr->getSize().x/ratioX;
        if (ratioY!=0)
            y = (float) texturePtr->getSize().y/ratioY;
        sprite.setOrigin(x,y);
    }

    /*
     * Checks whether the position is inside the visible part of the sprite.
     */
    bool CustomSprite::isInSprite(sf::Vector2f position) {
        if (sprite.getGlobalBounds().contains(position.x, position.y) &&
            imagePtr->getPixel((int) (sprite.getOrigin().x - (sprite.getPosition().x-position.x)/sprite.getScale().x),
                               (int) (sprite.getOrigin().y - (sprite.getPosition().y-position.y)/sprite.getScale().y)).a != 0)
            return true;
        else
            return false;
    }

    /*
     * Returns the sprite.
     */
    sf::Sprite& CustomSprite::getSprite() {
        return sprite;
    }

    /*
     * Returns the texture of the sprite.
     */
    sf::Texture* CustomSprite::getTexture() {
        return texturePtr;
    }

    /*
     * Returns the image of the sprite.
     */
    sf::Image* CustomSprite::getImage() {
        return imagePtr;
    }
}