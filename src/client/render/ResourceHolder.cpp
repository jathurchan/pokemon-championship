#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourceHolder.hpp"
#define stringify(name) #name

/*
 * Contains the textures, images and fonts which were loaded by the render, each one of them is stored only once.
 * Configures as a singleton as only one unique instance is wanted.
 */

namespace render {

    /* Il faudrait mettre ca dans le hpp mais comment faire avec dia ?
    ResourceHolder(const ResourceHolder&) = delete;
    void operator=(const ResourceHolder &) = delete;
     */


    /*
     * Private constructor
     */
    ResourceHolder::ResourceHolder() {
        assetsFile = "res/" + (*utilities::JsonParser::getConfigInfo())["jsonFiles"]["stateAssets"].asString();
    };

    /*
     * Returns the single instance of the class.
     */
    ResourceHolder &ResourceHolder::getInstance() {
        static ResourceHolder instance;
        return instance;
    }

    void ResourceHolder::loadStateAssets(sf::View view) {
        Json::Value stateAssetsInfo = utilities::JsonParser::readJsonString(assetsFile);
        for (const Json::Value &stateAssets: stateAssetsInfo) {
            if (stateAssets != Json::nullValue) {
                int index = stateAssets["stateIndex"].asInt();
                stateAssetsMap[index] = std::make_pair(std::vector<CustomText>{}, std::vector<CustomSprite>{});
                for (const Json::Value &stateText: stateAssets["text"])
                    loadStateText(stateText, index, view);
                for (const Json::Value &stateSprite: stateAssets["sprite"])
                    loadStateSprite(stateSprite, index, view);
                for (const Json::Value &stateButton: stateAssets["button"])
                    loadStateButton(stateButton, index, view);
            }
        }
    }

    void ResourceHolder::loadStateText(Json::Value stateText, int index, sf::View view) {
        stateAssetsMap[index].first.emplace(stateAssetsMap[index].first.end(),
                                            stateText["fontName"].asString(),
                                            stateText["string"].asString(),
                                            sf::Text::Style(stateText["style"].asInt()));
        stateAssetsMap[index].first.back().setCharacterSize(view,
                                                            stateText["characterSize"].asInt());
        stateAssetsMap[index].first.back().setXOrigin(stateText["origin"]["originX"].asFloat());
        stateAssetsMap[index].first.back().setPosition(view,
                                                       stateText["position"]["ratioX"].asFloat(),
                                                       stateText["position"]["ratioY"].asFloat());
        stateAssetsMap[index].first.back().setColor((char) stateText["color"]["red"].asInt(),
                                                    (char) stateText["color"]["green"].asInt(),
                                                    (char) stateText["color"]["blue"].asInt(),
                                                    (char) stateText["color"]["alpha"].asInt());
    }

    void ResourceHolder::loadStateSprite(Json::Value stateSprite, int index, sf::View view) {
        stateAssetsMap[index].second.emplace(stateAssetsMap[index].second.end(),
                                             stateSprite["imageName"].asString(),
                                             stateSprite["smooth"].asBool());
        stateAssetsMap[index].second.back().setScale(view,
                                                     stateSprite["scale"]["ratioOnX"].asBool(),
                                                     stateSprite["scale"]["percent"].asFloat(),
                                                     stateSprite["scale"]["invertedX"].asBool(),
                                                     stateSprite["scale"]["invertedY"].asBool());
        stateAssetsMap[index].second.back().setOrigin(stateSprite["origin"]["originX"].asFloat(),
                                                      stateSprite["origin"]["originY"].asFloat());
        stateAssetsMap[index].second.back().setPosition(view,
                                                        stateSprite["position"]["posX"].asFloat(),
                                                        stateSprite["position"]["posY"].asFloat());
    }

    void ResourceHolder::loadStateButton(Json::Value stateButton, int index, sf::View view) {
        loadStateSprite(stateButton["sprite"], index, view);
        stateButtonsMap[index].emplace(stateButtonsMap[index].end(),
                                       &stateAssetsMap[index].second.back(),
                                       stateButton["activeAction"].asString(),
                                       stateButton["holdAction"].asString(),
                                       stateButton["unactiveAction"].asString());
    }

    /*
     * Return the sf::Image identified by the name argument.
     * If the image described is not already loaded in memory, load it before returning it.
     */
    sf::Image* ResourceHolder::getImage(const std::string& name) {

        auto imagePair = images.find(name);
        if (imagePair != images.end()) {
            return &(imagePair->second);
        }
        else {
            sf::Image& image = images[name];
            if (!image.loadFromFile("res/asset/" + name + ".png")) {
                std::cout << "Failed to load " + name + " image" << std::endl;
            }
            return &images[name];
        }
    }

    /*
     * Return the sf::Texture identified by the name argument.
     * If the texture described is not already loaded in memory, load it before returning it.
     */
    sf::Texture* ResourceHolder::getTexture(const std::string& name) {

        auto texturePair = textures.find(name);
        if (texturePair != textures.end()) {
            return &(texturePair->second);
        }
        else {
            sf::Texture& texture = textures[name];
            if(!texture.loadFromImage(*getImage(name))) {
                std::cout << "Failed to load " + name + " texture" << std::endl;
            }
            return &textures[name];
        }
    }

    /*
     * Returns the sf::Font identified by the name argument.
     * If the font described is not already loaded in memory, loads it before returning it.
     */
    sf::Font* ResourceHolder::getFont(const std::string& name) {

        auto fontPair = fonts.find(name);
        if (fontPair != fonts.end()) {
            return &(fontPair->second);
        }
        else {
            sf::Font& font = fonts[name];
            if(!font.loadFromFile("res/font/" + name + ".ttf")) {
                std::cout << "Failed to load " + name + " font" << std::endl;
            }
            return &fonts[name];
        }
    }

    std::vector<CustomText> *ResourceHolder::getStateTextVector(int state) {
        return &stateAssetsMap[state].first;
    }

    std::vector<CustomSprite> *ResourceHolder::getStateSpriteVector(int state) {
        return &stateAssetsMap[state].second;
    }

    std::vector<CustomButton> *ResourceHolder::getStateButtonVector(int state) {
        return &stateButtonsMap[state];
    }
}