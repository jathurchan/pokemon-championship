#include <iostream>
#include "BattleScene.hpp"
#include "WaitState.hpp"
#include "SwitchState.hpp"

namespace client {

    void SwitchState::generateInterface() {

        auto &spriteVector = this->battleScene->getSpriteVector();
        auto &spriteText = this->battleScene->getTextVector();
        auto &view = this->battleScene->getView();
    }

    void SwitchState::temporaryRequest() {
        battleScene->transitionTo(std::make_shared<WaitState>());
    }
}