#include <iostream>
#include <random>
#include "GameScene.hpp"

namespace render {

    Json::Value* GameScene::configInfo = utilities::JsonParser::getConfigInfo();

    void GameScene::initWindow() {
        if ((*configInfo)["window"]["fullscreen"].asBool()) {
            window.create(sf::VideoMode::getDesktopMode(), (*configInfo)["window"]["name"].asString(),
                          sf::Style::Fullscreen);
            (*configInfo)["window"]["fullscreen"] = true;
        }
        else {
            window.create(
                    sf::VideoMode((*configInfo)["window"]["width"].asInt(), (*configInfo)["window"]["height"].asInt()),
                    (*configInfo)["window"]["name"].asString(), sf::Style::Default);
            (*configInfo)["window"]["fullscreen"] = false;
        }
        view = window.getDefaultView();
        ResourceHolder::getInstance().loadStateAssets(view);
    }

    void GameScene::playMusic() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(1, 6);
        if (!music.openFromFile("res/music/battleMusic" + std::to_string(distrib(gen)) + ".wav"))
            std::cout << "Failed to load music" << std::endl;
        music.setLoop(true);
        music.setVolume((*configInfo)["volume"].asFloat());
        music.play();
    }

    void GameScene::updateView(sf::Event event) {
        float windowRatio = (float) event.size.width / (float) event.size.height;
        float viewRatio = (*configInfo)["window"]["ratioX"].asFloat() /
                          (*configInfo)["window"]["ratioY"].asFloat();
        float sizeX = 1, sizeY = 1, posX = 0, posY = 0;
        if (windowRatio > viewRatio) {
            sizeX = viewRatio / windowRatio, posX = (1 - sizeX) / 2;
        } else {
            sizeY = windowRatio / viewRatio, posY = (1 - sizeY) / 2;
        }
        view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));
        window.setView(view);
    }

    void GameScene::changeScreenMode() {
        if (!(*configInfo)["window"]["fullscreen"].asBool()) {
            window.create(sf::VideoMode::getDesktopMode(), (*configInfo)["window"]["name"].asString(),
                          sf::Style::Fullscreen);
            (*configInfo)["window"]["fullscreen"] = true;
        }
        else {
            window.create(
                    sf::VideoMode((*configInfo)["window"]["width"].asInt(), (*configInfo)["window"]["height"].asInt()),
                    (*configInfo)["window"]["name"].asString(), sf::Style::Default);
            (*configInfo)["window"]["fullscreen"] = false;
        }
    }

    sf::RenderWindow *GameScene::getWindow() {
        return &window;
    }
}