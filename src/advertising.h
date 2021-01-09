//
//  advertising.h
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_ADVERTISING_H_
#define MY_GAME_ADVERTISING_H_

#include "SDL.h"

#include "animation.h"
#include "entity.h"

class Advertising : public Entity {
public:
  Advertising();

  bool Load();
  void Loop();
  void Render(SDL_Surface *display);
  void Cleanup();

private:
  SDL_Surface *surface_;

  Animation animation_;
};

#endif // MY_GAME_ADVERTISING_H_
