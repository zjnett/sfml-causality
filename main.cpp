/******************************************
 * Programmer: Zach Nett
 * Date: 9/28/19
 * File: main.cpp
 * Project: sfml-causality
 ******************************************/

#include "Game.hpp"
#include "Player.hpp"
#include "Graphics.hpp"
#include "Audio.hpp"
#include "mainMenu.hpp"
#include "gameInstance.hpp"

int main(void) {
    // Open window and set initial options
    sf::RenderWindow window(sf::VideoMode(HORIZONTAL_RESOLUTION, VERTICAL_RESOLUTION), "Causality");
    window.setFramerateLimit(FIXED_FRAMERATE);

    // Custom object declaration
    mainMenu menu;
    Graphics graphicsHandler;
    graphicsHandler.setTextureInArray(0, "assets/textures/player/adventurer-idle-00.png");
    gameInstance game;
    Audio audioHandler;
    std::string str = "assets/sfx/music.wav";
    audioHandler.playMusic(str);

    // Menu control parameters
    menu.instantiateMenuObjects();
    menu.setButtonSelected(1); // Ensure cursor is on 'new game' initially
    bool isMenuRunning = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (isMenuRunning) {
            int instruction = menu.runMainMenu(window, graphicsHandler, audioHandler);
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
            if (!game.runGameInstance(window, graphicsHandler, audioHandler))
                window.close();
        }
    }
    return 0;
}