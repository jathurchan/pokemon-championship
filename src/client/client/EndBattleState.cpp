#include <iostream>
#include "BattleScene.hpp"
#include "EndBattleState.hpp"
#include "ChoiceState.hpp"

namespace client {

    void EndBattleState::generateInterface() {

        std::string result = "victory";
        //std::string result = "defeat";

        auto &spriteVector = this->battleScene->getSpriteVector();
        auto &spriteText = this->battleScene->getTextVector();
        auto &view = this->battleScene->getView();

        spriteVector.emplace_back(result + "Banner1", true);
        spriteVector.back().setOrigin(2, 1);
        spriteVector.back().setPosition(view, 2, 1);
        spriteVector.back().setScale(view, 1.35);

        spriteVector.emplace_back(result + "Banner2", true);
        spriteVector.back().setOrigin(0, 1);
        spriteVector.back().setPosition(view, 40, 1);
        spriteVector.back().setScale(view, 1.1, false, false);

        spriteVector.emplace_back(result + "Banner2", true);
        spriteVector.back().setOrigin(0, 1);
        spriteVector.back().setPosition(view, 1.025, 1);
        spriteVector.back().setScale(view, 1.1, true, false);

        spriteVector.emplace_back(result + "Text", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 9.2, 1.91);
        spriteVector.back().setScale(view, 1.5);

        spriteVector.emplace_back(result + "Text", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 1.11, 1.91);
        spriteVector.back().setScale(view, 1.5);

    }

    void EndBattleState::temporaryRequest() {
        battleScene->transitionTo(std::make_shared<ChoiceState>());
    }
}