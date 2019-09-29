/******************************************
 * Programmer: Zach Nett
 * Date: 9/28/19
 * File: main.cpp
 * Project: sfml-causality
 ******************************************/

#include "Game.hpp"
#include "mainMenu.hpp"

int main(void) {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Causality");
    mainMenu menu;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        menu.runMainMenu(window);
    }
    return 0;
}