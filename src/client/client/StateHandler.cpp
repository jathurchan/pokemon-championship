#include <iostream>
#include "StateHandler.hpp"

namespace client {

    std::unordered_map<StatesName, std::vector<std::function<void(StateHandler&)>>> StateHandler::statesMap =
            {{Login_State,      functionVector{}},
             {Choice_State,     functionVector{}},
             {Ban_State,        functionVector{}},
             {Select_State,     functionVector{}},
             {Action_State,     functionVector{}},
             {Switch_State,     functionVector{}},
             {Wait_State,       functionVector{}},
             {TurnResult_State, functionVector{}},
             {EndBattle_State,  functionVector{}}};

    StateHandler::StateHandler(StatesName currentState) {
        this->currentState = currentState;
    }

    StatesName StateHandler::getCurrentState() {
        return currentState;
    }

    void StateHandler::transitionToState(StatesName state) {
        currentState = state;
    }

}