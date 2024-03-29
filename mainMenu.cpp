/******************************************
 * Programmer: Zach Nett
 * Date: 9/28/19
 * File: mainMenu.cpp
 * Project: sfml-causality
 ******************************************/

#include "mainMenu.hpp"

int mainMenu::runMainMenu(sf::RenderWindow &window, Graphics &graphicsHandler, Audio &audioHandler) {
    // Create logo object and set properties
    sf::Text logo("Causality", sysfont);
    logo.setCharacterSize(250);
    logo.setFillColor(sf::Color::White);
    logo.setPosition(window.getSize().x / 2 - (logo.getLocalBounds().width / 2), 
        window.getSize().y / 10);

    // Create new game UI button
    sf::Text newGame("New Game", sysfont);
    newGame.setCharacterSize(75);
    newGame.setFillColor(sf::Color::White);
    newGame.setPosition(window.getSize().x / 2 - (newGame.getLocalBounds().width / 2), 
        logo.getPosition().y + logo.getLocalBounds().height + 
        newGame.getLocalBounds().height + // Extra padding under logo
        (VERT_BUTTON_SPACING * newGame.getLocalBounds().height));

    // Create load game UI button
    sf::Text loadGame("Load Game", sysfont);
    loadGame.setCharacterSize(75);
    loadGame.setFillColor(sf::Color::White);
    loadGame.setPosition(window.getSize().x / 2 - (loadGame.getLocalBounds().width / 2), 
        newGame.getPosition().y + newGame.getLocalBounds().height + 
        (VERT_BUTTON_SPACING * loadGame.getLocalBounds().height));

    // Create exit UI button
    sf::Text exitGame("Exit", sysfont);
    exitGame.setCharacterSize(75);
    exitGame.setFillColor(sf::Color::White);
    exitGame.setPosition(window.getSize().x / 2 - (exitGame.getLocalBounds().width / 2), 
        loadGame.getPosition().y + loadGame.getLocalBounds().height + 
        (VERT_BUTTON_SPACING * exitGame.getLocalBounds().height));

    // Button selection
    int buttonSelected = getButtonSelected();
    static sf::Clock timer; // static persistent timer

    if (timer.getElapsedTime().asSeconds() > 0.25f) { // Only reads button change every 0.25s
        std::string str = "assets/sfx/uioption.wav";
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            audioHandler.playSFX(str);
            if (buttonSelected != 3) {
                this->setButtonSelected(++buttonSelected);
            } else {
                this->setButtonSelected(1);
            }
            timer.restart();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            audioHandler.playSFX(str);
            if (buttonSelected != 1) {
                this->setButtonSelected(--buttonSelected);
            } else {
                this->setButtonSelected(3);
            }
            timer.restart();
        }
    }

    switch (this->getButtonSelected()) {
        case 1: // New Game
            newGame.setFillColor(sf::Color::Yellow);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                window.clear();
                window.display();
                return NEW_GAME;
            }
            break;
        case 2: // Load Game
            loadGame.setFillColor(sf::Color::Yellow);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                // TODO: load game screen
                window.clear();
                window.display();
                return LOAD_GAME;
            }
            break;
        case 3: // Exit
            exitGame.setFillColor(sf::Color::Yellow);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                return EXIT;
            }
            break;
        default:
            break;
    }

    // Window clear, object display hierarchy, display command
    window.clear();
    window.draw(logo);
    window.draw(newGame);
    window.draw(loadGame);
    window.draw(exitGame);
    if (graphicsHandler.getAnimateReady()) { // if ready for animation
        if (graphicsHandler.fadeInAnimation(window, 0, 255, 2))
            graphicsHandler.stopAnimation(window);
    }
    window.display();

    return CONTINUE;
}

void mainMenu::instantiateMenuObjects() {
    // Instantiate and load font from file
    sysfont.loadFromFile("assets/fonts/Pelagiad.ttf");
    
    // Instantiate and load UI interact SFX from file
    buffer.loadFromFile("assets/sfx/uioption.wav");
    uiInteract.setBuffer(buffer);
    uiInteract.setLoop(true);
}