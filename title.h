//
//  title.h
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_TITLE_H_
#define MY_GAME_TITLE_H_

#include <SDL/SDL.h>
#include <SDL_ttf/SDL_ttf.h>

class Title {
 public:
  Title();
  
  void SetText(const char* text);
  inline void set_front_color(SDL_Color front_color) {
    front_color_ = front_color;
  }
  inline void set_y_front(int y) { y_front_ = y; }
  
  bool Load(int font_size);
  void Render(SDL_Surface* display);
  void Cleanup();
  
 private:
  TTF_Font* font_;
  
  SDL_Surface* s_front_;
  SDL_Surface* s_shadow_;
  
  int x_front_, y_front_;
  
  SDL_Color front_color_;
  
  int offset_;
  
  inline int XCenterCalc() { return x_front_ - s_front_->clip_rect.w / 2; }
};

#endif  // MY_GAME_TITLE_H_
