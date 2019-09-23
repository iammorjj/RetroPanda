//
//  burger_item.h
//  MyGame
//
//  Created by Alexander Mordovsky on 02/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_BURGER_ITEM_H_
#define MY_GAME_BURGER_ITEM_H_

#include "location.h"

class BurgerItem: public Location {
 public:
  explicit BurgerItem(int location);
  
  static int x_vel_;
  static int y_vel_;
  
  static void ResetVelocity();
  
  bool CanMoveSideway();
  bool CanMoveDown();
  void Move(double delta_ticks);
  
  inline bool IsGameOver() { return !CanMoveDown(); }
  
 private:
  int GetXDirectionSign();
};

#endif  // MY_GAME_BURGER_ITEM_H_
