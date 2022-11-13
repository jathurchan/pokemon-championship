#include "State.hpp"
#include "BattleScene.hpp"
#include <iostream>

namespace client {

    State::~State() = default;

    void State::setScene(BattleScene *battleScene) {
        this->battleScene = battleScene;
    }

    void State::initializeState() {
        battleScene->resetStateDrawVectors();
        generateInterface();
    }
}