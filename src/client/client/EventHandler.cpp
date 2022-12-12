#include <iostream>
#include "EventHandler.hpp"

namespace client {

    EventHandler::EventHandler() {
        initEventMap();
        initSupportedReleasedKeysMap();
    }

    EventHandler::~EventHandler() = default;

    void EventHandler::initEventMap() {
        eventsMap[0] = &ClientEngine::windowClose;
        eventsMap[1] = &ClientEngine::updateView;
        eventsMap[6] = &ClientEngine::releasedKeysAction;
        eventsMap[10] = &ClientEngine::releasedButtonsAction;
    }

    void EventHandler::initSupportedReleasedKeysMap() {
        supportedReleasedKeysMap[36] = &ClientEngine::windowClose;
        supportedReleasedKeysMap[58] = &ClientEngine::changeScreenMode;
    }

    std::unordered_map<int, std::function<void(ClientEngine&, sf::Event)>>* EventHandler::getEventsMap() {
        return &eventsMap;
    }

    std::unordered_map<int, std::function<void(ClientEngine &, sf::Event)>>* EventHandler::getSupportedReleasedKeysMap() {
        return &supportedReleasedKeysMap;
    }
}