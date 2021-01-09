//
//  advertising.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "advertising.h"

#include "global.h"
#include "surface.h"

namespace {
const char* const kFile = GLOBAL_ASSETS_PATH"sides_billys.png";

const int kAdvWidth = 282;
const int kAdvHeight = global::kScrHeight;
const int kAdvFrameRateMs = 200;
const int kMaxFrames = 3;

const int kXLeftSide = 0;
const int kYLeftSide = 0;
const int kXRightSide = global::kScrWidth - kAdvWidth;
const int kYRightSide = 0;
}  // namespace

Advertising::Advertising() : surface_(nullptr) {}

bool Advertising::Load() {
  surface_ = Surface::Load(kFile);
  if (!surface_) return false;
  
  animation_.SetSpriteInfo(kAdvWidth, kAdvHeight, kMaxFrames);
  animation_.set_frame_rate_ms(kAdvFrameRateMs);
  
  return true;
}

void Advertising::Loop() {
    animation_.Animate();
}

void Advertising::Render(SDL_Surface* display) {
    animation_.Draw(display, surface_, kXLeftSide, kYLeftSide);
    animation_.Draw(display, surface_, kXRightSide, kYRightSide);
}

void Advertising::Cleanup() {
    SDL_FreeSurface(surface_);
}
