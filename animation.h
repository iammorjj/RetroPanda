//
//  animation.h
//  MyGame
//
//  Created by Alexander Mordovsky on 27/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_ANIMATION_H_
#define MY_GAME_ANIMATION_H_

#include <SDL/SDL.h>

#include "surface.h"

class Animation {
 public:
  Animation();

  void set_current_frame_row(int row) { current_frame_row_ = row; }

  void set_frame_rate_ms(int ms) { frame_rate_ms_ = ms; }

  void SetSpriteInfo(int frame_width, int frame_height, int max_frames);

  void Animate();

  void Draw(SDL_Surface* display, SDL_Surface* surface,
            int x_display, int y_display);
  
 private:
  int frame_width_;
  int frame_height_;
  
  int max_frames_;
  int current_frame_;
  int frame_inc_;
  
  int frame_rate_ms_;
  int old_time_ms_;
  
  int current_frame_row_;

  inline int GetXCurrentFrame() { return current_frame_ * frame_width_; }
  inline int GetYCurrentFrame() { return current_frame_row_ * frame_height_; }
};

#endif  // MY_GAME_ANIMATION_H_
