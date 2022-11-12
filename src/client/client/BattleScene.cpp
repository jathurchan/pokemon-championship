#include "BattleScene.hpp"
#include <iostream>
#include <client.hpp>
#include <SFML/Graphics.hpp>
#include <forward_list>
#include <random>
#include <utility>
#include <list>


namespace client {

    BattleScene::BattleScene(std::shared_ptr<State> state) {
        this->state = nullptr;
        createWindow();
        transitionTo(std::move(state));

        while (window.isOpen()) {
            windowLoop();
        }
    }

    void BattleScene::createWindow() {

        fullScreen = true;
        window.create(sf::VideoMode::getDesktopMode(), "Fakemon_Projekt", sf::Style::Fullscreen);
        view = window.getDefaultView();

        generateDefaultInterface();
    }

    void BattleScene::windowLoop() {

        window.clear(sf::Color::Black);
        window.setView(view);

        for (auto iS : spriteVector) {
            window.draw(iS.getSprite());
        }
        for (auto iT : textVector) {
            window.draw(iT.getText());
        }

        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    view = updateView(event.size.width, event.size.height);
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                        case sf::Keyboard::Enter:
                            if (fullScreen) {
                                window.create(sf::VideoMode(960, 540), "Fakemon_Projekt");
                            } else {
                                window.create(sf::VideoMode::getDesktopMode(), "Fakemon_Projekt",
                                              sf::Style::Fullscreen);
                            }
                            fullScreen = !fullScreen;
                            break;
                        case sf::Keyboard::A:
                            temporaryRequestCall();
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
    }

    sf::View BattleScene::updateView(int windowWidth, int windowHeight) {

        float windowRatio = (float) windowWidth / (float) windowHeight;
        float viewRatio = 16.f / 9.f;
        float sizeX = 1, sizeY = 1;
        float posX = 0, posY = 0;

        if (windowRatio > viewRatio) {
            sizeX = viewRatio / windowRatio;
            posX = (1 - sizeX) / 2;
        } else {
            sizeY = windowRatio / viewRatio;
            posY = (1 - sizeY) / 2;
        }

        view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));

        return view;
    }

    void BattleScene::generateDefaultInterface() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(1,6);
        spriteVector.emplace_back(CustomSprite ("arenamap" + std::to_string(distrib(gen)), false));
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 2, 2);
        spriteVector.back().setScale(view, 1);

        spriteVector.emplace_back(CustomSprite ("optionButton", true));
        spriteVector.back().setOrigin(1, 0);
        spriteVector.back().setPosition(view, 1.008, 70);
        spriteVector.back().setScale(view, 15);

        numberStaticSprite = spriteVector.size();
        numberStaticText = textVector.size();
    }

    std::vector<CustomSprite>& BattleScene::getSpriteVector() {
        return spriteVector;
    }

    std::vector<CustomText>& BattleScene::getTextVector() {
        return textVector;
    }

    void BattleScene::resetDrawVectors() {
        spriteVector.resize(numberStaticSprite);
        textVector.resize(numberStaticText);
    }


    sf::View& BattleScene::getView() {
        return view;
    }

    void BattleScene::transitionTo(std::shared_ptr<State> state) {
        this->state = std::move(state);
        this->state->setScene(this);
        this->state->initializeState();
    }

    void BattleScene::temporaryRequestCall() {
        state->temporaryRequest();
    }
}
