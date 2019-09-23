//
//  hero.h
//  MyGame
//
//  Created by Alexander Mordovsky on 03/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_HERO_H_
#define MY_GAME_HERO_H_

#include "animation.h"
#include "burger.h"
#include "entity.h"
#include "location.h"
#include "surface.h"

class Hero: public Entity, public Location {
 public:
  Hero();
  
  inline void ChangeLocation(int location) {
    animation_.set_current_frame_row(location_ = location);
  }
  
  inline bool CanCatch(const Burger& obj) const {
    return obj.CanBeCaught(location_);
  }
  inline void CatchBurger(Burger& obj) { obj.DeleteBurger(location_); }
  
  bool Load();
  void Loop();
  void Render(SDL_Surface* display);
  void Cleanup();
  
 private:
  SDL_Surface* surface_;
  
  Animation animation_;
};

#endif  // MY_GAME_HERO_H_
