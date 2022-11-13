#include <iostream>
#include "BattleScene.hpp"
#include "EndBattleState.hpp"
#include "TurnResultState.hpp"

namespace client {

    void TurnResultState::generateInterface() {

        std::cout << "Enter Turn Result State" << std::endl;

        auto &spriteVector = this->battleScene->getStateSpriteVector();
        auto &textVector = this->battleScene->getStateTextVector();
        auto &view = this->battleScene->getView();

        spriteVector.emplace_back("battleInfoBack", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 2, 1.175);
        spriteVector.back().setScale(view, 3.5);

        textVector.emplace_back("textFont", "Player 2 switched Fakemon 2.1 with Fakemon 2.2.\n\nFakemon 1.1 of Player 1 did something to Fakemon 2.2\nof Player 2.");
        textVector.back().setCharacterSize(view, 95);
        textVector.back().setOrigin(2, 2);
        textVector.back().setPosition(view, 2, 1.175);
    }

    void TurnResultState::temporaryRequest() {
        battleScene->transitionTo(std::make_shared<EndBattleState>());
    }
}