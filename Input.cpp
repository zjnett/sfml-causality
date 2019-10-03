/******************************************
 * Programmer: Zach Nett
 * Date: 10/3/19
 * File: Input.cpp
 * Project: sfml-causality
 ******************************************/

#include "Input.hpp"

void handlePlayerMovement(Player &pc) {
    double speed = pc.getSpeed();
    if (sf::Keyboard::isKeyPressed(LEFT_KEY)) {
        pc.move(-speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(RIGHT_KEY)) {
        pc.move(speed, 0);
    }
}