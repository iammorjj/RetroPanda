//
//  music.h
//  MyGame
//
//  Created by Alexander Mordovsky on 22/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_MUSIC_H_
#define MY_GAME_MUSIC_H_

#include "SDL_mixer.h"

class Music {
public:
  Music();

  inline void PlayPointSound() { Mix_PlayChannel(-1, point_, 0); }

  bool Load();
  void Cleanup();

private:
  Mix_Music *music_;
  Mix_Chunk *point_;
};

#endif // MY_GAME_MUSIC_H_
