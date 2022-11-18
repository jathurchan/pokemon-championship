#include <iostream>
#include "BattleScene.hpp"
#include "SelectState.hpp"
#include "BanState.hpp"

/*
 * Turn Result state, when the player can ban a fakemon from the ennemy team.
 */

namespace client {

    /*
     * Add the state interface element to the vectors of the state displayed element.
     */
    void BanState::generateInterface() {

        std::cout << "Enter Ban State" << std::endl;

        this->battleScene->generateDefaultInterface();

        auto &spriteVector = this->battleScene->getStateSpriteVector();
        auto &textVector = this->battleScene->getStateTextVector();
        auto &view = this->battleScene->getView();

        spriteVector.emplace_back("banBack", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 2, 2);
        spriteVector.back().setScale(view, 1.2);

        spriteVector.emplace_back("fakemonInfoBack", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 1.46, 3.9);
        spriteVector.back().setScale(view, 5);

        spriteVector.emplace_back("fakemonInfoBack", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 1.46, 2);
        spriteVector.back().setScale(view, 5);

        spriteVector.emplace_back("fakemonInfoBack", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 1.46, 1.35);
        spriteVector.back().setScale(view, 5);

        spriteVector.emplace_back("fakemonInfoBack", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 3.18, 3.9);
        spriteVector.back().setScale(view, 5);

        spriteVector.emplace_back("fakemonInfoBack", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 3.18, 2);
        spriteVector.back().setScale(view, 5);

        spriteVector.emplace_back("fakemonInfoBack", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 3.18, 1.35);
        spriteVector.back().setScale(view, 5);


        spriteVector.emplace_back(CustomSprite ("Flarezael", false));
        spriteVector.back().setOrigin(1, 2);
        spriteVector.back().setPosition(view, 6, 3.9);
        spriteVector.back().setScale(view, 5.5, true, false);

        spriteVector.emplace_back(CustomSprite ("Veilow", false));
        spriteVector.back().setOrigin(1, 2);
        spriteVector.back().setPosition(view, 6, 2);
        spriteVector.back().setScale(view, 5.5, true, false);

        spriteVector.emplace_back(CustomSprite ("Unex", false));
        spriteVector.back().setOrigin(1, 2);
        spriteVector.back().setPosition(view, 6, 1.35);
        spriteVector.back().setScale(view, 5.5, true, false);

        spriteVector.emplace_back(CustomSprite ("Timbrian", false));
        spriteVector.back().setOrigin(1, 2);
        spriteVector.back().setPosition(view, 1.85, 3.9);
        spriteVector.back().setScale(view, 5.5, true, false);

        spriteVector.emplace_back(CustomSprite ("Aevituu", false));
        spriteVector.back().setOrigin(1, 2);
        spriteVector.back().setPosition(view, 1.85, 2);
        spriteVector.back().setScale(view, 5.5, true, false);

        spriteVector.emplace_back(CustomSprite ("Gramarvog", false));
        spriteVector.back().setOrigin(1, 2);
        spriteVector.back().setPosition(view, 1.85, 1.35);
        spriteVector.back().setScale(view, 5.5, true, false);


        textVector.emplace_back(CustomText("textFont", "PV : 100/100\n\nAttack : 100\n\nDefense : 100\n\nSpeed : 100"));
        textVector.back().setCharacterSize(view, 100);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 3.5, 3.90);

        textVector.emplace_back(CustomText("textFont", "Action 1\n\nAction 2\n\nAction 3\n\npAction 4"));
        textVector.back().setCharacterSize(view, 100);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 2.5, 3.90);

        textVector.emplace_back(CustomText("textFont", "PV : 100/100\n\nAttack : 100\n\nDefense : 100\n\nSpeed : 100"));
        textVector.back().setCharacterSize(view, 100);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 3.5, 1.98);

        textVector.emplace_back(CustomText("textFont", "Action 1\n\nAction 2\n\nAction 3\n\npAction 4"));
        textVector.back().setCharacterSize(view, 100);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 2.5, 1.98);

        textVector.emplace_back(CustomText("textFont", "PV : 100/100\n\nAttack : 100\n\nDefense : 100\n\nSpeed : 100"));
        textVector.back().setCharacterSize(view, 100);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 3.5, 1.34);

        textVector.emplace_back(CustomText("textFont", "Action 1\n\nAction 2\n\nAction 3\n\npAction 4"));
        textVector.back().setCharacterSize(view, 100);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 2.5, 1.34);


        textVector.emplace_back(CustomText("textFont", "PV : 100/100\n\nAttack : 100\n\nDefense : 100\n\nSpeed : 100"));
        textVector.back().setCharacterSize(view, 100);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 1.52, 3.9);

        textVector.emplace_back(CustomText("textFont", "Action 1\n\nAction 2\n\nAction 3\n\npAction 4"));
        textVector.back().setCharacterSize(view, 100);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 1.3, 3.9);

        textVector.emplace_back(CustomText("textFont", "PV : 100/100\n\nAttack : 100\n\nDefense : 100\n\nSpeed : 100"));
        textVector.back().setCharacterSize(view, 100);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 1.52, 1.98);

        textVector.emplace_back(CustomText("textFont", "Action 1\n\nAction 2\n\nAction 3\n\npAction 4"));
        textVector.back().setCharacterSize(view, 100);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 1.3, 1.98);

        textVector.emplace_back(CustomText("textFont", "PV : 100/100\n\nAttack : 100\n\nDefense : 100\n\nSpeed : 100"));
        textVector.back().setCharacterSize(view, 100);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 1.52, 1.34);

        textVector.emplace_back(CustomText("textFont", "Action 1\n\nAction 2\n\nAction 3\n\npAction 4"));
        textVector.back().setCharacterSize(view, 100);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 1.3, 1.34);


        spriteVector.emplace_back(CustomSprite ("banButton", true));
        spriteVector.back().setOrigin(2, 1);
        spriteVector.back().setPosition(view, 2, 1.002);
        spriteVector.back().setScale(view, 7);

        textVector.emplace_back(CustomText("textFont", "Ban", sf::Text::Bold));
        textVector.back().setCharacterSize(view, 50);
        textVector.back().setOrigin(2, 1);
        textVector.back().setPosition(view, 2, 1.07);
    }

    /*
     * Test request which change the current state of the scene to the Select State.
     */
    void BanState::temporaryRequest() {
        battleScene->transitionTo(std::make_shared<SelectState>());
    }

    std::string BanState::getStateName() {
        return std::to_string(StatesName::Ban_State);
    }
}