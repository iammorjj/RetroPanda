//
//  conveyor.h
//  MyGame
//
//  Created by Alexander Mordovsky on 28/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_CONVEYOR_H_
#define MY_GAME_CONVEYOR_H_

#include "animation.h"
#include "entity.h"

class Conveyor: public Entity {
 public:
  Conveyor();
  
  inline void NewGame() { is_running_ = true; }
  inline void GameOver() { is_running_ = false; }
  
  bool Load();
  void Loop();
  void Render(SDL_Surface* display);
  void Cleanup();
  
 private:
  SDL_Surface* surface_;
  
  bool is_running_;
  
  Animation animation_;
  
  void DrawSide(SDL_Surface* display, int side);
};

#endif  // MY_GAME_CONVEYOR_H_
