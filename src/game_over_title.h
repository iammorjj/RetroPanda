//
//  game_over_title.h
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_GAMEOVERTITLE_H_
#define MY_GAME_GAMEOVERTITLE_H_

#include "entity.h"
#include "global.h"
#include "hide_effect.h"
#include "title.h"

class GameOverTitle : public Entity {
 public:
  inline void NewGame() { best_score_.set_front_color(global::kWhiteColor); }
  inline void GameOver() { best_score_.set_front_color(global::kGoldColor); }
  
  bool Load();
  void Loop();
  void Render(SDL_Surface* display);
  void Cleanup();
  
 private:
  Title best_score_;
  Title welcome_;
  Title leader_[3];
  
  HideEffect welcome_effect_;
  
  bool LoadLeader();
};

#endif  // MY_GAME_GAMEOVERTITLE_H_
