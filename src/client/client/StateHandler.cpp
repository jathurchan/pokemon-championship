#include <iostream>
#include "StateHandler.hpp"

namespace client {

    std::unordered_map<StatesName, std::unordered_map<std::string, render::CustomButton*>> StateHandler::statesMap =
            {{Login_State,           {{"testTransition", nullptr}, {"saveUsername", nullptr}, {"saveLinkCode", nullptr}}},
             {Team_Choice_State,     {}},
             {Creature_Ban_State,    {}},
             {Creature_Choice_State, {}},
             {Action_Choice_State,   {}},
             {Move_Choice_State,     {}},
             {Creature_Switch_State, {}},
             {Wait_State,            {}},
             {Turn_Result_State,     {}},
             {End_Battle_State,      {}}};

    StateHandler::StateHandler(StatesName currentState) {
        this->currentState = currentState;
    }

    void StateHandler::initStatesMap() {
        for (auto &stateButtonMap: statesMap) {
            for (auto &renderButton: *render::ResourceHolder::getInstance().getStateButtonVector(stateButtonMap.first)) {
                if (stateButtonMap.second.find(renderButton->getEngineFunction()) != stateButtonMap.second.end()) {
                    stateButtonMap.second[renderButton->getEngineFunction()] = &*renderButton;
                }
            }
            for (const auto& buttonPair: stateButtonMap.second) {
                if (buttonPair.second == nullptr)
                    std::cout << "Error : no " + buttonPair.first + "function loaded" << std::endl;
            }
        }
    }

    void StateHandler::transitionToState(StatesName state) {
        currentState = state;
    }

    StatesName StateHandler::getCurrentState() {
        return currentState;
    }

    std::unordered_map<std::string, render::CustomButton *> *StateHandler::getStateMap(StatesName state) {
        return &statesMap[state];
    }
}