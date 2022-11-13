#include <iostream>
#include "BattleScene.hpp"
#include "WaitState.hpp"
#include "TurnResultState.hpp"

/*
 * Wait state, when the player wait for the other player to play.
 */

namespace client {

    /*
     * Add the state interface element to the vectors of the state displayed element.
     */
    void WaitState::generateInterface() {

        std::cout << "Enter Wait State" << std::endl;

        auto &spriteVector = this->battleScene->getStateSpriteVector();
        auto &textVector = this->battleScene->getStateTextVector();
        auto &view = this->battleScene->getView();

        spriteVector.emplace_back("battleInfoBack", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 2, 1.175);
        spriteVector.back().setScale(view, 3.5);

        textVector.emplace_back("textFont", "Wait ...");
        textVector.back().setCharacterSize(view, 50);
        textVector.back().setOrigin(2, 2);
        textVector.back().setPosition(view, 2, 1.175);
    }

    /*
     * Test request which change the current state of the scene to the Turn Result State.
     */
    void WaitState::temporaryRequest() {
        battleScene->transitionTo(std::make_shared<TurnResultState>());
    }
}