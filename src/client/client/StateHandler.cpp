#include <iostream>
#include "StateHandler.hpp"

namespace client {

    StateHandler::StateHandler(StatesName currentState) {
        this->currentState = currentState;
        initStatesMap();
    }

    void StateHandler::initStatesMap() {
        statesMap = {{Login_State,      functionVector{}},
                     {Choice_State,     functionVector{}},
                     {Ban_State,        functionVector{}},
                     {Select_State,     functionVector{}},
                     {Action_State,     functionVector{}},
                     {Switch_State,     functionVector{}},
                     {Wait_State,       functionVector{}},
                     {TurnResult_State, functionVector{}},
                     {EndBattle_State,  functionVector{}}};
    }

    StatesName StateHandler::getCurrentState() {
        return currentState;
    }

    void StateHandler::transitionToState(StatesName state) {

    }

}