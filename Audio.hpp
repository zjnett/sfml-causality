/******************************************
 * Programmer: Zach Nett
 * Date: 9/30/19
 * File: Audio.hpp
 * Project: sfml-causality
 ******************************************/

#ifndef AUDIO_HPP
#define AUDIO_HPP

#include "Game.hpp"

class Audio {
public:
    Audio() { volume = 100; }
    ~Audio() {}
    int playSFX(std::string &filepath);
    void stopSFX();
    int playMusic(std::string &filepath);
    void stopMusic();
    void fadeOutMusic(double duration);
private:
    sf::SoundBuffer gameSoundBuffer;
    sf::Sound sfx;
    sf::Music gameMusic;
    double volume; // 0-100
};

#endif /* AUDIO_HPP */