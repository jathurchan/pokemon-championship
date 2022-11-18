#include <iostream>
#include "BattleScene.hpp"
#include "LoginState.hpp"
#include "BanState.hpp"

/*
 * Login state, when the player can log into the match.
 */

namespace client {

    /*
     * Add the state interface element to the vectors of the state displayed element.
     */
    void LoginState::generateInterface() {

        std::cout << "Enter Login State" << std::endl;

        auto &spriteVector = this->battleScene->getStateSpriteVector();
        auto &textVector = this->battleScene->getStateTextVector();
        auto &view = this->battleScene->getView();

        spriteVector.emplace_back("loginBackground", true);
        spriteVector.back().setOrigin(0, 0);
        spriteVector.back().setPosition(view, 0, 0);
        spriteVector.back().setScale(view, 1);

        textVector.emplace_back(CustomText("titleFont", "Fakemon Projekt"));
        textVector.back().setCharacterSize(view, 20);
        textVector.back().setOrigin(2, 2);
        textVector.back().setPosition(view, 2, 12);

        textVector.emplace_back(CustomText("textFont", "Username"));
        textVector.back().setCharacterSize(view, 60);
        textVector.back().setOrigin(2, 2);
        textVector.back().setPosition(view, 2, 4.5);

        textVector.emplace_back(CustomText("textFont", "Link Code"));
        textVector.back().setCharacterSize(view, 60);
        textVector.back().setOrigin(2, 2);
        textVector.back().setPosition(view, 2, 2.7);

        spriteVector.emplace_back("loginTextBox", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 2, 3.5);
        spriteVector.back().setScale(view, 12);

        spriteVector.emplace_back("loginTextBox", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 2, 2.3);
        spriteVector.back().setScale(view, 12);
    }

    /*
     * Test request which change the current state of the scene to the Ban State.
     */
    void LoginState::temporaryRequest() {
        battleScene->transitionTo(std::make_shared<BanState>());
    }

    std::string LoginState::getStateName() {
        return std::to_string(StatesName::Login_State);
    }
}