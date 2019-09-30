/******************************************
 * Programmer: Zach Nett
 * Date: 9/30/19
 * File: Audio.cpp
 * Project: sfml-causality
 ******************************************/

#include "Audio.hpp"

int Audio::playSFX(std::string &filepath) {
    if (!gameSoundBuffer.loadFromFile(filepath)) {
        return 0;
    }
    sfx.setBuffer(gameSoundBuffer);
    sfx.play();
    return 1;
}

void Audio::stopSFX() {
    sfx.stop();
}

int Audio::playMusic(std::string &filepath) {
    if (!gameMusic.openFromFile(filepath)) {
        return 0;
    }
    gameMusic.play();
    return 1;
}

void Audio::stopMusic() {
    gameMusic.stop();
}