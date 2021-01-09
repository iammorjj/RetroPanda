//
//  score.h
//  MyGame
//
//  Created by Alexander Mordovsky on 11/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_SCORE_H_
#define MY_GAME_SCORE_H_

#include "entity.h"
#include "title.h"

class Score : public Entity {
 public:
  Score();
  
  void NewGame();
  
  inline void IncrScore() { ++score_; }
  inline int score() const { return score_; }
  
  bool Load();
  void Loop();
  void Render(SDL_Surface* display);
  void Cleanup();
  
 private:
  int score_;
  int best_score_;
  
  Title t_score_;
  
  char score_buffer_[5];

  void ShowBestScore();
};

#endif  // MY_GAME_SCORE_H_
