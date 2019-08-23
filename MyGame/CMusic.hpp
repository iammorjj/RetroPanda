//
//  CMusic.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 22/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CMusic_hpp
#define CMusic_hpp

#ifndef MAC
#include <SDL/SDL_mixer.h>
#else
#include <SDL_mixer/SDL_mixer.h>
#endif

#include "Constants.h"

class CMusic {
    friend class CApp;
private:
    Mix_Music*      music;
    Mix_Chunk*      point;
    
    CMusic() {}
    ~CMusic() {}
    
    bool OnLoad() {
        if(Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1)
            return false;
        
        music = Mix_LoadMUS( CONSTANTS::MUSIC.c_str() );
        point = Mix_LoadWAV( CONSTANTS::POINT_WAV.c_str() );
        if(music == NULL || point == NULL || Mix_PlayMusic( music, -1 ) < 0)
            return false;
        
        return true;
    }
    
    void OnCleanup() {
        Mix_FreeMusic(music);
        Mix_FreeChunk(point);
    }
    
    void pointSoundPlay() {
        Mix_PlayChannel( -1, point, 0 );
    }
};

#endif /* CMusic_hpp */
