/******************************************
 * Programmer: Zach Nett
 * Date: 10/2/19
 * File: Player.hpp
 * Project: sfml-causality
 ******************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Game.hpp"

class Player {
public:
    Player();
    ~Player();
    void setName(std::string &newName) { name = newName; }
    void setName(const char[] newName) {
        std::string temp = newName;
        name = temp;
    }
    std::string getName() { return name; }
    double getHealthMax() { return healthMax; }
    double getStaminaMax() { return staminaMax; }
    double getMagicMax() { return magicMax; }
    double getCurrentHealth() { return currentHealth; }
    double getCurrentStamina() { return currentStamina; }
    double getCurrentMagic() { return currentMagic; }

private:
    std::string name;
    double healthMax;
    double staminaMax;
    double magicMax;
    double currentHealth;
    double currentStamina;
    double currentMagic;
};

#endif /* PLAYER_HPP */