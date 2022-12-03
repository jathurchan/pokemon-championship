#include "GameScene.hpp"

namespace render {

    void GameScene::initWindow() {
        Json::Value configInfo = utilities::JsonParser::readJsonString(configFile)["window"];
        fullscreen = configInfo["fullscreen"].asBool();
        if (fullscreen)
            window.create(sf::VideoMode::getDesktopMode(), configInfo["name"].asString(), sf::Style::Fullscreen);
        else
            window.create(sf::VideoMode(configInfo["width"].asInt(), configInfo["height"].asInt()), configInfo["name"].asString(), sf::Style::Default);
    }

    sf::RenderWindow *GameScene::getWindow() {
        return &window;
    }
}

//Unordered map de pointeurs de fonctions pour les bouttons
//Map pour les fatory