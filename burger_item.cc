//
//  burger_item.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 02/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "burger_item.h"

#include "burger_constants.h"

int BurgerItem::x_vel_ = burger_constants::kXVelStart;
int BurgerItem::y_vel_ = burger_constants::kYVelStart;

void BurgerItem::ResetVelocity() {
  x_vel_ = burger_constants::kXVelStart;
  y_vel_ = burger_constants::kYVelStart;
}

BurgerItem::BurgerItem(int location) {
  location_ = location;
  switch (location) {
    case kLeftDown:
      x_ = burger_constants::kXStartLeft; y_ = burger_constants::kYStartDown;
      break;
    case kLeftMid:
      x_ = burger_constants::kXStartLeft; y_ = burger_constants::kYStartMid;
      break;
    case kLeftUp:
      x_ = burger_constants::kXStartLeft; y_ = burger_constants::kYStartUp;
      break;
    
    case kRightDown:
      x_ = burger_constants::kXStartRight; y_ = burger_constants::kYStartDown;
      break;
    case kRightMid:
      x_ = burger_constants::kXStartRight; y_ = burger_constants::kYStartMid;
      break;
    case kRightUp:
      x_ = burger_constants::kXStartRight; y_ = burger_constants::kYStartUp;
      break;
  }
}

inline int BurgerItem::GetXDirectionSign() {
  if (location_ == kLeftDown || location_ == kLeftMid || location_ == kLeftUp)
    return 1;
  
  return -1;
}

inline bool BurgerItem::CanMoveSideway() {
  return !(x_ > burger_constants::kXStopLeft &&
           x_ < burger_constants::kXStopRight);
}

bool BurgerItem::CanMoveDown() {
  switch (location_) {
    case kLeftDown:
    case kRightDown:
      return y_ < burger_constants::kYStopDown;
    case kLeftMid:
    case kRightMid:
      return y_ < burger_constants::kYStopMid;
    case kLeftUp:
    case kRightUp:
      return y_ < burger_constants::kYStopUp;
      
    default: assert(false);
  }
}

void BurgerItem::Move(double delta_ticks) {
  if (CanMoveSideway()) {
    x_ += x_vel_ * (delta_ticks / 1000.0) * GetXDirectionSign();
    y_ += y_vel_ * (delta_ticks / 1000.0);
  } else {
    y_ += burger_constants::kGravity * (delta_ticks / 1000.0);
  }
}

