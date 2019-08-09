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

using namespace CONSTANTS::BURGER;

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
    Location location;
public:
    Burger(Location location) {
        this->location = location;
        
        switch(location) {
            case LEFT_DOWN:
                coord = Coordinate(START_BURGER_X_LEFT, START_BURGER_Y_UP + VERTICAL_DISTANCE_BETWEEN_BURGERS * 2);
                break;
            case LEFT_MID:
                coord = Coordinate(START_BURGER_X_LEFT, START_BURGER_Y_UP + VERTICAL_DISTANCE_BETWEEN_BURGERS);
                break;
            case LEFT_UP:
                coord = Coordinate(START_BURGER_X_LEFT, START_BURGER_Y_UP);
                break;
                
            case RIGHT_DOWN:
                coord = Coordinate(START_BURGER_X_RIGHT, START_BURGER_Y_UP + VERTICAL_DISTANCE_BETWEEN_BURGERS * 2);
                break;
            case RIGHT_MID:
                coord = Coordinate(START_BURGER_X_RIGHT, START_BURGER_Y_UP + VERTICAL_DISTANCE_BETWEEN_BURGERS);
                break;
            case RIGHT_UP:
                coord = Coordinate(START_BURGER_X_RIGHT, START_BURGER_Y_UP);
                break;
        }
    }
    
    bool canMoveSideway() {
        return !(coord.x > STOP_BURGER_X_LEFT && coord.x < STOP_BURGER_X_RIGHT);
    }
    
    bool canMoveDown() {
        switch(location) {
            case LEFT_DOWN:
            case RIGHT_DOWN:
                if(coord.y < STOP_BURGER_Y_UP + VERTICAL_DISTANCE_BETWEEN_BURGERS * 2) return true;
                return false;
            case LEFT_MID:
            case RIGHT_MID:
                if(coord.y < STOP_BURGER_Y_UP + VERTICAL_DISTANCE_BETWEEN_BURGERS) return true;
                return false;
            case LEFT_UP:
            case RIGHT_UP:
               if(coord.y < STOP_BURGER_Y_UP) return true;
               return false;
                
        }
    }
    
    bool isGameOver() {
        return !canMoveDown();
    }
    
    bool isTakenByHero() {
        if(coord.x > HERO_CAN_TAKE_X_LEFT && coord.x < HERO_CAN_TAKE_X_RIGHT) {
            //CONSTANTS::score++;
            return true;
        }
        
        return false;
    }
    
};

#endif /* Burger_hpp */
