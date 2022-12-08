#include <iostream>
#include "State.hpp"


namespace client {

    State::State(const std::string& stateName) {
        initAssetsVectors(stateName);
    }

    void State::initStatesName() {

    }

    void State::initAssetsVectors(const std::string& statesName) {
    }
    /*for (auto spriteInfo : configInterfaceJson[getStateName()]["Sprite"]) {
    spriteVector->emplace_back(CustomSprite(spriteInfo["imageName"].asString(), spriteInfo["smooth"].asBool()));
    spriteVector->back().setOrigin(spriteInfo["origin"]["x"].asFloat(), spriteInfo["origin"]["y"].asFloat());
    spriteVector->back().setPosition(*view, spriteInfo["position"]["ratioX"].asFloat(), spriteInfo["position"]["ratioY"].asFloat());
    spriteVector->back().setScale(*view, spriteInfo["scale"]["ratio"].asFloat(), spriteInfo["scale"]["invertedX"].asBool(), spriteInfo["scale"]["invertedY"].asBool());*/

    std::vector<render::CustomSprite> State::getSpriteVector() {
        return spriteVector;
    }

    std::vector<render::CustomText> State::getTextVector() {
        return textVector;
    }
}