//
//  app_loop.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "app.h"

#include "global.h"

void App::Loop() {
  for (int i = 0; i < Entity::entity_list_.size(); ++i) {
    if (!Entity::entity_list_[i])
      continue;
    Entity::entity_list_[i]->Loop();
  }
  
  if (global::is_game_over)
    return;
  
  if (hero_.CanCatch(burger_)) {
    hero_.CatchBurger(burger_);
    score_.IncrScore();
    music_.PlayPointSound();
    if (IsNewLevel())
      NewLevel();
  }
  
  if (burger_.IsMissed())
    GameOver();
}
