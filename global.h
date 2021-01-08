//
//  global.h
//  MyGame
//
//  Created by Alexander Mordovsky on 13/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_GLOBAL_H_
#define MY_GAME_GLOBAL_H_

#include <string>

#include "SDL.h"

#include "timer.h"

namespace global {
const int kScrWidth = 1024;
const int kScrHeight = 768;
const int kScrBpp = 32;

const int kSpeedLevelUp = 3;
const int kAppearanceLevelUp = 5;

extern bool is_first_game;
extern bool is_game_over;
extern bool is_leader;

const SDL_Color kWhiteColor = {255, 255, 255};
const SDL_Color kGoldColor = {255, 215, 0};
const SDL_Color kShadowColor = {0, 0, 0};

extern Timer keyboard_delay_timer;
const int kKeyboardDelay = 2000;
inline bool IsKeyboardDelayFinished() {
  return global::keyboard_delay_timer.GetTicks() > global::kKeyboardDelay ||
         global::is_first_game;
}

const int kLineAmount = 6;

#define GLOBAL_ASSETS_PATH "./Assets/"
} // namespace global

#endif // MY_GAME_GLOBAL_H_
