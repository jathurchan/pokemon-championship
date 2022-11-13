#include "State.hpp"
#include "BattleScene.hpp"
#include <iostream>

/*
 * State of the game scene.
 */

namespace client {

    /*
     * Default destructor;
     */
    State::~State() = default;

    /*
     * Sets the pointer refering to the battlescene associated to the state.
     */
    void State::setScene(BattleScene *battleScene) {
        this->battleScene = battleScene;
    }

    /*
     * Modify the content of the content of the vectors in the battle scene containing the displayed element.
     */
    void State::initializeState() {
        battleScene->resetStateDrawVectors();
        generateInterface();
    }
}