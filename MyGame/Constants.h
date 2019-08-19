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

namespace CONSTANTS
{
    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 768;
    const int SCREEN_BPP = 32;
    
    const int BACKGROUND_WIDTH = 461;
    const int BACKGROUND_HEIGHT = 768;
    
    const int CONVEYOR_WIDTH = 192;
    const int CONVEYOR_HEIGHT = 192;
    const int CONVEYOR_MAX_FRAMES = 16;
    
    const int VERTICAL_DISTANCE_BETWEEN_CONVEYORS = 120;
    const int LEFT_SIDE_COORD = CONSTANTS::SCREEN_WIDTH / 2. - CONSTANTS::BACKGROUND_WIDTH / 2. - 60;
    const int RIGHT_SIDE_COORD = CONSTANTS::SCREEN_WIDTH / 2. + 90;
    const int TOP_COORD = 200;
    
    const int CONVEYORS_NUM = 6;
    
    const int HERO_WIDTH = 400;
    const int HERO_HEIGHT = 400;
    const int HERO_MAX_FRAMES = 4;
    
    const int PIZZA_WIDTH = 282;
    const int PIZZA_HEIGHT = 768;
    
    const std::string PATH = "/Users/alexandermordovsky/Documents/XCodeProjects/MyGame/MyGame/Assets/1024x768/";
    
    const std::string FONT = PATH+"acknowtt.ttf";
    
    const std::string BACKGROUND_IMG = PATH+"background.png";
    const std::string CONVEYOR_IMG = PATH+"conveyor.png";
    const std::string HERO_IMG = PATH+"hero.png";
    const std::string BURGER_IMG = PATH+"burger.png";
    const std::string PIZZA1_IMG = PATH+"pizza1.png";
    const std::string PIZZA2_IMG = PATH+"pizza2.png";
    const std::string MUSIC = PATH+"music.wav";
    
    namespace BURGER {
        const int BURGER_WIDTH = 192;
        const int BURGER_HEIGHT = 192;
        const int BURGER_MAX_FRAMES = 1;
        
        const int VERTICAL_DISTANCE_BETWEEN_BURGERS = 120;
//            const int LEFT_SIDE_COORD = 500;
//            const int RIGHT_SIDE_COORD = 600;//SCREEN_WIDTH - BURGER_WIDTH + 38;
//            const int TOP_COORD = 190;
        
        const int START_BURGER_X_LEFT = 160;//-237;
        const int START_BURGER_X_RIGHT = SCREEN_WIDTH - BURGER_WIDTH - START_BURGER_X_LEFT;//BACKGROUND_WIDTH - BURGER_WIDTH - START_BURGER_X_LEFT;
        const int START_BURGER_Y_UP = 140;
        
        const int STOP_BURGER_X_LEFT = 300;
        const int STOP_BURGER_X_RIGHT = SCREEN_WIDTH - BURGER_WIDTH - STOP_BURGER_X_LEFT;
        const int HERO_CAN_TAKE_X_LEFT = STOP_BURGER_X_LEFT - 15;
        const int HERO_CAN_TAKE_X_RIGHT = STOP_BURGER_X_RIGHT + 15;
        const int STOP_BURGER_Y_UP = 265;
        
        const int X_VEL_START = 70;
        const int Y_VEL_START = 40;
        const int GRAVITY = 50;
        const int CREATE_NEW_BURGER_DELAY_START = 2300;
    }
}

#endif /* Constants_h */
