/******************************************
 * Programmer: Zach Nett
 * Date: 9/28/19
 * File: mainMenu.hpp
 * Project: sfml-causality
 ******************************************/

#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "Game.hpp"

class mainMenu {
public:
    mainMenu() {}
    ~mainMenu() {}
    void runMainMenu(sf::RenderWindow &window);
};

#endif /* MAIN_MENU_HPP */