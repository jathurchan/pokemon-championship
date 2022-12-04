#include <iostream>
#include "ClientEngine.hpp"
#include "render.hpp"

namespace client {

    //Pour les test je peux faire que chaque event a un nom -> problème : dia, ENCORE
    //vu que le nombre de caractère est limité

    void ClientEngine::run() {

        scene.initWindow();
        scene.playMusic();

        while (scene.getWindow()->isOpen()) {

            scene.getWindow()->clear();
            scene.getWindow()->display();

            sf::Event event{};
            while (scene.getWindow()->pollEvent(event)) {
                if (EventHandler::getInstance().getEventMap()->find(event.type) ==
                    EventHandler::getInstance().getEventMap()->end())
                    break;
                else {
                    EventHandler::getInstance().getEventMap()->find(event.type)->second(*this, event);
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
}