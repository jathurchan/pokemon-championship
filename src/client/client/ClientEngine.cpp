#include <iostream>
#include "ClientEngine.hpp"
#include "render.hpp"

namespace client {

    //Pour les test je peux faire que chaque event a un nom -> problème : dia, ENCORE
    //vu que le nombre de caractère est limité

    ClientEngine::ClientEngine() {
        //Unique_ptr donc pas d'allocation dynamique
        eventHandler = std::unique_ptr<EventHandler>(new EventHandler);

    }

    void ClientEngine::run() {

        scene.initWindow();
        scene.playMusic();

        while (scene.getWindow()->isOpen()) {

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
}