//
//  music.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 12/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "music.h"

#include "global.h"

namespace {
const char* const kMusicFile = GLOBAL_ASSETS_PATH"music.wav";
const char* const kPointSoundFile = GLOBAL_ASSETS_PATH"point.wav";
}  // namespace

Music::Music() : music_(nullptr), point_(nullptr) {}

bool Music::Load() {
  if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    return false;
  
  music_ = Mix_LoadMUS(kMusicFile);
  point_ = Mix_LoadWAV(kPointSoundFile);
  
  if (music_ == nullptr || point_ == nullptr || Mix_PlayMusic(music_, -1) < 0)
    return false;
  
  return true;
}

void Music::Cleanup() {
  Mix_FreeMusic(music_);
  Mix_FreeChunk(point_);
}
