#include <iostream>
#include "BattleScene.hpp"
#include "LoginState.hpp"
#include "BanState.hpp"


/*
 * Login state, when the player can log into the match.
 */

namespace client {

    void LoginState::temporaryRequest() {
        battleScene->transitionTo(std::make_shared<BanState>());
    }

    std::string LoginState::getStateName() {
        return ResourceHolder::getInstance().getStateName(Login_State);
    }
}