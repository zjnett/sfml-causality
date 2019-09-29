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

class mainMenu {
public:
    mainMenu() {
        buttonSelected = 1;
    }
    ~mainMenu() {}
    void runMainMenu(sf::RenderWindow &window);

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