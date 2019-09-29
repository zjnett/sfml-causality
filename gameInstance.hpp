/******************************************
 * Programmer: Zach Nett
 * Date: 9/29/19
 * File: gameInstance.hpp
 * Project: sfml-causality
 ******************************************/

#ifndef GAME_INSTANCE_HPP
#define GAME_INSTANCE_HPP

#include "Game.hpp"
#include "saveData.hpp"

class gameInstance {
public:
    gameInstance() {
        isNewSave = true;
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

    // Return 0 if instance is quit, otherwise continue
    int runGameInstance(sf::RenderWindow &window);

private:
    bool isNewSave;
};

#endif /* GAME_INSTANCE_HPP */