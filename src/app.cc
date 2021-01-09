//
//  app.c
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "app.h"

#include "global.h"

App::App() : display_(nullptr), is_running_(true) {}

int App::Execute() {
  if (Init() == false) {
    printf("smt goes wrong\n");
    return -1;
  }

  SDL_Event event;
  while (is_running_) {
    while (SDL_PollEvent(&event))
      EventHandler(&event);
    Loop();
    Render();
  }

  Cleanup();

  return 0;
}

void App::NewGame() {
  global::is_game_over = false;

  score_.NewGame();
  burger_.NewGame();
  conveyor_.NewGame();
}

void App::GameOver() {
  global::is_first_game = false;
  global::is_game_over = true;

  global::keyboard_delay_timer.Start();
  burger_.GameOver();
  conveyor_.GameOver();
}

bool App::IsNewLevel() {
  int current_score = score_.score();
  return current_score % global::kSpeedLevelUp == 0 ||
         current_score % global::kAppearanceLevelUp == 0;
}

void App::NewLevel() {
  if (score_.score() % global::kSpeedLevelUp == 0) {
    burger_.MovementSpeedNewLevel();
  } else {
    burger_.AppearanceSpeedNewLevel();
  }
}
