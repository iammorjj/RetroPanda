//
//  Conveyor.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 08/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Conveyor_hpp
#define Conveyor_hpp

#include "Constants.h"
#include "Burger.hpp"
#include <vector>

class Conveyor {
    friend class CBurger;
private:
    std::vector<Burger> burger;
    Location location;
private:
    static int locationInitCounter;
public:
    Conveyor() { location = (Location) locationInitCounter++; }
    void addBurger() {
        burger.push_back(Burger(location));
    }
    
    bool isLeftSide() {
        return location == LEFT_DOWN || location == LEFT_MID || location == LEFT_UP;
    }
    bool isRightSide() {
        return location == RIGHT_DOWN || location == RIGHT_MID || location == RIGHT_UP;
    }
};

#endif /* Conveyor_hpp */
