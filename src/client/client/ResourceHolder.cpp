#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourceHolder.hpp"

/*
 * Contains the textures, images and fonts which were loaded by the render, each one of them is stored only once.
 * Configures as a singleton as only one unique instance is wanted.
 */

namespace client {

    /* Il faudrait mettre ca dans le hpp mais dia...
    ResourceHolder(const ResourceHolder&) = delete;
    void operator=(const ResourceHolder &) = delete;
     */

    /*
     * Private constructor
     */
    ResourceHolder::ResourceHolder() {}

    /*
     * Returns the single instance of the class.
     */
    ResourceHolder& ResourceHolder::getInstance() {
        static ResourceHolder instance;
        return instance;
    }

    /*
     * Return the sf::Image identified by the name argument.
     * If the image described is not already loaded in memory, load it before returning it.
     */
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

    /*
     * Return the sf::Texture identified by the name argument.
     * If the texture described is not already loaded in memory, load it before returning it.
     */
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

    /*
     * Returns the sf::Font identified by the name argument.
     * If the font described is not already loaded in memory, loads it before returning it.
     */
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