//
//  location.h
//  MyGame
//
//  Created by Alexander Mordovsky on 28/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_LOCATION_H_
#define MY_GAME_LOCATION_H_

class Location {
 public:
  enum { kLeftDown = 0, kLeftMid, kLeftUp,
    kRightDown, kRightMid, kRightUp
  };
  
  inline double x() const { return x_; }
  inline double y() const { return y_; }
  
protected:
  double x_ = 0, y_ = 0;
  
  int location_ = kLeftDown;
};

#endif  // MY_GAME_LOCATION_H_
