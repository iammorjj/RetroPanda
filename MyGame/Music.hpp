//
//  Music.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 22/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Music_hpp
#define Music_hpp

#ifndef MAC
#include <SDL/SDL_mixer.h>
#else
#include <SDL_mixer/SDL_mixer.h>
#endif

class Music {
private:
    Mix_Music* music;
    Mix_Chunk* point;
public:
    Music();
    
    void pointSoundPlay();
    
    bool load();
    void cleanup();
};

#endif /* Music_hpp */
