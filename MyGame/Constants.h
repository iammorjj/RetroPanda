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

enum Location {LEFT_DOWN,LEFT_MID,LEFT_UP,
    RIGHT_DOWN,RIGHT_MID,RIGHT_UP
};

namespace GLOBAL {
    extern bool GameOver;
}

// coef angle conveyor = 1.75

namespace CONSTANTS
{
    // NOT CONSTANT FUCK REPLACE IT
    //int score = 0;
    
    const int SCREEN_WIDTH = 144*2;
    const int SCREEN_HEIGHT = 240*2;
    const int SCREEN_BPP = 32;
    
    const int BACKGROUND_WIDTH = 144*2;
    const int BACKGROUND_HEIGHT = 240*2;
    
//    const int SCREEN_WIDTH = 1024;
//    const int SCREEN_HEIGHT = 768;
//    const int SCREEN_BPP = 32;
//
//    const int BACKGROUND_WIDTH = 461;
//    const int BACKGROUND_HEIGHT = 768;
    
    const int CONVEYORS_NUM = 6;
    
    const int CONVEYOR_WIDTH = 60*2;
    const int CONVEYOR_HEIGHT = 60*2;
    const int CONVEYOR_MAX_FRAMES = 16;
    
    const int HERO_WIDTH = 100*2.5;
    const int HERO_HEIGHT = 100*2.5;
    const int HERO_MAX_FRAMES = 4;
    
    const std::string PATH = "/Users/alexandermordovsky/Documents/XCodeProjects/MyGame/MyGame/Assets/";
    
    const std::string BACKGROUND_IMG = PATH+"backgroundx2.png";
    const std::string CONVEYOR_IMG = PATH+"conveyorx2.png";
    const std::string HERO_IMG = PATH+"pandax25.png";
    const std::string BURGER_IMG = PATH+"burgerx2.png";
    const std::string FONT = PATH+"acknowtt.ttf";
    
    namespace BURGER {
        const int BURGER_WIDTH = 60*2;
        const int BURGER_HEIGHT = 60*2;
        const int BURGER_MAX_FRAMES = 1;
        
        const int VERTICAL_DISTANCE_BETWEEN_BURGERS = 75;
        const int LEFT_SIDE_COORD = 40;
        const int RIGHT_SIDE_COORD = SCREEN_WIDTH - BURGER_WIDTH + 12;
        const int TOP_COORD = 120;
        
        const int START_BURGER_X_LEFT = -74;
        const int START_BURGER_X_RIGHT = BACKGROUND_WIDTH - BURGER_WIDTH - START_BURGER_X_LEFT;
        const int START_BURGER_Y_UP = 80;
        
        const int STOP_BURGER_X_LEFT = 20;
        const int STOP_BURGER_X_RIGHT = BACKGROUND_WIDTH - BURGER_WIDTH - STOP_BURGER_X_LEFT;
        const int HERO_CAN_TAKE_X_LEFT = STOP_BURGER_X_LEFT - 5;
        const int HERO_CAN_TAKE_X_RIGHT = STOP_BURGER_X_RIGHT + 5;
        const int STOP_BURGER_Y_UP = 165;
        
        const int FRAME_RATE_GRAVITY = 20;
        
        const int X_VEL_START = 35;
        const int Y_VEL_START = 20;
        const int GRAVITY = 35;
        const int CREATE_NEW_BURGER_DELAY_START = 2400;
    }
}

#endif /* Constants_h */
