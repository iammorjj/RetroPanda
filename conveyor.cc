//
//  conveyor.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 08/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "conveyor.h"

#include "location.h"
#include "global.h"

namespace {
const char* const kFile = GLOBAL_ASSETS_PATH"conveyor.png";

const int kFrameWidth = 192;
const int kFrameHeight = 192;
const int kMaxFrames = 16;

const int kYDistanceBetweenLines = 120;

const int kLeftSideCoord = global::kScrWidth / 2 - 290;
const int kRightSideCoord = global::kScrWidth / 2 + 100;
const int kYUp = 200;

enum { kRight = 0, kLeft };

const int kX[] = {kLeftSideCoord, kLeftSideCoord, kLeftSideCoord,
    kRightSideCoord, kRightSideCoord, kRightSideCoord};
const int kY[] = {kYUp + kYDistanceBetweenLines * 2, kYUp + kYDistanceBetweenLines,
    kYUp, kYUp + kYDistanceBetweenLines * 2, kYUp + kYDistanceBetweenLines, kYUp};
}  // namespace

Conveyor::Conveyor() : surface_(nullptr), is_running_(false) {}

void Conveyor::DrawSide(SDL_Surface* display, int side) {
  animation_.set_current_frame_row(side);
  
  int location = (side == kLeft ? Location::kLeftDown : Location::kRightDown);
  for (int i = 0; i < 3; ++i, ++location)
      animation_.Draw(display, surface_, kX[location], kY[location]);
}

bool Conveyor::Load() {
  surface_ = Surface::Load(kFile);
  if (!surface_)
    return false;
  
  animation_.SetSpriteInfo(kFrameWidth, kFrameHeight, kMaxFrames);
  return true;
}

void Conveyor::Loop() {
  if (is_running_)
    animation_.Animate();
}

void Conveyor::Render(SDL_Surface* display) {
  DrawSide(display, kLeft);
  DrawSide(display, kRight);
}

void Conveyor::Cleanup() {
  SDL_FreeSurface(surface_);
}
