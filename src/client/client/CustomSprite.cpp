#include "CustomSprite.hpp"
#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"


namespace client {

    CustomSprite::CustomSprite() = default;

    CustomSprite::CustomSprite(std::string fileName, bool smooth) {

        sprite.setTexture(ResourceHolder::getInstance().getTexture(fileName));
        texture = ResourceHolder::getInstance().getTexture(fileName);
        image = ResourceHolder::getInstance().getImage(fileName);

        texture.setSmooth(smooth);
    }

    void CustomSprite::setScale(sf::View& view, float ratio, bool invertedX, bool invertedY, float ratioCropX) {
        float x,y;
        if (invertedX)
            x = -(float) view.getSize().y/texture.getSize().y/ratio*ratioCropX;
        else
            x = (float) view.getSize().y/texture.getSize().y/ratio*ratioCropX;
        if (invertedY)
            y = -(float) view.getSize().y/texture.getSize().y/ratio;
        else
            y = (float) view.getSize().y/texture.getSize().y/ratio;

        sprite.setScale(x,y);
    }

    void CustomSprite::setPosition(sf::View& view, float ratioX, float ratioY) {
        float x=0, y=0;
        if (ratioX!=0)
            x=view.getSize().x/ratioX;
        if (ratioY!=0)
            y=view.getSize().y/ratioY;
        sprite.setPosition(x,y);
    }

    void CustomSprite::setOrigin(float ratioX, float ratioY) {
        float x=0,y=0;
        if (ratioX!=0)
            x=texture.getSize().x/ratioX;
        if (ratioY!=0)
            y=texture.getSize().y/ratioY;
        sprite.setOrigin(x,y);
    }

    bool CustomSprite::isInSprite(sf::Vector2f position) {
        if (sprite.getGlobalBounds().contains(position.x, position.y) &&
            image.getPixel(sprite.getOrigin().x - (sprite.getPosition().x-position.x)/sprite.getScale().x,
                           sprite.getOrigin().y - (sprite.getPosition().y-position.y)/sprite.getScale().y).a !=0)
            return true;
        else
            return false;
    }

    sf::Sprite CustomSprite::getSprite() {
        return sprite;
    }

    sf::Texture CustomSprite::getTexture() {
        return texture;
    }

    sf::Image CustomSprite::getImage() {
        return image;
    }
}