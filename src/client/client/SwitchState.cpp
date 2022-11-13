#include <iostream>
#include "BattleScene.hpp"
#include "WaitState.hpp"
#include "SwitchState.hpp"

namespace client {

    void SwitchState::generateInterface() {

        std::cout << "Enter Switch State" << std::endl;

        auto &spriteVector = this->battleScene->getStateSpriteVector();
        auto &textVector = this->battleScene->getStateTextVector();
        auto &view = this->battleScene->getView();

        spriteVector.emplace_back("switchBack", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 2, 2);
        spriteVector.back().setScale(view, 1.3);

        spriteVector.emplace_back("fakemonInfoBack", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 2, 3.1);
        spriteVector.back().setScale(view, 3.35);

        spriteVector.emplace_back("fakemonInfoBack", true);
        spriteVector.back().setOrigin(2, 2);
        spriteVector.back().setPosition(view, 2, 1.48);
        spriteVector.back().setScale(view, 3.35);

        spriteVector.emplace_back("returnButton", true);
        spriteVector.back().setOrigin(0, 1);
        spriteVector.back().setPosition(view, 1.35, 1);
        spriteVector.back().setScale(view, 10);

        spriteVector.emplace_back(CustomSprite ("Flarezael", false));
        spriteVector.back().setOrigin(1, 2);
        spriteVector.back().setPosition(view, 3.8, 3.1);
        spriteVector.back().setScale(view, 3.5, true, false);

        spriteVector.emplace_back(CustomSprite ("Veilow", false));
        spriteVector.back().setOrigin(1, 2);
        spriteVector.back().setPosition(view, 3.8, 1.48);
        spriteVector.back().setScale(view, 3.5, true, false);

        textVector.emplace_back(CustomText("textFont", "PV : 100/100\n\nAttack : 100\n\nDefense : 100\n\nSpeed : 100"));
        textVector.back().setCharacterSize(view, 80);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 2.1, 3.05);

        textVector.emplace_back(CustomText("textFont", "Action 1\n\nAction 2\n\nAction 3\n\npAction 4"));
        textVector.back().setCharacterSize(view, 80);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 1.6, 3.05);

        textVector.emplace_back(CustomText("textFont", "PV : 100/100\n\nAttack : 100\n\nDefense : 100\n\nSpeed : 100"));
        textVector.back().setCharacterSize(view, 80);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 2.1, 1.47);

        textVector.emplace_back(CustomText("textFont", "Action 1\n\nAction 2\n\nAction 3\n\npAction 4"));
        textVector.back().setCharacterSize(view, 80);
        textVector.back().setOrigin(0, 2);
        textVector.back().setPosition(view, 1.6, 1.47);


        spriteVector.emplace_back("berryItem", true);
        spriteVector.back().setOrigin(2.5, 1);
        spriteVector.back().setPosition(view, 2.38, 2.2);
        spriteVector.back().setScale(view, 14);

        spriteVector.emplace_back("berryItem", true);
        spriteVector.back().setOrigin(2.5, 1);
        spriteVector.back().setPosition(view, 2.38, 1.238);
        spriteVector.back().setScale(view, 14);
    }

    void SwitchState::temporaryRequest() {
        battleScene->transitionTo(std::make_shared<WaitState>());
    }
}