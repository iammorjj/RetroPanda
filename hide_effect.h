//
//  hide_effect.h
//  MyGame
//
//  Created by Alexander Mordovsky on 03/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_HIDEEFFECT_H_
#define MY_GAME_HIDEEFFECT_H_

#include <SDl/SDL.h>

class HideEffect {
 public:
  bool is_hide_ = false;
  
  inline void Hide() {
    if (old_time_ + frame_rate_ms_ > SDL_GetTicks())
      return;
    
    is_hide_ = !is_hide_;
    old_time_ = SDL_GetTicks();
  }
  
private:
  int old_time_ = 0;
  int frame_rate_ms_ = 500;
};

#endif  // MY_GAME_HIDEEFFECT_H_
