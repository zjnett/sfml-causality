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
    sf::RenderWindow window(sf::VideoMode(HORIZONTAL_RESOLUTION, VERTICAL_RESOLUTION), "Causality");
    window.setFramerateLimit(FIXED_FRAMERATE);
    sf::Clock timer;
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
        } else { // Run game instance
            if (!game.runGameInstance(window))
                window.close();
        }
    }
    return 0;
}