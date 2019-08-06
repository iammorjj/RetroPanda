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
    
    const std::string PATH = "/Users/alexandermordovsky/Documents/XCodeProjects/MyGame/MyGame/Assets/";
    const std::string BACKGROUND_IMG = PATH+"backgroundx2.png";
    const std::string CONVEYOR_IMG = PATH+"conveyorx2.png";
    const std::string HERO_IMG = PATH+"pandax2.png";
}
//
//class Constants {
//public:
//    static const int SCREEN_WIDTH = 144*2;
//    static const int SCREEN_HEIGHT = 240*2;
//    static const int SCREEN_BPP = 32;
//
//    static const int BACKGROUND_WIDTH = 144*2;
//    static const int BACKGROUND_HEIGHT = 240*2;
//
//    static const int CONVEYOR_WIDTH = 60*2;
//    static const int CONVEYOR_HEIGHT = 60*2;
//    static const int CONVEYOR_MAX_FRAMES = 16;
//
//    static const int HERO_WIDTH = 100*2;
//    static const int HERO_HEIGHT = 100*2;
//    static const int HERO_MAX_FRAMES = 4;
//
//    static const std::string PATH;
//
////    constexpr static char* BACKGROUND_IMG = "/Users/alexandermordovsky/Documents/XCodeProjects/MyGame/MyGame/Assets/background.png";
//    static const std::string BACKGROUND_IMG;// = PATH+"backgroundx2.png";
////    constexpr static char* CONVEYOR_IMG = "/Users/alexandermordovsky/Documents/XCodeProjects/MyGame/MyGame/Assets/conveyor.png";
//    static const std::string CONVEYOR_IMG;// = PATH+"conveyorx2.png";
//
//    static const std::string HERO_IMG;// = PATH+"pandax2.png";
//};
//
//const std::string Constants::PATH = "Users/alexandermordovsky/Documents/XCodeProjects/MyGame/MyGame/Assets/";
//const std::string Constants::BACKGROUND_IMG = PATH+"backgroundx2.png";
//const std::string Constants::CONVEYOR_IMG = PATH+"conveyorx2.png";
//const std::string Constants::HERO_IMG = PATH+"pandax2.png";


#endif /* Constants_h */
