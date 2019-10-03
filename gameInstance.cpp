/******************************************
 * Programmer: Zach Nett
 * Date: 9/29/19
 * File: gameInstance.cpp
 * Project: sfml-causality
 ******************************************/

#include "gameInstance.hpp"

int gameInstance::runGameInstance(sf::RenderWindow &window, Graphics &graphicsHandler, Audio &audioHandler) {
    window.clear();
    // at start of frame, check if player's animation needs to change
    sf::Texture playerTex;
    playerTex = graphicsHandler.getTextureInArray(0);
    pc.setTexture(&playerTex);

    handlePlayerMovement(pc);
    // TODO:
    // * Have player object & draw on screen - DONE
    // * Player object controllable
    // * Player cannot leave window bounds
    // * Camera system to track player
    // * Implement physics system
    // * Tileset drawing & collision


    window.draw(this->pc);
    window.display();
    return 1;
}