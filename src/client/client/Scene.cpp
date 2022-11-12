#include <iostream>
#include <client.hpp>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include <ctime>
#include <forward_list>

namespace client {

    Scene::Scene() {

        //OBTENU D'UN GETTER

        createWindow();
    }


    void Scene::createWindow() {

        bool fullScreen = true;
        window.create(sf::VideoMode().getDesktopMode(), "Fakemon_Projekt", sf::Style::Fullscreen);
        sf::View view(window.getDefaultView());

        //A modifier plus tard une fois les API implémentée pour récupérer une liste de créatures
        std::vector<std::string> team1 = {"Timbrian","Unex","Flarezael"};
        std::vector<std::string> team2 = {"Veilow","Aevituu","Gramarvog"};
        /*CustomSprite* fakemonSprites[3];
        for (int i = 0; i < ; i++) {
            fakemonSprites[i] = new CustomSprite(fakemons[i].getName(), false);
            fakemonSprites[i]->setOrigin(1,1);
            if (i<3) {
                fakemonSprites[i]->setPosition(window,40,1);
                fakemonSprites[i]->setScale(window, 1.7, true);
            }
            else {
                fakemonSprites[i]->setPosition(window,1.025,1);
                fakemonSprites[i]->setScale(window, 1.7);
            }
        }*/



        srand(time(NULL));
        int rnd = rand() % 6 + 1;
        CustomSprite background("arenamap" + std::to_string(rnd), false);

        CustomSprite actionButton("actionButton", true);
        CustomSprite switchButton("switchButton", true);

        actionButtonText = CustomText("textFont", "ACTION", sf::Text::Bold);
        switchButtonText = CustomText("textFont", "SWITCH", sf::Text::Bold);

        CustomSprite action1Button("action1Button", true);
        CustomSprite action2Button("action2Button", true);
        CustomSprite action3Button("action3Button", true);
        CustomSprite action4Button("action4Button", true);

        action1Text = CustomText("textFont", "Action 1");
        action2Text = CustomText("textFont", "Action 2");
        action3Text = CustomText("textFont", "Action 3");
        action4Text = CustomText("textFont", "Action 4");

        CustomSprite returnActionButton("returnButton", true);
        CustomSprite returnSwitchButton("returnButton", true);




        std::forward_list < CustomSprite * > spriteDrawList = {&background, &actionButton, &switchButton};
        std::forward_list < CustomText * > textDrawList = {&actionButtonText, &switchButtonText};

        background.setOrigin(2, 2);
        background.setPosition(view, 2, 2);
        background.setScale(view, 1);

        actionButton.setOrigin(1, 1);
        actionButton.setPosition(view, 2.01, 1.002);
        actionButton.setScale(view, 5);

        switchButton.setOrigin(0, 1);
        switchButton.setPosition(view, 1.99, 1.002);
        switchButton.setScale(view, 5);

        actionButtonText.setCharacterSize(window, view, 50);
        actionButtonText.setOrigin(1, 2);
        actionButtonText.setPosition(view, 2.1, 1.114);

        switchButtonText.setCharacterSize(window, view, 50);
        switchButtonText.setOrigin(0, 2);
        switchButtonText.setPosition(view, 1.9, 1.114);

        action1Button.setOrigin(1, 1);
        action1Button.setPosition(view, 2.01, 1.179);
        action1Button.setScale(view, 7);

        action2Button.setOrigin(0, 1);
        action2Button.setPosition(view, 1.99, 1.179);
        action2Button.setScale(view, 7);

        action3Button.setOrigin(1, 0);
        action3Button.setPosition(view, 2.01, 1.169);
        action3Button.setScale(view, 7);

        action4Button.setOrigin(0, 0);
        action4Button.setPosition(view, 1.99, 1.169);
        action4Button.setScale(view, 7);

        action1Text.setCharacterSize(window, view, 63);
        action1Text.setOrigin(1, 2);
        action1Text.setPosition(view, 2.08, 1.28);

        action2Text.setCharacterSize(window, view, 63);
        action2Text.setOrigin(0, 2);
        action2Text.setPosition(view, 1.92, 1.28);

        action3Text.setCharacterSize(window, view, 63);
        action3Text.setOrigin(1, 2);
        action3Text.setPosition(view, 2.08, 1.08);

        action4Text.setCharacterSize(window, view, 63);
        action4Text.setOrigin(0, 2);
        action4Text.setPosition(view, 1.92, 1.08);

        returnActionButton.setOrigin(0, 1);
        returnActionButton.setPosition(view, 1.5, 1);
        returnActionButton.setScale(view, 10);


        CustomSprite fakemonInfo1("fakemonInfo", true);
        CustomSprite fakemonInfo2("fakemonInfo", true);
        fakemonInfo1.setPosition(view, 0,4);
        fakemonInfo1.setScale(view, 12);
        fakemonInfo2.setPosition(view, 1,6);
        fakemonInfo2.setScale(view, 12, true);



        while (window.isOpen()) {

            window.clear(sf::Color::Black);
            window.draw(background.getSprite());

            for (auto iS : spriteDrawList) {
                window.draw((*iS).getSprite());
            }
            for (auto iT : textDrawList) {
                window.draw((*iT).getText());
            }

            //window.draw(fakemonSprites[0]->getSprite());
            //window.draw(fakemonSprites[3]->getSprite());

            window.draw(fakemonInfo1.getSprite());
            window.draw(fakemonInfo2.getSprite());

            window.setView(view);
            window.display();

            sf::Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyPressed:
                        switch (event.key.code) {
                            case sf::Keyboard::Escape:
                                window.close();
                                break;
                            case sf::Keyboard::Enter:
                                if (fullScreen) {
                                    window.create(sf::VideoMode(960, 540), "Fakemon_Projekt");
                                } else {
                                    window.create(sf::VideoMode().getDesktopMode(), "Fakemon_Projekt",
                                                  sf::Style::Fullscreen);
                                }
                                fullScreen = !fullScreen;
                                break;
                            default:
                                break;
                        }
                    case sf::Event::MouseButtonPressed:
                        switch (event.mouseButton.button) {
                            case sf::Mouse::Left: {
                                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                                if (actionButton.isInSprite(mousePosition)) {
                                    spriteDrawList.remove(&actionButton);
                                    spriteDrawList.remove(&switchButton);
                                    textDrawList.remove(&actionButtonText);
                                    textDrawList.remove(&switchButtonText);

                                    spriteDrawList.assign(
                                            {&action1Button, &action2Button, &action3Button, &action4Button,
                                             &returnActionButton});
                                    textDrawList.assign({&action1Text, &action2Text, &action3Text, &action4Text});
                                }
                                if (returnActionButton.isInSprite(mousePosition)) {
                                    spriteDrawList.remove(&action1Button);
                                    spriteDrawList.remove(&action2Button);
                                    spriteDrawList.remove(&action3Button);
                                    spriteDrawList.remove(&action4Button);
                                    textDrawList.remove(&action1Text);
                                    textDrawList.remove(&action2Text);
                                    textDrawList.remove(&action3Text);
                                    textDrawList.remove(&action4Text);

                                    spriteDrawList.assign({&actionButton, &switchButton});
                                    textDrawList.assign({&actionButtonText, &switchButtonText});
                                }
                                if (switchButton.isInSprite(mousePosition)) {
                                }
                                break;
                            }
                            default:
                                break;
                        }
                        break;
                    case sf::Event::Resized:
                        view = updatedView(view, event.size.width, event.size.height);
                    default:
                        break;
                }
            }
        }
    }


    sf::View Scene::updatedView(sf::View view, int windowWidth, int windowHeight) {

        float windowRatio = (float) windowWidth / windowHeight;
        float viewRatio = 16.f / 9.f;
        float sizeX = 1, sizeY = 1;
        float posX = 0, posY = 0;

        if (windowRatio > viewRatio) {
            sizeX = viewRatio / windowRatio;
            posX = (1 - sizeX) / 2;
        } else {
            sizeY = windowRatio / viewRatio;
            posY = (1 - sizeY) / 2;
        }

        view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));

        return view;
    }
}



/*
 * pollEvent()
 * waitEvent()
 * setIcon()
 * setVisible()
 * setMouseCursorVisible()
 * setMouseCursor()
 * requestFocus()
 * clear()
 */