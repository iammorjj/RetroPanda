//
//  hero.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 03/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "hero.h"

#include "global.h"

namespace {
const char* const kFile = GLOBAL_ASSETS_PATH"hero.png";

const int kFrameWidth = 400;
const int kFrameHeight = 400;
const int kMaxFrames = 4;

const int kXSpritePos = global::kScrWidth / 2 - kFrameWidth / 2;
const int kYSpritePos = global::kScrHeight - kFrameHeight - 20;
}  // namespace

Hero::Hero(): surface_(nullptr) {}

bool Hero::Load() {
  surface_ = Surface::Load(kFile);
  if (!surface_)
    return false;
  
  animation_.SetSpriteInfo(kFrameWidth, kFrameHeight, kMaxFrames);
  
  return true;
}

void Hero::Loop() {
  animation_.Animate();
}

void Hero::Render(SDL_Surface* display) {
  animation_.Draw(display, surface_, kXSpritePos, kYSpritePos);
}

void Hero::Cleanup() {
  SDL_FreeSurface(surface_);
}

