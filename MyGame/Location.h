//
//  Location.h
//  MyGame
//
//  Created by Alexander Mordovsky on 09/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Location_h
#define Location_h

class LocationClass {
public:
    int x, y;
    Location location;
public:
    
    static bool isHeroCollision(LocationClass& burger) {
        return burger.x > CONSTANTS::BURGER::HERO_CAN_TAKE_X_LEFT && burger.x < CONSTANTS::BURGER::HERO_CAN_TAKE_X_RIGHT;
    };
};

#endif /* Location_h */
