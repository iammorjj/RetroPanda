//
//  timer.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 30/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "timer.h"

#include "SDL.h"

Timer::Timer()
    : start_ticks_(0), paused_ticks_(0), is_paused_(false), is_started_(false) {
}

void Timer::Start() {
  is_started_ = true;
  is_paused_ = false;
  start_ticks_ = SDL_GetTicks();
}

void Timer::Stop() {
  is_started_ = false;
  is_paused_ = false;
}

int Timer::GetTicks() {
  if (is_started_) {
    if (is_paused_) {
      return paused_ticks_;
    } else {
      return SDL_GetTicks() - start_ticks_;
    }
  }

  return 0;
}
