//
//  Constants.h
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Constants_h
#define Constants_h

#include <string>
#include <iostream>

namespace Constants
{
    const int SCREEN_WIDTH = 144*2;
    const int SCREEN_HEIGHT = 240*2;
    const int SCREEN_BPP = 32;
    
    const int BACKGROUND_WIDTH = 144*2;
    const int BACKGROUND_HEIGHT = 240*2;
    
    const int CONVEYOR_WIDTH = 60*2;
    const int CONVEYOR_HEIGHT = 60*2;
    const int CONVEYOR_MAX_FRAMES = 16;
    
    const int HERO_WIDTH = 100*2;
    const int HERO_HEIGHT = 100*2;
    const int HERO_MAX_FRAMES = 4;
    
    const int BURGER_WIDTH = 60*2;
    const int BURGER_HEIGHT = 60*2;
    const int BURGER_MAX_FRAMES = 1;
    
    const std::string PATH = "/Users/alexandermordovsky/Documents/XCodeProjects/MyGame/MyGame/Assets/";
    
    const std::string BACKGROUND_IMG = PATH+"backgroundx2.png";
    const std::string CONVEYOR_IMG = PATH+"conveyorx2.png";
    const std::string HERO_IMG = PATH+"pandax2.png";
    const std::string BURGER_IMG = PATH+"burgerx2.png";
}

#endif /* Constants_h */
