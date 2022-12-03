#include <iostream>
#include "ClientEngine.hpp"
#include "LoginState.hpp"

namespace client {

    void ClientEngine::run() {

        std::function<void(ClientEngine&, sf::Event)> func = &ClientEngine::windowClose;

        scene.initWindow();
        scene.playMusic();

        while (scene.getWindow()->isOpen()) {
            sf::Event event;
            while (scene.getWindow()->pollEvent(event)) {
                if (EventHandler::getInstance().getMap()->find(event.type) ==
                    EventHandler::getInstance().getMap()->end())
                    break;
                else {
                    std::cout << EventHandler::getInstance().getMap()->at(event.type) << std::endl;
                    func(*this, event);
                }
            }
        }
    }

    void ClientEngine::windowClose(sf::Event event) {
        scene.getWindow()->close();
    }
}