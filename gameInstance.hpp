/******************************************
 * Programmer: Zach Nett
 * Date: 9/29/19
 * File: gameInstance.hpp
 * Project: sfml-causality
 ******************************************/

#ifndef GAME_INSTANCE_HPP
#define GAME_INSTANCE_HPP

#include "Game.hpp"
#include "Player.hpp"
#include "saveData.hpp"
#include "Graphics.hpp"
#include "Audio.hpp"
#include "Input.hpp"

class gameInstance {
public:
    gameInstance() {
        // Default game instance, no passed in save data
        isNewSave = true;
        
        // Construct default player (prior to character creation)
        pc.setName("Default");
        pc.setHealth(10, 10);
        pc.setStamina(10, 10);
        pc.setMagic(0, 0); // player does not initially have magic
        pc.setSpeed(6.5);
        pc.setSize(*(new sf::Vector2f(300, 220))); // sprite is 22x30
        pc.setFillColor(sf::Color::White);
        pc.setPosition(HORIZONTAL_RESOLUTION / 2 - (pc.getSize().x / 2), VERTICAL_RESOLUTION / 2 - (pc.getSize().y / 2));
    }
    // TODO: constructor with pre-existing save data
    gameInstance(saveData &save) {}
    ~gameInstance() {}

    // isNewSave getter
    bool getIsNewSave() {
        return isNewSave;
    }

    // isNewSave setter
    void setIsNewSave(bool &value) {
        isNewSave = value;
    }

    // saveData getter
    saveData getSaveData() {
        return save;
    }

    void setSaveData(saveData &value) {
        save = value;
    }

    // Return 0 if instance is quit, otherwise continue
    int runGameInstance(sf::RenderWindow &window, Graphics &graphicsHandler, Audio &audioHandler);

    int saveCreation(sf::RenderWindow &window, Graphics &graphicsHandler);

private:
    bool isNewSave;
    saveData save;
    Player pc;
};

#endif /* GAME_INSTANCE_HPP */