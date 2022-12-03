#include "ClientEngine.hpp"

namespace client {

    void ClientEngine::run() {
        scene.initWindow();

        while (scene.getWindow()->isOpen()) {
            sf::Event event;
            while (scene.getWindow()->pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                        scene.getWindow()->close();
                        break;
                    case sf::Event::KeyPressed:
                        scene.getWindow()->close();
                        break;
                    default:
                        break;
                }
            }
        }
    }
}