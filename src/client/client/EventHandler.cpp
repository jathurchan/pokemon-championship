#include "EventHandler.hpp"

namespace client {

    EventHandler::EventHandler() {
        initEventMap();
    }

    EventHandler& EventHandler::getInstance() {
        static EventHandler instance;
        return instance;
    }

    std::unordered_map<int, std::function<void(ClientEngine&, sf::Event)>>* EventHandler::getEventMap() {
        return &eventMap;
    }

    void EventHandler::initEventMap() {
        eventMap[0] = &ClientEngine::windowClose;
        eventMap[1] = &ClientEngine::updateView;
    }
}