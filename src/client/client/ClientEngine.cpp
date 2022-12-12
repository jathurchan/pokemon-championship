#include <iostream>
#include <memory>
#include "ClientEngine.hpp"

namespace client {

    ClientEngine::ClientEngine() {
        eventHandler = std::make_unique<EventHandler>();
        stateHandler = std::make_unique<StateHandler>(Login_State);
    }

    void ClientEngine::run() {

        scene.initWindow();
        scene.playMusic();

        while (scene.getWindow()->isOpen()) {

            scene.display(stateHandler->getCurrentState());

            sf::Event event{};
            while (scene.getWindow()->pollEvent(event)) {
                if (eventHandler->getEventsMap()->find(event.type) ==
                    eventHandler->getEventsMap()->end())
                    break;
                else {
                    eventHandler->getEventsMap()->find(event.type)->second(*this, event);
                }
            }
        }
    }

    void ClientEngine::windowClose(sf::Event event) {
        scene.getWindow()->close();
    }

    void ClientEngine::updateView(sf::Event event) {
        scene.updateView(event);
    }

    void ClientEngine::changeScreenMode(sf::Event event) {
        scene.changeScreenMode();
    }

    void ClientEngine::releasedKeysAction(sf::Event event) {
        eventHandler->getSupportedReleasedKeysMap()->find(event.key.code)->second(*this, event);
    }

    void ClientEngine::releasedButtonsAction(sf::Event event) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i position(event.mouseButton.x, event.mouseButton.y);
            for (auto button: *render::ResourceHolder::getInstance().getStateButtonVector(stateHandler->getCurrentState())) {
                if (button.isInSprite(scene.getWindow()->mapPixelToCoords(position, scene.getWindow()->getView()))) {
                    button.action();
                }
            }
        }
    }
}