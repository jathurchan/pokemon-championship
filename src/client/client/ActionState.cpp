#include <iostream>
#include <regex>
#include "BattleScene.hpp"
#include "ActionState.hpp"
#include "SwitchState.hpp"

/*
 * Turn Result state, when the player can choose between the 4 actions of its active fakemon.
 */

namespace client {

    /*
     * Add the state interface element to the vectors of the state displayed element.
     */
    void ActionState::generateInterface() {

        std::cout << "Enter Action State" << std::endl;

        /*auto &spriteVector = this->battleScene->getStateSpriteVector();
        auto &textVector = this->battleScene->getStateTextVector();
        auto &view = this->battleScene->getView();

        spriteVector.emplace_back("infernalAction", true);
        spriteVector.back().setOrigin(1, 0);
        spriteVector.back().setPosition(view, 2.01, 1.179);
        spriteVector.back().setScale(view, 7, false, true);

        spriteVector.emplace_back("infernalAction", true);
        spriteVector.back().setOrigin(1, 0);
        spriteVector.back().setPosition(view, 1.99, 1.179);
        spriteVector.back().setScale(view, 7, true, true);

        spriteVector.emplace_back("infernalAction", true);
        spriteVector.back().setOrigin(1, 0);
        spriteVector.back().setPosition(view, 2.01, 1.169);
        spriteVector.back().setScale(view, 7, false, false);

        spriteVector.emplace_back("neutralAction", true);
        spriteVector.back().setOrigin(1, 0);
        spriteVector.back().setPosition(view, 1.99, 1.169);
        spriteVector.back().setScale(view, 7, true, false);

        spriteVector.emplace_back("returnButton", true);
        spriteVector.back().setOrigin(0, 1);
        spriteVector.back().setPosition(view, 1.5, 1);
        spriteVector.back().setScale(view, 10);

        textVector.emplace_back("textFont", "Action 1");
        textVector.back().setCharacterSize(view, 63);
        textVector.back().setOrigin(1, 2);
        textVector.back().setPosition(view, 2.08, 1.28);

        textVector.emplace_back("textFont", "Action 2");
        textVector.back().setCharacterSize(view, 63);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 1.92, 1.28);

        textVector.emplace_back("textFont", "Action 3");
        textVector.back().setCharacterSize(view, 63);
        textVector.back().setOrigin(1, 2);
        textVector.back().setPosition(view, 2.08, 1.08);

        textVector.emplace_back("textFont", "Action 4");
        textVector.back().setCharacterSize(view, 63);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 1.92, 1.08);*/
    }

    /*
     * Test request which change the current state of the scene to the Switch State.
     */
    void ActionState::temporaryRequest() {
        battleScene->transitionTo(std::make_shared<SwitchState>());
    }

    std::string ActionState::getStateName() {
        return ResourceHolder::getInstance().getStateName(Action_State);
    }
}