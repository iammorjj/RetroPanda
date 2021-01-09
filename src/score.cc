//
//  score.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 11/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "score.h"

#include <fstream>

#include "global.h"

namespace {
const char* const kFile = GLOBAL_ASSETS_PATH"best_score.txt";

const int kFontSize = 200;

const int kYTitle = 80;
}  // namespace

Score::Score() : best_score_(0), score_(0) {
  std::ifstream score_in(kFile);
  if (score_in.is_open())
    score_in >> best_score_;
  score_ = best_score_;
  score_in.close();
}

void Score::NewGame() {
  score_ = 0;
  t_score_.set_front_color(global::kWhiteColor);
}

void Score::ShowBestScore() {
  best_score_ = score_;
  static std::ofstream score_out;
  score_out.open(kFile);
  score_out << best_score_;
  score_out.close();
}

bool Score::Load() {
  if (!t_score_.Load(kFontSize))
    return false;

  t_score_.set_y_front(kYTitle);
  t_score_.set_front_color(global::kWhiteColor);

  return true;
}

void Score::Render(SDL_Surface* display) {
  sprintf(score_buffer_, "%d", score_);
  t_score_.SetText(score_buffer_);

  if (global::is_game_over) {
    if (score_ > best_score_) {
      global::is_leader = true;
      ShowBestScore();
      t_score_.set_front_color(global::kGoldColor);
    }
    score_ = best_score_;
  } else {
    global::is_leader = false;
  }

  t_score_.Render(display);
}

void Score::Loop() {}

void Score::Cleanup() {
  t_score_.Cleanup();
}
