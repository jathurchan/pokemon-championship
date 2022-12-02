#include "State.hpp"
#include "BattleScene.hpp"
#include <iostream>
#include "InterfaceJsonParser.hpp"
#include "StatesName.hpp"
#include "CustomTextBox.hpp"

#define stringify(name) #name

/*
 * State of the game scene.
 */

namespace client {

    State::~State() = default;

    /*
     * Sets the pointer refering to the battlescene associated to the state.
     */
    void State::setBattleScene(BattleScene *battleScene) {
        this->battleScene = battleScene;
    }

    /*
     * Modify the content of the content of the vectors in the battle scene containing the displayed element.
     */
    void State::initializeState() {

        battleScene->resetStateDrawVectors();
        configInterfaceJson = InterfaceJsonParser::readJsonString("res/interfaceConfig.json");

        spriteVector = this->battleScene->getStateSpriteVector();
        buttonVector = this->battleScene->getStateButtonVector();
        buttonWithTextVector = this->battleScene->getStateButtonWithTextVector();
        textVector = this->battleScene->getStateTextVector();
        view = this->battleScene->getView();

        loadSprite();
        loadButton();
        loadButtonWithText();
        loadText();
        loadTextBox();
    }

    void State::loadSprite() {
        for (auto spriteInfo : configInterfaceJson[getStateName()]["Sprite"]) {
            spriteVector->emplace_back(CustomSprite(spriteInfo["imageName"].asString(), spriteInfo["smooth"].asBool()));
            spriteVector->back().setOrigin(spriteInfo["origin"]["x"].asFloat(), spriteInfo["origin"]["y"].asFloat());
            spriteVector->back().setPosition(*view, spriteInfo["position"]["ratioX"].asFloat(), spriteInfo["position"]["ratioY"].asFloat());
            spriteVector->back().setScale(*view, spriteInfo["scale"]["ratio"].asFloat(), spriteInfo["scale"]["invertedX"].asBool(), spriteInfo["scale"]["invertedY"].asBool());
        }
    }

    void State::loadButton() {
        for (auto buttonInfo : configInterfaceJson[getStateName()]["Button"]) {
            std::cout << buttonInfo["imageName"].asString() << std::endl;
            buttonVector->emplace_back(CustomButton(buttonInfo["imageName"].asString(), buttonInfo["smooth"].asBool(),buttonInfo["parameters"]));
            buttonVector->back().setOrigin(buttonInfo["origin"]["x"].asFloat(), buttonInfo["origin"]["y"].asFloat());
            buttonVector->back().setPosition(*view, buttonInfo["position"]["ratioX"].asFloat(), buttonInfo["position"]["ratioY"].asFloat());
            buttonVector->back().setScale(*view, buttonInfo["scale"]["ratio"].asFloat(), buttonInfo["scale"]["invertedX"].asBool(), buttonInfo["scale"]["invertedY"].asBool());
            buttonVector->back().setView(view);
            buttonVector->back().setActiveButton(battleScene->getActiveButton());
        }
    }

    void State::loadText() {
        for (auto textInfo : configInterfaceJson[getStateName()]["Text"]) {
            textVector->emplace_back(CustomText(textInfo["fontName"].asString(), textInfo["string"].asString(), sf::Text::Style(textInfo["style"].asInt())));
            textVector->back().setCharacterSize(*view, textInfo["characterSize"].asFloat());
            textVector->back().setOrigin(textInfo["origin"]["x"].asFloat(), textInfo["origin"]["y"].asFloat());
            textVector->back().setPosition(*view, textInfo["position"]["ratioX"].asFloat(), textInfo["position"]["ratioY"].asFloat());
            textVector->back().setColor((char) textInfo["color"]["red"].asInt(), (char) textInfo["color"]["green"].asInt(), (char) textInfo["color"]["blue"].asInt(), (char) textInfo["color"]["a"].asInt());

        }
    }

    void State::loadButtonWithText() {
        for (auto buttonWithTextInfo : configInterfaceJson[getStateName()]["ButtonWithText"]) {
            Json::Value spriteInfo = buttonWithTextInfo["Sprite"];
            Json::Value textInfo = buttonWithTextInfo["Text"];

            buttonWithTextVector->emplace_back(CustomButtonWithText(spriteInfo["imageName"].asString(), spriteInfo["smooth"].asBool(),buttonWithTextInfo["parameters"]));
            buttonWithTextVector->back().setOrigin(spriteInfo["origin"]["x"].asFloat(), spriteInfo["origin"]["y"].asFloat());
            buttonWithTextVector->back().setPosition(*view, spriteInfo["position"]["ratioX"].asFloat(), spriteInfo["position"]["ratioY"].asFloat());
            buttonWithTextVector->back().setScale(*view, spriteInfo["scale"]["ratio"].asFloat(), spriteInfo["scale"]["invertedX"].asBool(), spriteInfo["scale"]["invertedY"].asBool());

            buttonWithTextVector->back().getText() = CustomText(textInfo["fontName"].asString(), textInfo["string"].asString(), sf::Text::Style(textInfo["style"].asInt()));
            buttonWithTextVector->back().getText().setCharacterSize(*view, textInfo["characterSize"].asFloat());
            buttonWithTextVector->back().getText().setOrigin(textInfo["origin"]["x"].asFloat(), textInfo["origin"]["y"].asFloat());
            buttonWithTextVector->back().getText().setPosition(*view, textInfo["position"]["ratioX"].asFloat(), textInfo["position"]["ratioY"].asFloat());
            buttonWithTextVector->back().getText().setColor((char) textInfo["color"]["red"].asInt(), (char) textInfo["color"]["green"].asInt(), (char) textInfo["color"]["blue"].asInt(), (char) textInfo["color"]["a"].asInt());

            buttonWithTextVector->back().setView(view);
            buttonWithTextVector->back().setActiveButton(battleScene->getActiveButton());
        }
    }

    void State::loadTextBox() {
        for (auto buttonWithTextInfo : configInterfaceJson[getStateName()]["TextBox"]) {
            Json::Value spriteInfo = buttonWithTextInfo["Sprite"];
            Json::Value textInfo = buttonWithTextInfo["Text"];

            buttonWithTextVector->emplace_back(CustomTextBox(spriteInfo["imageName"].asString(), spriteInfo["smooth"].asBool(),buttonWithTextInfo["parameters"]));
            buttonWithTextVector->back().setOrigin(spriteInfo["origin"]["x"].asFloat(), spriteInfo["origin"]["y"].asFloat());
            buttonWithTextVector->back().setPosition(*view, spriteInfo["position"]["ratioX"].asFloat(), spriteInfo["position"]["ratioY"].asFloat());
            buttonWithTextVector->back().setScale(*view, spriteInfo["scale"]["ratio"].asFloat(), spriteInfo["scale"]["invertedX"].asBool(), spriteInfo["scale"]["invertedY"].asBool());

            buttonWithTextVector->back().getText() = CustomText(textInfo["fontName"].asString(), textInfo["string"].asString(), sf::Text::Style(textInfo["style"].asInt()));
            buttonWithTextVector->back().getText().setCharacterSize(*view, textInfo["characterSize"].asFloat());
            buttonWithTextVector->back().getText().setOrigin(textInfo["origin"]["x"].asFloat(), textInfo["origin"]["y"].asFloat());
            buttonWithTextVector->back().getText().setPosition(*view, textInfo["position"]["ratioX"].asFloat(), textInfo["position"]["ratioY"].asFloat());
            buttonWithTextVector->back().getText().setColor((char) textInfo["color"]["red"].asInt(), (char) textInfo["color"]["green"].asInt(), (char) textInfo["color"]["blue"].asInt(), (char) textInfo["color"]["a"].asInt());

            buttonWithTextVector->back().setView(view);
            buttonWithTextVector->back().setActiveButton(battleScene->getActiveButton());
        }
    }
}