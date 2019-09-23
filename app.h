//
//  app.h
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_APP_H_
#define MY_GAME_APP_H_

#include <SDL/SDL.h>

#include "advertising.h"
#include "background.h"
#include "burger.h"
#include "conveyor.h"
#include "game_over_title.h"
#include "hero.h"
#include "music.h"
#include "score.h"

class App {
 public:
  App();
  
  int Execute();
  
  bool Init();
  void EventHandler(SDL_Event* event);
  
  void Loop();
  void Render();
  void Cleanup();
  
 private:
  SDL_Surface* display_;
  
  bool is_running_;
  
  Background background_;
  Advertising advertising_;
  
  GameOverTitle game_over_title_;
  
  Music music_;
  
  Score score_;

  Hero hero_;
  Burger burger_;
  Conveyor conveyor_;

  bool WindowInit();
  bool ResourceInit();
  
  void NewGame();
  void GameOver();
  
  bool IsNewLevel();
  void NewLevel();
};

#endif  // MY_GAME_APP_H_
