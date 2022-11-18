#include <iostream>
#include "BattleScene.hpp"
#include "EndBattleState.hpp"
#include "LoginState.hpp"

/*
 * End Battle state, when the player see the result of the match.
 */

namespace client {

    /*
     * Add the state interface element to the vectors of the state displayed element.
     */
    void EndBattleState::generateInterface() {

        //std::string result = "victory";
        std::string result = "defeat";

        std::cout << "Enter " + result + " End Turn State" << std::endl;

        auto &spriteVector = this->battleScene->getStateSpriteVector();
        auto &textVector = this->battleScene->getStateTextVector();
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

        textVector.emplace_back("textFont", "Recap : Player 1", sf::Text::Bold);
        textVector.back().setCharacterSize(view, 55);
        textVector.back().setOrigin(1, 2);
        textVector.back().setPosition(view, 2.17, 2.6);

        textVector.emplace_back("textFont", "Recap : Player 2", sf::Text::Bold);
        textVector.back().setCharacterSize(view, 55);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 1.855, 2.6);
    }

    /*
     * Test request which change the current state of the scene to the Login State.
     */
    void EndBattleState::temporaryRequest() {
        battleScene->transitionTo(std::make_shared<LoginState>());
    }

    std::string EndBattleState::getStateName() {
        return std::to_string(StatesName::EndBattle_State);
    }
}