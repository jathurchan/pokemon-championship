#include <iostream>
#include "BattleScene.hpp"
#include "EndBattleState.hpp"
#include "TurnResultState.hpp"

/*
 * Turn Result state, when the player see the result of the current turn.
 */

namespace client {

    /*
     * Add the state interface element to the vectors of the state displayed element.
     */
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

    /*
     * Test request which change the current state of the scene to the End Battle State.
     */
    void TurnResultState::temporaryRequest() {
        battleScene->transitionTo(std::make_shared<EndBattleState>());
    }

    std::string TurnResultState::getStateName() {
        return std::to_string(StatesName::TurnResult_State);
    }
}