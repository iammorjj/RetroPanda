//
//  animation.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 11/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "animation.h"

Animation::Animation()
    : frame_width_(0),
      frame_height_(0),
      max_frames_(0),
      current_frame_(0),
      frame_inc_(1),
      frame_rate_ms_(125),
      old_time_ms_(0),
      current_frame_row_(0) {}

void Animation::SetSpriteInfo(int frame_width, int frame_height,
                                int max_frames) {
  frame_width_ = frame_width;
  frame_height_ = frame_height;
  max_frames_ = max_frames;
}

void Animation::Animate() {
  if (old_time_ms_ + frame_rate_ms_ > SDL_GetTicks())
    return;
  
  old_time_ms_ = SDL_GetTicks();
  current_frame_ += frame_inc_;
  if (current_frame_ >= max_frames_)
    current_frame_ = 0;
}

void Animation::Draw(SDL_Surface* display, SDL_Surface* surface,
                     int x_display, int y_display) {
  Surface::Draw(display, surface, x_display, y_display,
                GetXCurrentFrame(), GetYCurrentFrame(),
                frame_width_, frame_height_);
}
