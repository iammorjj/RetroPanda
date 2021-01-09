//
//  entity.h
//  MyGame
//
//  Created by Alexander Mordovsky on 27/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_ENTITY_H_
#define MY_GAME_ENTITY_H_

#include <vector>

#include "SDL.h"

class Entity {
public:
  static std::vector<Entity *> entity_list_;

  virtual ~Entity() {}

  virtual bool Load() = 0;
  virtual void Loop() = 0;
  virtual void Render(SDL_Surface *display) = 0;
  virtual void Cleanup() = 0;
};

#endif // MY_GAME_ENTITY_H_
