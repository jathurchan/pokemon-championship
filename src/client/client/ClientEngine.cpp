#include <memory>
#include <iostream>
#include "ClientEngine.hpp"

namespace client {

    ClientEngine::ClientEngine() {
        eventHandler = std::make_unique<EventHandler>();
        stateHandler = std::make_unique<StateHandler>(Login_State);

        scene.initWindow();
        stateHandler->initStatesMap();
        scene.playMusic();
    }

    void ClientEngine::run() {
        sf::Event event{};
        while (scene.getWindow()->isOpen()) {

            scene.display(stateHandler->getCurrentState());

            while (scene.getWindow()->pollEvent(event)) {
                if (!eventHandler->getEventsMap()->count(event.type))
                    break;
                else
                    eventHandler->getEventsMap()->find(event.type)->second(*this, event);
            }
            if (!eventHandler->getActiveButtons()->empty())
                eventHandler->updateActiveButtons();
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

    void ClientEngine::connect(sf::Event event) {
        std::cout << "Username: " + (std::string) stateHandler->getStateMap(stateHandler->getCurrentState())->at("saveUsername")->getText()->getText().getString() << std::endl;
        std::cout << "Link Code: " + (std::string) stateHandler->getStateMap(stateHandler->getCurrentState())->at("saveLinkCode")->getText()->getText().getString() << std::endl;
        stateHandler->transitionToState(StatesName::Wait_State);
    }

    void ClientEngine::releasedKeysAction(sf::Event event) {
        if (eventHandler->getKeysMap()->find(stateHandler->getCurrentState()) != eventHandler->getKeysMap()->end() &&
            eventHandler->getKeysMap()->find(stateHandler->getCurrentState())->second.count(event.key.code))
            eventHandler->getKeysMap()->find(stateHandler->getCurrentState())->second.find(event.key.code)->second(
                    *this, event);
        else if (eventHandler->getKeysMap()->find(StatesName::Unknow)->second.count(event.key.code))
            eventHandler->getKeysMap()->find(StatesName::Unknow)->second.find(event.key.code)->second(*this, event);
    }

    void ClientEngine::pressedButtonsAction(sf::Event event) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i position(event.mouseButton.x, event.mouseButton.y);
            for (const auto &button: *render::ResourceHolder::getInstance().getStateButtonVector(
                    stateHandler->getCurrentState())) {
                if (button->isInSprite(scene.getWindow()->mapPixelToCoords(position, scene.getWindow()->getView()))) {
                    if (!button->isActive() && button->getCanBePressed()) {
                        eventHandler->clearActiveButtons(button);
                        button->setActive(true);
                        button->setReleased(false);
                        button->renderActivate(eventHandler->getTime(), scene.getView());
                        eventHandler->addToActiveButtons(&*button);
                    }
                }
            }
        }
    }

    void ClientEngine::releasedButtonsAction(sf::Event event) {
        for (auto activeButton: *eventHandler->getActiveButtons())
            activeButton->setReleased(true);
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i position(event.mouseButton.x, event.mouseButton.y);
            for (auto &button: *render::ResourceHolder::getInstance().getStateButtonVector(
                    stateHandler->getCurrentState())) {
                if (button->isInSprite(scene.getWindow()->mapPixelToCoords(position, scene.getWindow()->getView()))) {
                    if (button->isActive() && button->getCanBePressed()) {
                        if (!button->getEngineFunction().empty()) {
                            if (stateHandler->getStateMap(stateHandler->getCurrentState())->count(
                                    button->getEngineFunction()) &&
                                stateHandler->getStateMap(stateHandler->getCurrentState())->find(
                                        button->getEngineFunction())->second == &*button) {
                                eventHandler->getActionsMap()->at(button->getEngineFunction())(*this, event);
                                button->setCanBePressed(false);
                            }
                        }
                    }
                }
            }
        }
    }

    void ClientEngine::textEnteredAction(sf::Event event) {
        if (eventHandler->getAllowTextEntered()) {
            for (auto button: *eventHandler->getActiveButtons()) {
                if (typeid(*button) == typeid(render::TextBox)) {
                    std::string tmp = button->getText()->getText().getString();
                    if (event.text.unicode > 32 && event.text.unicode < 168 && event.text.unicode != 124) {
                        if (button->getText()->getText().getString().getSize() <= 9) {
                            if (((std::string) button->getText()->getText().getString()).back() == '|')
                                tmp.insert(tmp.end() - 1, static_cast<char>(event.text.unicode));
                            else
                                 tmp += static_cast<char>(event.text.unicode);
                            button->getText()->changeText(tmp);
                        }
                    }
                    else if (event.text.unicode == 8) {
                        if (!((std::string) button->getText()->getText().getString()).empty() &&
                            button->getText()->getText().getString() != "|") {
                            if (((std::string) button->getText()->getText().getString()).back() == '|') {
                                tmp.erase(tmp.end() - 2);
                            } else {
                                tmp.pop_back();
                            }
                            button->getText()->changeText(tmp);
                        }
                    }
                }
            }
        }
    }

    void ClientEngine::nothingAction(sf::Event event) {}
}