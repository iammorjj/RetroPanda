//
//  BurgerConstants.h
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef BurgerConstants_h
#define BurgerConstants_h

#include <string>
#include "Global.hpp"
using namespace Global;

namespace burgerConstants {
    const std::string file = Global::path+"burger.png";
    const int frameWidth = 192;
    
    const int lineNumber = 6;
    
    const double xVelNewLevel = 7.;
    const double yVelNewLevel = xVelNewLevel * 4./7.;
    
    const int xStopLeft = 300;
    const int xStopRight = scrWidth - frameWidth - xStopLeft;
    const int xCanBeCaughtLeft = xStopLeft - 15;
    const int xCanBeCaughtRight = xStopRight + 15;
    
    const int xStartLeft = 160;
    const int xStartRight = scrWidth - frameWidth - xStartLeft;
    
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

#endif /* BurgerConstants_h */
