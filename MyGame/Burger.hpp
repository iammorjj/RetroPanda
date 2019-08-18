//
//  Burger.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 08/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Burger_hpp
#define Burger_hpp

#include "Constants.h"
#include "Location.h"

using namespace CONSTANTS::BURGER;

struct Coordinate {
    int x, y;
    Coordinate(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
};

class Burger: public LocationClass {
private:
    int xDirectionSign();
public:
    static double xVel;
    static double yVel;
    
    Burger(Location location = LEFT_DOWN);
    
    bool canMoveSideway();
    
    bool canMoveDown();
    
    bool isGameOver();
    
    void move(double deltaTicks);
};

#endif /* Burger_hpp */
