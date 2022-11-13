#include <iostream>
#include "BattleScene.hpp"
#include "ChoiceState.hpp"
#include "ActionState.hpp"

namespace client {

    void ChoiceState::generateInterface() {

        std::cout << "Enter Choice State" << std::endl;

        this->battleScene->generateFakemonInterface();

        auto& spriteVector = this->battleScene->getStateSpriteVector();
        auto& textVector = this->battleScene->getStateTextVector();
        auto& view = this->battleScene->getView();

        spriteVector.emplace_back("actionButton", true);
        spriteVector.back().setOrigin(1, 1);
        spriteVector.back().setPosition(view, 2.01, 1.002);
        spriteVector.back().setScale(view, 5);

        spriteVector.emplace_back("switchButton", true);
        spriteVector.back().setOrigin(0, 1);
        spriteVector.back().setPosition(view, 1.99, 1.002);
        spriteVector.back().setScale(view, 5);

        textVector.emplace_back("textFont", "ACTION", sf::Text::Bold);
        textVector.back().setCharacterSize(view, 50);
        textVector.back().setOrigin(1, 2);
        textVector.back().setPosition(view, 2.1, 1.114);

        textVector.emplace_back("textFont", "SWITCH", sf::Text::Bold);
        textVector.back().setCharacterSize(view, 50);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 1.9, 1.114);
    }

    void ChoiceState::temporaryRequest() {
        battleScene->transitionTo(std::make_shared<ActionState>());
    }
}