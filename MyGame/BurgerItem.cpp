//
//  BurgerItem.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 02/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "BurgerItem.hpp"

BurgerItem::BurgerItem(int location) {
    this->location = location;
    
    switch(location) {
        case LEFT_DOWN:
            x = START_BURGER_X_LEFT; y = START_BURGER_Y_UP + VERTICAL_DISTANCE_BETWEEN_BURGERS * 2;
            break;
        case LEFT_MID:
            x = START_BURGER_X_LEFT; y = START_BURGER_Y_UP + VERTICAL_DISTANCE_BETWEEN_BURGERS;
            break;
        case LEFT_UP:
            x = START_BURGER_X_LEFT; y = START_BURGER_Y_UP;
            break;
            
        case RIGHT_DOWN:
            x = START_BURGER_X_RIGHT; y = START_BURGER_Y_UP + VERTICAL_DISTANCE_BETWEEN_BURGERS * 2;
            break;
        case RIGHT_MID:
            x = START_BURGER_X_RIGHT; y = START_BURGER_Y_UP + VERTICAL_DISTANCE_BETWEEN_BURGERS;
            break;
        case RIGHT_UP:
            x = START_BURGER_X_RIGHT; y = START_BURGER_Y_UP;
            break;
    }
}

bool BurgerItem::canMoveSideway() {
    return !(x > STOP_BURGER_X_LEFT && x < STOP_BURGER_X_RIGHT);
}

int BurgerItem::xDirectionSign() {
    if(location == LEFT_DOWN || location == LEFT_MID || location == LEFT_UP)
        return 1;
    
    return -1;
}

void BurgerItem::move(double deltaTicks) {
    if(canMoveSideway()) {
        x += xVel * ( deltaTicks / 1000.0 ) * xDirectionSign();
        y += yVel * ( deltaTicks / 1000.0 );
    } else {
        y += GRAVITY * ( deltaTicks / 1000.0 );
    }
}

bool BurgerItem::canMoveDown() {
    switch(this->location) {
        case LEFT_DOWN:
        case RIGHT_DOWN:
            if(y < STOP_BURGER_Y_UP + VERTICAL_DISTANCE_BETWEEN_BURGERS * 2) return true;
            return false;
        case LEFT_MID:
        case RIGHT_MID:
            if(y < STOP_BURGER_Y_UP + VERTICAL_DISTANCE_BETWEEN_BURGERS) return true;
            return false;
        case LEFT_UP:
        case RIGHT_UP:
            if(y < STOP_BURGER_Y_UP) return true;
            return false;
            
    }
}

bool BurgerItem::isGameOver() {
    return !canMoveDown();
}

