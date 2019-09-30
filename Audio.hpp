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
    Audio() {}
    ~Audio() {}
    int playSFX(std::string &filepath);
    void stopSFX();
    int playMusic(std::string &filepath);
    void stopMusic();
private:
    sf::SoundBuffer gameSoundBuffer;
    sf::Sound sfx;
    sf::Music gameMusic;
};

#endif /* AUDIO_HPP */