#include <iostream>
#include "EventHandler.hpp"

namespace client {

    const std::unordered_map<int, std::function<void(ClientEngine &, sf::Event)>> EventHandler::eventsMap =
            {{0,  &ClientEngine::windowClose},
             {1,  &ClientEngine::updateView},
             {6,  &ClientEngine::releasedKeysAction},
             {9,  &ClientEngine::pressedButtonsAction},
             {10, &ClientEngine::releasedButtonsAction}};

    const std::unordered_map<std::string, std::function<void(ClientEngine &, sf::Event)>> EventHandler::actionsMap =
            {{"closeWindow",          &ClientEngine::windowClose},
             {"setOrUnsetFullscreen", &ClientEngine::changeScreenMode},
             {"testTransition",       &ClientEngine::testTransition}};


    EventHandler::EventHandler() {
        keysFile = "res/" + (*utilities::JsonParser::getConfigInfo())["jsonFiles"]["supportedKeys"].asString();
        initKeysMap();
    }

    EventHandler::~EventHandler() = default;

    void EventHandler::initKeysMap() {
        Json::Value supportedKeysInfo = utilities::JsonParser::readJsonString(keysFile);
        for (const Json::Value &supportedKeysPerState: supportedKeysInfo) {
            auto index = StatesName(supportedKeysPerState["stateIndex"].asInt());
            keysMap[index] = std::unordered_map<int, std::function<void(ClientEngine&, sf::Event)>>{};
            for (const Json::Value& supportedKeys : supportedKeysPerState["keys"])
                keysMap[index].emplace((int) sf::Keyboard::Key(supportedKeys["keyIndex"].asInt()), actionsMap.at(supportedKeys["function"].asString()));
        }
    }

    void EventHandler::addToActiveButtons(render::CustomButton* buttonPtr) {
        activeButtons.push_back(buttonPtr);
    }

    void EventHandler::updateActiveButtons() {
        auto buttonIt = activeButtons.begin();
        while (buttonIt != activeButtons.end()) {
            (*buttonIt)->renderHold(clk.getElapsedTime());
            if (!(*buttonIt)->isActive())
                activeButtons.erase(buttonIt);
            else
                buttonIt++;
        }
    }

    const std::unordered_map<int, std::function<void(ClientEngine &, sf::Event)>>* EventHandler::getEventsMap() {
        return &eventsMap;
    }

    const std::unordered_map<std::string, std::function<void(ClientEngine &, sf::Event)>>* EventHandler::getActionsMap() {
        return &actionsMap;
    }

    std::unordered_map<StatesName, std::unordered_map<int, std::function<void(ClientEngine &, sf::Event)>>>* EventHandler::getKeysMap() {
        return &keysMap;
    }

    sf::Time EventHandler::getTime() {
        return clk.getElapsedTime();
    }

    std::vector<render::CustomButton *>* EventHandler::getActiveButtons() {
        return &activeButtons;
    }
}