#include <iostream>
#include "BattleScene.hpp"
#include "WaitState.hpp"
#include "TurnResultState.hpp"

namespace client {

    void WaitState::generateInterface() {

        auto &spriteVector = this->battleScene->getSpriteVector();
        auto &spriteText = this->battleScene->getTextVector();
        auto &view = this->battleScene->getView();

        spriteVector.emplace_back("battleInfoBack", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 2, 1.175);
        spriteVector.back().setScale(view, 3.5);

        spriteText.emplace_back("textFont", "Wait ...");
        spriteText.back().setCharacterSize(view, 50);
        spriteText.back().setOrigin(2, 2);
        spriteText.back().setPosition(view, 2, 1.175);
    }

    void WaitState::temporaryRequest() {
        battleScene->transitionTo(std::make_shared<TurnResultState>());
    }
}