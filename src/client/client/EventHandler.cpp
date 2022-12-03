#include "EventHandler.hpp"

namespace client {

    //EventHandler::EventHandler() = default;
    EventHandler::EventHandler() {
        eventMap[0] = "Closed";
    }

    EventHandler& EventHandler::getInstance() {
        static EventHandler instance;
        return instance;
    }

    std::unordered_map<int, std::string>* EventHandler::getMap() {
        return &eventMap;
    }

    std::function<void(ClientEngine&, sf::Event)>& getFunc() {
        std::function<void(ClientEngine&, sf::Event)> func = &ClientEngine::windowClose;
        return func;
    };
}