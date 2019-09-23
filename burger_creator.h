//
//  burger_creator.h
//  MyGame
//
//  Created by Alexander Mordovsky on 12/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_BURGERCREATOR_H_
#define MY_GAME_BURGERCREATOR_H_

#include <SDL/SDL.h>

class Burger;

class BurgerCreator {
 public:
  BurgerCreator(Burger* burger);
  
  void CreateBurger();
  
  void ResetDelay();
  
  void Start();
  void Stop();
  void RestartTimer();
  
  void ChangeDelay();
  
 private:
  SDL_TimerID timer_;
  Uint32 delay_;
  
  bool is_delay_changed_;
  
  Burger* burger_;
};

#endif  // MY_GAME_BURGERCREATOR_H_
