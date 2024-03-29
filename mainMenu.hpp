/******************************************
 * Programmer: Zach Nett
 * Date: 9/28/19
 * File: mainMenu.hpp
 * Project: sfml-causality
 ******************************************/

#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "Game.hpp"
#include "Graphics.hpp"
#include "Audio.hpp"

#define VERT_BUTTON_SPACING 1.5

enum instruction { EXIT, NEW_GAME, LOAD_GAME, CONTINUE };

class mainMenu {
public:
    mainMenu() {
        buttonSelected = 1;
    }
    ~mainMenu() {}

    void instantiateMenuObjects();

    int runMainMenu(sf::RenderWindow &window, Graphics &graphicsHandler, Audio &audioHandler);

    // Button selected getter
    int getButtonSelected() {
        return buttonSelected;
    }

    void setButtonSelected(int newSelection) {
        if (newSelection < 1)
            buttonSelected = 1;
        else if (newSelection > 3)
            buttonSelected = 3;
        else
            buttonSelected = newSelection;
    }

private:
    int buttonSelected;
    sf::Font sysfont;
    sf::Sound uiInteract;
    sf::SoundBuffer buffer;
};

#endif /* MAIN_MENU_HPP */