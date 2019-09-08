//
//  BurgerItem.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 02/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "BurgerItem.hpp"
#include "Constants.h"
using namespace CONSTANTS;

namespace {
    const int xStartLeft = 160;
    const int xStartRight = SCREEN_WIDTH - BURGER::BURGER_WIDTH - xStartLeft;
    const int xStopLeft = 300;
    const int xStopRight = SCREEN_WIDTH - BURGER::BURGER_WIDTH - xStopLeft;
    
    const int yDistanceBetweenLines = 120;
    const int yStartUp = 140;
    const int yStartMid = yStartUp + yDistanceBetweenLines;
    const int yStartDown = yStartMid + yDistanceBetweenLines;
    const int yStopUp = 265;
    const int yStopMid = yStopUp + yDistanceBetweenLines;
    const int yStopDown = yStopMid + yDistanceBetweenLines;
    
    const int gravity = 50;
    const int xVelStart = 70;
    const int yVelStart = 40;
}

double BurgerItem::xVel = xVelStart;
double BurgerItem::yVel = yVelStart;

BurgerItem::BurgerItem(int location) {
    this->location = location;
    
    switch(location) {
        case LEFT_DOWN:
            x = xStartLeft; y = yStartDown;
            break;
        case LEFT_MID:
            x = xStartLeft; y = yStartMid;
            break;
        case LEFT_UP:
            x = xStartLeft; y = yStartUp;
            break;
            
        case RIGHT_DOWN:
            x = xStartRight; y = yStartDown;
            break;
        case RIGHT_MID:
            x = xStartRight; y = yStartMid;
            break;
        case RIGHT_UP:
            x = xStartRight; y = yStartUp;
            break;
    }
}

bool BurgerItem::canMoveSideway() {
    return !(x > xStopLeft && x < xStopRight);
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
        y += gravity * ( deltaTicks / 1000.0 );
    }
}

bool BurgerItem::canMoveDown() {
    switch(this->location) {
        case LEFT_DOWN:
        case RIGHT_DOWN:
            return y < yStopDown;
        case LEFT_MID:
        case RIGHT_MID:
            return y < yStopMid;
        case LEFT_UP:
        case RIGHT_UP:
            return y < yStopUp;
            
        default: return false;
    }
}

bool BurgerItem::isGameOver() {
    return !canMoveDown();
}

