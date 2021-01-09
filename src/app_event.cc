//
//  app_event.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "app.h"

#include "global.h"

namespace {
inline bool IsQuitGame(SDL_Event* event) {
  return event->type == SDL_QUIT ||
    event->key.keysym.sym == SDLK_q;
}
}  // namespace

void App::EventHandler(SDL_Event* event) {
  if (IsQuitGame(event)) {
    is_running_ = false;
    return;
  }
    
  if (event->type == SDL_KEYDOWN) {
    if (global::is_game_over) {
      if (global::IsKeyboardDelayFinished()) {
        NewGame();
      } else {
        return;
      }
    }
  }
  
  switch (event->key.keysym.sym) {
    case SDLK_LCTRL:
    case SDLK_v:
      hero_.ChangeLocation(Location::kLeftDown);
      break;
    case SDLK_LALT:
    case SDLK_f:
      hero_.ChangeLocation(Location::kLeftMid);
      break;
    case SDLK_SPACE:
    case SDLK_r:
      hero_.ChangeLocation(Location::kLeftUp);
      break;
    case SDLK_LSHIFT:
    case SDLK_n:
      hero_.ChangeLocation(Location::kRightDown);
      break;
    case SDLK_z:
    case SDLK_j:
      hero_.ChangeLocation(Location::kRightMid);
      break;
    case SDLK_x:
    case SDLK_i:
      hero_.ChangeLocation(Location::kRightUp);
      break;
    
    default: break;
  }
}
