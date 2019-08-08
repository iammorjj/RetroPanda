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
#include <vector>

struct Coordinate {
    int x, y;
    Coordinate(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
};

class Burger {
public:
    Coordinate coord;
public:
    Burger(LOCATION location) {
        switch(location) {
            case LEFT_DOWN: coord = Coordinate(CONSTANTS::BURGER::START_BURGER_X_LEFT, CONSTANTS::BURGER::START_BURGER_Y_UP + CONSTANTS::BURGER::VERTICAL_DISTANCE_BETWEEN_BURGERS * 2);
                break;
            case LEFT_MID: coord = Coordinate(CONSTANTS::BURGER::START_BURGER_X_LEFT, CONSTANTS::BURGER::START_BURGER_Y_UP + CONSTANTS::BURGER::VERTICAL_DISTANCE_BETWEEN_BURGERS);
                break;
            case LEFT_UP: coord = Coordinate(CONSTANTS::BURGER::START_BURGER_X_LEFT, CONSTANTS::BURGER::START_BURGER_Y_UP);
                break;
                
            case RIGHT_DOWN: break;
            case RIGHT_MID: break;
            case RIGHT_UP: coord = Coordinate(CONSTANTS::BURGER::START_BURGER_X_RIGHT, CONSTANTS::BURGER::START_BURGER_Y_UP);
                break;
        }
    }
};

class Conveyor {
    friend class CBurger;
private:
    std::vector<Burger> burger;
    LOCATION location;
private:
    static int locationInitCounter;
public:
    Conveyor() { location = (LOCATION) locationInitCounter++; }
    void addBurger() {
        burger.push_back(Burger(location));
    }
};

#endif /* Conveyor_hpp */
