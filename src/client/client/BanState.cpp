#include <iostream>
#include "BattleScene.hpp"
#include "SelectState.hpp"
#include "BanState.hpp"

/*
 * Turn Result state, when the player can ban a fakemon from the ennemy team.
 */

namespace client {

    /*
     * Test request which change the current state of the scene to the Select State.
     */
    void BanState::temporaryRequest() {
        battleScene->transitionTo(std::make_shared<SelectState>());
    }

    std::string BanState::getStateName() {
        return ResourceHolder::getInstance().getStateName(Ban_State);
    }
}