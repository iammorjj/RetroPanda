//
//  background.h
//  MyGame
//
//  Created by Alexander Mordovsky on 10/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_BACKGROUND_H_
#define MY_GAME_BACKGROUND_H_

#include <SDL/SDL.h>

#include "entity.h"

class Background : public Entity {
 public:
  Background();
  
  bool Load();
  void Loop();
  void Render(SDL_Surface* display);
  void Cleanup();
  
 private:
  SDL_Surface* surface_;
};

#endif  // MY_GAME_BACKGROUND_H_
