//
//  GameOvertitle.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "game_over_title.h"

#include "global.h"

namespace {
const int kBestScoreFontSize = 60;
const int kWelcomeFontSize = 35;
const int kLeaderFontSize = 30;

const int kLeaderLines = 3;

const char* kBestScoreText = "best score";
const char* kWelcomeText = "press f to pay for burger";
const char* kLeaderText[] = {
    "you're the leader now!", "make #billyssubs screen photo",
    "to take part in the daily draw!"};

const int kYBestScore = 90;
const int kYWelcome = 600;
const int kYLeader[] = {630, 650, 670};
}  // namespace

inline bool GameOverTitle::LoadLeader() {
  for(int i = 0; i < kLeaderLines; ++i)
    if (!leader_[i].Load(kLeaderFontSize)) return false;
  
  return true;
}

bool GameOverTitle::Load() {
  if (!best_score_.Load(kBestScoreFontSize) ||
      !welcome_.Load(kWelcomeFontSize) ||
      !LoadLeader())
    return false;
  
  best_score_.set_y_front(kYBestScore);
  welcome_.set_y_front(kYWelcome);
  for(int i = 0; i < kLeaderLines; ++i)
    leader_[i].set_y_front(kYLeader[i]);
  
  best_score_.set_front_color(global::kWhiteColor);
  welcome_.set_front_color(global::kWhiteColor);
  for(int i = 0; i < kLeaderLines; ++i)
    leader_[i].set_front_color(global::kGoldColor);
  
  best_score_.SetText(kBestScoreText);
  welcome_.SetText(kWelcomeText);
  for(int i = 0; i < kLeaderLines; ++i)
    leader_[i].SetText(kLeaderText[i]);
  
  return true;
}

void GameOverTitle::Loop() {}

void GameOverTitle::Render(SDL_Surface* display) {
  if (!global::is_game_over) return;
  
  best_score_.Render(display);
  if (static_cast<void>(welcome_effect_.Hide()), !welcome_effect_.is_hide_)
    welcome_.Render(display);
  if (global::is_leader) {
    for(int i = 0; i < kLeaderLines; ++i)
      leader_[i].Render(display);
  }
}

void GameOverTitle::Cleanup() {
  best_score_.Cleanup();
  welcome_.Cleanup();
  for(int i = 0; i < kLeaderLines; ++i)
    leader_[i].Cleanup();
}
