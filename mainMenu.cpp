/******************************************
 * Programmer: Zach Nett
 * Date: 9/28/19
 * File: mainMenu.cpp
 * Project: sfml-causality
 ******************************************/

#include "mainMenu.hpp"

void mainMenu::runMainMenu(sf::RenderWindow &window) {
    // Instantiate and load font from file
    sf::Font sysfont;
    sysfont.loadFromFile("src/fonts/Pelagiad.ttf");

    // Create logo object and set properties
    sf::Text logo("Causality", sysfont);
    logo.setCharacterSize(250);
    logo.setFillColor(sf::Color::White);
    logo.setPosition(window.getSize().x / 2 - (logo.getLocalBounds().width / 2), window.getSize().y / 10);

    // Window clear, object display hierarchy, display command
    window.clear();
    window.draw(logo);
    window.display();
}