/******************************************
 * Programmer: Zach Nett
 * Date: 9/29/19
 * File: Graphics.hpp
 * Project: sfml-causality
 ******************************************/

#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "Game.hpp"

class Graphics {
public:
    Graphics() {
        sf::RectangleShape temp;
        temp.setSize(*(new sf::Vector2f(HORIZONTAL_RESOLUTION, VERTICAL_RESOLUTION)));
        temp.setFillColor(*(new sf::Color(0, 0, 0, 0)));
        setAnimateReady(true);
        setScreenRect(temp);
    }
    ~Graphics() {}
    // fadeInAnimation, alpha start and end integers, duration in seconds
    int fadeInAnimation(sf::RenderWindow &window, int alphaStart, int alphaEnd, double duration);
    // Assumes 0-255
    int fadeInAnimation(sf::RenderWindow &window, double duration);
    void stopAnimation(sf::RenderWindow &window);

    // screenRect getter
    sf::RectangleShape getScreenRect() {
        return screenRect;
    }

    // screenRect setter
    void setScreenRect(sf::RectangleShape &newRect) {
        screenRect.setSize(newRect.getSize());
        screenRect.setFillColor(newRect.getFillColor());
    }

    bool getAnimateReady() {
        return animateReady;
    }

    void setAnimateReady(bool status) {
        animateReady = status;
    }

    void setPlayerSpriteSheet(sf::Texture newSheet) {
        playerSpriteSheet = newSheet;
    }

    sf::Texture getPlayerSpriteSheet() {
        return playerSpriteSheet;
    }

    int setTextureInArray(int index, std::string filepath) {
        if(!textures[index].loadFromFile(filepath))
            return 0;
        return 1;
    }

    int setTextureInArray(int index, const char *filepath) {
        std::string temp = filepath;
        if(!textures[index].loadFromFile(temp))
            return 0;
        return 1;
    }

    sf::Texture getTextureInArray(int index) { return textures[index]; }

private:
    bool animateReady;
    sf::RectangleShape screenRect;
    sf::Texture playerSpriteSheet;
    sf::Texture textures[100]; // persistent texture pointers for lifetime of program
};

#endif /* GRAPHICS_HPP */