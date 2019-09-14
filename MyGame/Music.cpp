//
//  Music.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 12/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Music.hpp"
#include "Constants.h"
#include "Global.hpp"
#include <string>

using namespace Global;

namespace {
    const std::string fMusic = path+"music.wav";
    const std::string fPointSound = path+"point.wav";
}

Music::Music() : music(nullptr), point(nullptr) {}

bool Music::load() {
    if(Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1)
        return false;
    
    music = Mix_LoadMUS( fMusic.c_str() );
    point = Mix_LoadWAV( fPointSound.c_str() );
    
    if(music == nullptr || point == nullptr || Mix_PlayMusic( music, -1 ) < 0)
        return false;
    
    return true;
}

void Music::cleanup() {
    Mix_FreeMusic(music);
    Mix_FreeChunk(point);
}

void Music::pointSoundPlay() {
    Mix_PlayChannel( -1, point, 0 );
}
