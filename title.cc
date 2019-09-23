//
//  title.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "title.h"

#include "global.h"
#include "surface.h"

namespace {
const char* const kFile = GLOBAL_ASSETS_PATH"acknowtt.ttf";
}  // namespace

Title::Title()
    : font_(nullptr),
      s_front_(nullptr),
      s_shadow_(nullptr),
      x_front_(global::kScrWidth / 2),
      y_front_(0),
      front_color_(global::kWhiteColor),
      offset_(5) {}

void Title::SetText(const char* text) {
  s_front_ = TTF_RenderText_Solid(font_, text, front_color_);
  s_shadow_ = TTF_RenderText_Solid(font_, text, global::kShadowColor);
}

bool Title::Load(int fontSize) {
  return font_ = TTF_OpenFont(kFile, fontSize);
}

void Title::Render(SDL_Surface* display) {
  Surface::Draw(display, s_shadow_,
                XCenterCalc() + offset_, y_front_ + offset_);
  Surface::Draw(display, s_front_, XCenterCalc(), y_front_);
}

void Title::Cleanup() {
  if (s_front_) SDL_FreeSurface(s_front_);
  if (s_shadow_) SDL_FreeSurface(s_shadow_);
  if (font_) TTF_CloseFont(font_);
}
