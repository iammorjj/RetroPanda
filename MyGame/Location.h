//
//  Location.h
//  MyGame
//
//  Created by Alexander Mordovsky on 09/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Location_h
#define Location_h

enum Location {LEFT_DOWN,LEFT_MID,LEFT_UP,
    RIGHT_DOWN,RIGHT_MID,RIGHT_UP
};

#include "Constants.h"

class LocationClass {
public:
    double x, y;
    Location location;
//public:
//    enum {LEFT_DOWN,LEFT_MID,LEFT_UP,
//        RIGHT_DOWN,RIGHT_MID,RIGHT_UP
//    } location;
public:
    
    static bool isHeroCollision(LocationClass& burger) {
        
        return burger.x > CONSTANTS::BURGER::HERO_CAN_TAKE_X_LEFT && burger.x < CONSTANTS::BURGER::HERO_CAN_TAKE_X_RIGHT;
    };
};

#endif /* Location_h */
