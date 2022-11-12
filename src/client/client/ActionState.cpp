#include <iostream>
#include "BattleScene.hpp"
#include "ActionState.hpp"
#include "ChoiceState.hpp"

namespace client {

    void ActionState::generateInterface() {

        auto &spriteVector = this->battleScene->getSpriteVector();
        auto &spriteText = this->battleScene->getTextVector();
        auto &window = this->battleScene->getWindow();
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

        spriteText.emplace_back("textFont", "Action 1");
        spriteText.back().setCharacterSize(window, view, 63);
        spriteText.back().setOrigin(1, 2);
        spriteText.back().setPosition(view, 2.08, 1.28);

        spriteText.emplace_back("textFont", "Action 2");
        spriteText.back().setCharacterSize(window, view, 63);
        spriteText.back().setOrigin(0, 2);
        spriteText.back().setPosition(view, 1.92, 1.28);

        spriteText.emplace_back("textFont", "Action 3");
        spriteText.back().setCharacterSize(window, view, 63);
        spriteText.back().setOrigin(1, 2);
        spriteText.back().setPosition(view, 2.08, 1.08);

        spriteText.emplace_back("textFont", "Action 4");
        spriteText.back().setCharacterSize(window, view, 63);
        spriteText.back().setOrigin(0, 2);
        spriteText.back().setPosition(view, 1.92, 1.08);
    }
}