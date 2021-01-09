//
//  background.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 10/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "background.h"

#include "global.h"
#include "surface.h"

namespace {
const char* const kFile = GLOBAL_ASSETS_PATH"background.png";

const int kBackgroundWidth = 461;

const int kX = global::kScrWidth / 2 - kBackgroundWidth / 2;
const int kY = 0;
}  // namespace

Background::Background() : surface_(nullptr) {}

bool Background::Load() {
  surface_ = Surface::Load(kFile);
  
  return surface_ != nullptr;
}

void Background::Loop() {}

void Background::Render(SDL_Surface* display) {
    Surface::Draw(display, surface_, kX, kY);
}

void Background::Cleanup() {
    SDL_FreeSurface(surface_);
}
