#include <iostream>
#include <random>
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

    void GameScene::playMusic() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(1,6);
        if (!music.openFromFile("res/BattleMusic" + std::to_string(distrib(gen)) + ".wav"))
            std::cout << "Failed to load music" << std::endl;
        music.setLoop(true);
        music.play();
    }

    sf::RenderWindow *GameScene::getWindow() {
        return &window;
    }
}




//Unordered map de pointeurs de fonctions pour les bouttons
//Map pour les fatory