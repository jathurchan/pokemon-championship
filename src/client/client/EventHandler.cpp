#include <iostream>
#include "EventHandler.hpp"

namespace client {

    const std::unordered_map<int, std::function<void(ClientEngine &, sf::Event)>> EventHandler::eventsMap =
            {{0,  &ClientEngine::windowClose},
             {1,  &ClientEngine::updateView},
             {6,  &ClientEngine::releasedKeysAction},
             {10, &ClientEngine::releasedButtonsAction}};

    const std::unordered_map<std::string, std::function<void(ClientEngine &, sf::Event)>> EventHandler::actionsMap =
            {{"closeWindow", &ClientEngine::windowClose},
             {"setOrUnsetFullscreen", &ClientEngine::changeScreenMode}};


    EventHandler::EventHandler() {
        keysFile = "res/" + (*utilities::JsonParser::getConfigInfo())["jsonFiles"]["supportedKeys"].asString();
        initKeysMap();
    }

    EventHandler::~EventHandler() = default;

    void EventHandler::initKeysMap() {
        Json::Value supportedKeysInfo = utilities::JsonParser::readJsonString(keysFile);
        for (const Json::Value &supportedKeysPerState: supportedKeysInfo) {
            auto index = StatesName(supportedKeysPerState["stateIndex"].asInt());
            keysMap[index] = std::vector<std::pair<int, std::function<void(ClientEngine&, sf::Event)>>>{};
            for (const Json::Value& supportedKeys : supportedKeysPerState["keys"]) {
                keysMap[index].emplace_back((int) sf::Keyboard::Key(supportedKeys["keyIndex"].asInt()), actionsMap.at(supportedKeys["keyIndex"].asString()));
            }
        }
    }

    void EventHandler::addToActiveButtons(render::CustomButton* buttonPtr) {
        activeButtons.push_back(buttonPtr);
    }

    void EventHandler::updateActiveButtons() {
        for (auto buttonPtr : activeButtons) {
            if (!buttonPtr->getStateFunctionIndex()) {

            }
        }
    }

    const std::unordered_map<int, std::function<void(ClientEngine &, sf::Event)>>* EventHandler::getEventsMap() {
        return &eventsMap;
    }

    std::unordered_map<StatesName, std::vector<std::pair<int, std::function<void(ClientEngine &, sf::Event)>>>>*
    EventHandler::getKeysMap() {
        return &keysMap;
    }
}