/******************************************
 * Programmer: Zach Nett
 * Date: 10/2/19
 * File: Player.hpp
 * Project: sfml-causality
 ******************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Game.hpp"

class Player : public sf::RectangleShape { // inherits from rectangle shape due to sprite/hitbox
public:
    Player() {}
    ~Player() {}

    // Attribute/stat setters
    void setName(std::string &newName) { name = newName; }
    void setName(const char *newName) {
        std::string temp = newName;
        name = temp;
    }
    void setHealth(double health) { currentHealth = health; }
    void setHealth(double health, double newHealthMax) { currentHealth = health; healthMax = newHealthMax; }
    void setStamina(double stamina) { currentStamina = stamina; }
    void setStamina(double stamina, double newStaminaMax) { currentStamina = stamina; staminaMax = newStaminaMax; }
    void setMagic(double magic) { currentMagic = magic; }
    void setMagic(double magic, double newMagicMax) { currentMagic = magic; magicMax = newMagicMax; }

    // Attribute getters
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