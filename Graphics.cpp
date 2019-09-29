/******************************************
 * Programmer: Zach Nett
 * Date: 9/29/19
 * File: Graphics.cpp
 * Project: sfml-causality
 ******************************************/

#include "Game.hpp"
#include "Graphics.hpp"

// Assumes 0-255
int Graphics::fadeInAnimation(sf::RenderWindow &window, double duration) {
    return 0;
}

int Graphics::fadeInAnimation(sf::RenderWindow &window, int alphaStart, int alphaEnd, double duration) {
    // Sketch: static counter (persistent between calls) that changes color
    if (animateReady) {
        static double opacity;
        double changesPerSecond = (alphaEnd - alphaStart + 1) / duration;

        if (std::abs(opacity) < alphaEnd) {
            opacity -= std::ceil((changesPerSecond / FIXED_FRAMERATE));
            screenRect.setFillColor(*(new sf::Color(0, 0, 0, opacity)));
            window.draw(screenRect);
        } else {
            //opacity = 0;
            // TODO: loop gets stuck here after animation complete -- make more efficient?
            return 1;
        }
    }
    return 0;
}

void Graphics::stopAnimation(sf::RenderWindow &window) {
    // permanently set screenrect with opacity of 0 until next animation call
    screenRect.setFillColor(*(new sf::Color(0, 0, 0, 0)));
    animateReady = false;
}
// TODO: overloaded methods with chosen color (fade in from white, etc.)