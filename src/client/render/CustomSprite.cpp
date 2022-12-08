#include "CustomSprite.hpp"

/*
 * Creates an instance of sf::Sprite and implement different method to interact with it.
 */

namespace render {

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
    CustomSprite::CustomSprite(const std::string& fileName, bool smooth) {
        imagePtr = ResourceHolder::getInstance().getImage(fileName);
        texturePtr = ResourceHolder::getInstance().getTexture(fileName);
        texturePtr->setSmooth(smooth);
        sprite.setTexture(*texturePtr);
    }

    void CustomSprite::changeTexture(const std::string& newFileName) {
        imagePtr = ResourceHolder::getInstance().getImage(newFileName);
        texturePtr = ResourceHolder::getInstance().getTexture(newFileName);
        sprite.setTexture(*texturePtr);
    }

    void CustomSprite::setScale(sf::View& view, bool ratioOnX, float percent, bool invertedX, bool invertedY) {
        float scaleX, scaleY, viewSize, textureSize;
        viewSize = ratioOnX ? view.getSize().x : view.getSize().y;
        textureSize = ratioOnX ? (float) texturePtr->getSize().x : (float) texturePtr->getSize().y;
        scaleX = invertedX ? -viewSize/textureSize*percent/100 : viewSize/textureSize*percent/100;
        scaleY = invertedY ? -viewSize/textureSize*percent/100 : viewSize/textureSize*percent/100;
        sprite.setScale(scaleX, scaleY);
    }

    void CustomSprite::setOrigin(float originX, float originY) {
        sprite.setOrigin((originX+10) * (float) texturePtr->getSize().x/20,
                         (originY+10) * (float) texturePtr->getSize().y/20);
    }

    void CustomSprite::setPosition(sf::View& view, float posX, float posY) {
        sprite.setPosition((posX+100) * view.getSize().x/200,
                           (posY+100) * view.getSize().y/200);
    }

    void CustomSprite::move(sf::View& view, float posX, float posY) {
        sprite.move((posX+100) * view.getSize().x/200,
                    (posY+100) * view.getSize().y/200);
    }

    /*
     * Returns the sprite.
     */
    sf::Sprite& CustomSprite::getSprite() {
        return sprite;
    }
}