#include "FakemonRender.hpp"

namespace client {

    FakemonRender::FakemonRender(std::string name) {
        this->name = name;

        this->fakemonSprite = CustomSprite(name, false);
        this->healthBar = CustomSprite("healthBar100",true);
        this->healthBarFont = CustomSprite("healthBarFont", true);

        this->nameText = CustomText("textFont",name);
        this->healtText = CustomText("textFont",name);
    }

    CustomSprite FakemonRender::getFakemonSprite() {
        return fakemonSprite;
    }

    CustomSprite FakemonRender::getHealthBar() {
        return healthBar;
    }

    CustomSprite FakemonRender::getHealthBarFont() {
        return healthBarFont;
    }

    CustomText FakemonRender::getNameText() {
        return nameText;
    }

    CustomText FakemonRender::getHealthText() {
        return healtText;
    }
}