#include <iostream>
#include "EventHandler.hpp"

namespace client {

    std::unordered_map<int, std::function<void(ClientEngine &, sf::Event)>> EventHandler::eventsMap =
            {{0,  &ClientEngine::windowClose},
             {1,  &ClientEngine::updateView},
             {6,  &ClientEngine::releasedKeysAction},
             {10, &ClientEngine::releasedButtonsAction}};

    std::unordered_map<std::string, std::function<void(ClientEngine &, sf::Event)>> EventHandler::actionsMap =
            {{"closeWindow", &ClientEngine::windowClose},
             {"setOrUnsetFullscreen", &ClientEngine::changeScreenMode}};


    EventHandler::EventHandler() {
        keyFile = "res/" + (*utilities::JsonParser::getConfigInfo())["jsonFiles"]["supportedKeys"].asString();
        initKeyMap();
    }

    EventHandler::~EventHandler() = default;

    void EventHandler::initKeyMap() {
        Json::Value supportedKeysInfo = utilities::JsonParser::readJsonString(keyFile);
        for (const Json::Value &supportedKeysPerState: supportedKeysInfo) {
            auto index = StatesName(supportedKeysPerState["stateIndex"].asInt());
            keysMap[index] = std::vector<std::pair<int, std::function<void(ClientEngine&, sf::Event)>>>{};
            for (const Json::Value& supportedKeys : supportedKeysPerState["keys"]) {
                keysMap[index].emplace_back((int) sf::Keyboard::Key(supportedKeys["keyIndex"].asInt()), &ClientEngine::windowClose);
            }
        }
    }

    void EventHandler::checkEvent(render::GameScene* scene, ClientEngine* engine) {
        sf::Event event{};
        while (scene->getWindow()->pollEvent(event)) {
            if (eventsMap.contains(event.type))
                break;
            else
                eventsMap.find(event.type)->second(*engine, event);
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
}