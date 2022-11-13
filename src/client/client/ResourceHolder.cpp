#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourceHolder.hpp"

namespace client {

    /*FAUT CA DANS LE HPP COMMENT JE FAIIIIIIIIIIIIIIIS
    ResourceHolder(const ResourceHolder&) = delete;
    void operator=(const ResourceHolder &) = delete;
     */

    ResourceHolder& ResourceHolder::getInstance() {
        static ResourceHolder instance;
        return instance;
    }

    ResourceHolder::ResourceHolder() {}

    sf::Image& ResourceHolder::getImage(std::string name) {

        auto imagePair = images.find(name);
        if (imagePair != images.end()) {
            return imagePair->second;
        }
        else {
            sf::Image& image = images[name];
            if (!image.loadFromFile("res/" + name + ".png")) {
                std::cout << "Failed to load " + name + " image" << std::endl;
            }
            return images[name];
        }
    }

    sf::Texture& ResourceHolder::getTexture(std::string name) {

        auto texturePair = textures.find(name);
        if (texturePair != textures.end()) {
            return texturePair->second;
        }
        else {
            sf::Texture& texture = textures[name];
            if(!texture.loadFromImage(getImage(name))) {
                std::cout << "Failed to load " + name + " texture" << std::endl;
            }
            return textures[name];
        }
    }

    sf::Font& ResourceHolder::getFont(std::string name) {

        auto fontPair = fonts.find(name);
        if (fontPair != fonts.end()) {
            return fontPair->second;
        }
        else {
            sf::Font& font = fonts[name];
            if(!font.loadFromFile("res/" + name + ".ttf")) {
                std::cout << "Failed to load " + name + " font" << std::endl;
            }
            return fonts[name];
        }
    }
}