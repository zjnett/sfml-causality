/******************************************
 * Programmer: Zach Nett
 * Date: 10/3/19
 * File: Input.hpp
 * Project: sfml-causality
 ******************************************/

#ifndef INPUT_HPP
#define INPUT_HPP

#include "Game.hpp"
#include "Player.hpp"

#define LEFT_KEY sf::Keyboard::A
#define RIGHT_KEY sf::Keyboard::D
#define JUMP_KEY sf::Keyboard::Space

void handlePlayerMovement(Player &pc);

#endif /* INPUT_HPP */