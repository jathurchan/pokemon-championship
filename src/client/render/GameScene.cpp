#include <iostream>
#include <random>
#include "GameScene.hpp"

namespace render {

    void GameScene::initWindow() {
        configInfo = utilities::JsonParser::readJsonString(configFile)["window"];
        fullscreen = configInfo["fullscreen"].asBool();
        if (fullscreen)
            window.create(sf::VideoMode::getDesktopMode(), configInfo["name"].asString(), sf::Style::Fullscreen);
        else
            window.create(sf::VideoMode(configInfo["width"].asInt(), configInfo["height"].asInt()), configInfo["name"].asString(), sf::Style::Default);
        view=window.getDefaultView();
    }

    void GameScene::playMusic() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(1,6);
        if (!music.openFromFile("res/music/battleMusic" + std::to_string(distrib(gen)) + ".wav"))
            std::cout << "Failed to load music" << std::endl;
        music.setLoop(true);
        music.play();
    }

    void GameScene::updateView(sf::Event event) {
        float windowRatio = (float) event.size.width / (float) event.size.height;
        float viewRatio = utilities::JsonParser::readJsonString("res/config.json")["window"]["ratioX"].asFloat()/
                          utilities::JsonParser::readJsonString("res/config.json")["window"]["ratioY"].asFloat();
        float sizeX = 1, sizeY = 1, posX = 0, posY = 0;
        if (windowRatio > viewRatio) {
            sizeX = viewRatio/windowRatio, posX = (1-sizeX)/2;
        } else {
            sizeY = windowRatio/viewRatio, posY = (1-sizeY)/2;
        }
        view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));
        window.setView(view);
    }

    void GameScene::changeScreenMode() {
        if (!fullscreen)
            window.create(sf::VideoMode::getDesktopMode(), configInfo["name"].asString(), sf::Style::Fullscreen);
        else
            window.create(sf::VideoMode(configInfo["width"].asInt(), configInfo["height"].asInt()), configInfo["name"].asString(), sf::Style::Default);
        fullscreen = !fullscreen;
    }

    sf::RenderWindow *GameScene::getWindow() {
        return &window;
    }
}