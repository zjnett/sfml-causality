/******************************************
 * Programmer: Zach Nett
 * Date: 9/29/19
 * File: gameInstance.cpp
 * Project: sfml-causality
 ******************************************/

#include "gameInstance.hpp"

int gameInstance::runGameInstance(sf::RenderWindow &window, Graphics &graphicsHandler, Audio &audioHandler) {
    window.clear();
    audioHandler.fadeOutMusic(100);
    return 1;
}