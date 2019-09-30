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
    sfx.setVolume(100);
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
    gameMusic.setVolume(100);
    gameMusic.play();
    return 1;
}

void Audio::stopMusic() {
    gameMusic.stop();
}

// Duration is in centiseconds (roughly) TODO fix?
void Audio::fadeOutMusic(double duration) {
    // turn down music's audio every frame
    volume = gameMusic.getVolume();
    double changesPerSec = 100 / duration;
    if (volume > 1) {
        double i = (changesPerSec / FIXED_FRAMERATE);
        volume -= i;
        gameMusic.setVolume(volume);
    } else {
        gameMusic.setVolume(0);
    }
}