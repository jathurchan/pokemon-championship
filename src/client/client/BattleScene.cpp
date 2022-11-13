#include "BattleScene.hpp"
#include <iostream>
#include <client.hpp>
#include <SFML/Graphics.hpp>
#include <forward_list>
#include <random>
#include <utility>
#include <list>

/*
 * Creates and manages the window in which the game is displayed.
 */

namespace client {

    /*
     * Construct the scene and initialized its state.
     */
    BattleScene::BattleScene(std::shared_ptr<State> state) {
        this->state = nullptr;
        createWindow();
        transitionTo(std::move(state));

        while (window.isOpen()) {
            windowLoop();
        }
    }

    /*
     * Creates a new window on fullScreen and sets its view.
     */
    void BattleScene::createWindow() {

        fullScreen = true;
        window.create(sf::VideoMode::getDesktopMode(), "Fakemon_Projekt", sf::Style::Fullscreen);
        view = window.getDefaultView();
    }

    /*
     *
     */
    void BattleScene::windowLoop() {

        window.clear(sf::Color::Black);
        window.setView(view);

        for (auto iS : baseSpriteVector) {
            window.draw(iS.getSprite());
        }
        for (auto iT : baseTextVector) {
            window.draw(iT.getText());
        }
        for (auto iS : stateSpriteVector) {
            window.draw(iS.getSprite());
        }
        for (auto iT : stateTextVector) {
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

    /*
     * up
     */
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
        baseSpriteVector.emplace_back(CustomSprite ("arenamap" + std::to_string(distrib(gen)), false));
        baseSpriteVector.back().setOrigin(2, 2);
        baseSpriteVector.back().setPosition(view, 2, 2);
        baseSpriteVector.back().setScale(view, 1);

        baseSpriteVector.emplace_back(CustomSprite ("optionButton", true));
        baseSpriteVector.back().setOrigin(1, 0);
        baseSpriteVector.back().setPosition(view, 1.008, 70);
        baseSpriteVector.back().setScale(view, 15);

        numberBaseSprite = stateSpriteVector.size();
        numberBaseText = stateTextVector.size();
    }

    void BattleScene::generateFakemonInterface() {

        baseSpriteVector.emplace_back(CustomSprite ("Unex", false));
        baseSpriteVector.back().setOrigin(0, 1);
        baseSpriteVector.back().setPosition(view, 2.818, 1.01);
        baseSpriteVector.back().setScale(view, 1.7, true, false);

        baseSpriteVector.emplace_back(CustomSprite ("Aevituu", false));
        baseSpriteVector.back().setOrigin(0, 1);
        baseSpriteVector.back().setPosition(view, 1.55, 1.01);
        baseSpriteVector.back().setScale(view, 1.7, false, false);

        baseSpriteVector.emplace_back(CustomSprite ("fakemonInfo", true));
        baseSpriteVector.back().setOrigin(0, 2);
        baseSpriteVector.back().setPosition(view, 0, 3.5);
        baseSpriteVector.back().setScale(view, 12, false, false);

        baseSpriteVector.emplace_back(CustomSprite ("fakemonInfo", true));
        baseSpriteVector.back().setOrigin(0, 2);
        baseSpriteVector.back().setPosition(view, 1, 4.2);
        baseSpriteVector.back().setScale(view, 12, true, false);

        baseTextVector.emplace_back(CustomText("textFont", "Unex"));
        baseTextVector.back().setOrigin(2, 2);
        baseTextVector.back().setPosition(view, 3.805, 3.7);
        baseTextVector.back().setCharacterSize(view, 80);

        baseTextVector.emplace_back(CustomText("textFont", "Aevituu"));
        baseTextVector.back().setOrigin(2, 2);
        baseTextVector.back().setPosition(view, 1.356, 4.5);
        baseTextVector.back().setCharacterSize(view, 80);

        baseSpriteVector.emplace_back(CustomSprite ("healthBar100", true));
        baseSpriteVector.back().setOrigin(0, 2);
        baseSpriteVector.back().setPosition(view, 5.362, 3.3);
        baseSpriteVector.back().setScale(view, 53);

        baseSpriteVector.emplace_back(CustomSprite ("healthBar75", true));
        baseSpriteVector.back().setOrigin(0, 2);
        baseSpriteVector.back().setPosition(view, 1.512, 3.95);
        baseSpriteVector.back().setScale(view, 53, false, false, 0.75);

        baseSpriteVector.emplace_back(CustomSprite ("healthBarFont", true));
        baseSpriteVector.back().setOrigin(2, 2);
        baseSpriteVector.back().setPosition(view, 3.805, 3.3);
        baseSpriteVector.back().setScale(view, 64);

        baseSpriteVector.emplace_back(CustomSprite ("healthBarFont", true));
        baseSpriteVector.back().setOrigin(2, 2);
        baseSpriteVector.back().setPosition(view, 1.356, 3.95);
        baseSpriteVector.back().setScale(view, 64);
    }

    std::vector<CustomSprite>& BattleScene::getStateSpriteVector() {
        return stateSpriteVector;
    }

    std::vector<CustomText>& BattleScene::getStateTextVector() {
        return stateTextVector;
    }

    void BattleScene::resetStateDrawVectors() {
        stateSpriteVector.resize(0);
        stateTextVector.resize(0);
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
