//
//  BurgerOldVersion.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 08/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Burger_hpp
#define Burger_hpp

#include "Constants.h"
#include "LocationOldVersion.h"

using namespace CONSTANTS::BURGER;

class BurgerOldVersion: public LocationClassOldVersion {
private:
    int xDirectionSign();
public:
    static double xVel;
    static double yVel;
    
    BurgerOldVersion(LocationOldVersion location = LEFT_DOWN);
    
    bool canMoveSideway();
    
    bool canMoveDown();
    
    bool isGameOver();
    
    void move(double deltaTicks);
};

#endif /* Burger_hpp */
