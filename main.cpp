/******************************************
 * Programmer: Zach Nett
 * Date: 9/28/19
 * File: main.cpp
 * Project: sfml-causality
 ******************************************/

#include "Game.hpp"
#include "mainMenu.hpp"
#include "gameInstance.hpp"

int main(void) {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Causality");
    mainMenu menu;
    gameInstance game;
    menu.setButtonSelected(1); // Ensure cursor is on 'new game' initially
    bool isMenuRunning = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (isMenuRunning) {
            int instruction = menu.runMainMenu(window);
            switch (instruction) {
                case NEW_GAME:
                    isMenuRunning = false;
                    break;

                case LOAD_GAME:
                    isMenuRunning = false;
                    break;

                case EXIT:
                    window.close();

                case CONTINUE:
                    break;

                default: // continue
                    break;
            }
        } else {
            if (!game.runGameInstance(window))
                window.close();
        }
    }
    return 0;
}