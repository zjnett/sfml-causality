/******************************************
 * Programmer: Zach Nett
 * Date: 9/28/19
 * File: mainMenu.hpp
 * Project: sfml-causality
 ******************************************/

#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "Game.hpp"

#define VERT_BUTTON_SPACING 1.5

enum instruction { EXIT, NEW_GAME, LOAD_GAME, CONTINUE };

class mainMenu {
public:
    mainMenu() {
        buttonSelected = 1;
    }
    ~mainMenu() {}
    int runMainMenu(sf::RenderWindow &window);

    // Button selected getter
    int getButtonSelected() {
        return buttonSelected;
    }

    void setButtonSelected(int newSelection) {
        buttonSelected = newSelection;
    }

private:
    int buttonSelected;
};

#endif /* MAIN_MENU_HPP */