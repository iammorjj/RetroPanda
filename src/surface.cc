//
//  surface.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "surface.h"

SDL_Surface* Surface::Load(const char* const file) {
  SDL_Surface* s_temp = nullptr;
  SDL_Surface* s_return = nullptr;
  
  s_temp = IMG_Load(file);
  if (!s_temp) return nullptr;
  
  s_return = SDL_DisplayFormatAlpha(s_temp);
  SDL_FreeSurface(s_temp);
  
  return s_return;
}

void Surface::Draw(SDL_Surface* s_destination, SDL_Surface* s_source,
                   int x, int y) {
  if(s_destination == nullptr || s_source == nullptr) return;
  
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  
  SDL_BlitSurface(s_source, nullptr, s_destination, &rect);
}

void Surface::Draw(SDL_Surface* s_destination, SDL_Surface* s_source,
                   int x_destination, int y_destination,
                   int x_source, int y_source, int width, int height) {
  if(s_destination == nullptr || s_source == nullptr) return;
  
  SDL_Rect dest_rect;
  dest_rect.x = x_destination;
  dest_rect.y = y_destination;
  
  SDL_Rect src_rect;
  src_rect.x = x_source;
  src_rect.y = y_source;
  src_rect.w = width;
  src_rect.h = height;
  
  SDL_BlitSurface(s_source, &src_rect, s_destination, &dest_rect);
}
