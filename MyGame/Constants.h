//
//  Constants.h
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Constants_h
#define Constants_h

class Constants {
public:
    static const int SCREEN_WIDTH = 144*2;
    static const int SCREEN_HEIGHT = 240*2;
    static const int SCREEN_BPP = 32;
    
    static const int BACKGROUND_WIDTH = 144*2;
    static const int BACKGROUND_HEIGHT = 240*2;
    
    static const int CONVEYOR_WIDTH = 60*2;
    static const int CONVEYOR_HEIGHT = 60*2;
    static const int CONVEYOR_MAX_FRAMES = 16;
    
    static const int HERO_WIDTH = 100*2;
    static const int HERO_HEIGHT = 100*2;
    static const int HERO_MAX_FRAMES = 4;
    
//    constexpr static char* BACKGROUND_IMG = "/Users/alexandermordovsky/Documents/XCodeProjects/MyGame/MyGame/Assets/background.png";
    constexpr static char* BACKGROUND_IMG = "/Users/alexandermordovsky/Documents/XCodeProjects/MyGame/MyGame/Assets/backgroundx2.png";
//    constexpr static char* CONVEYOR_IMG = "/Users/alexandermordovsky/Documents/XCodeProjects/MyGame/MyGame/Assets/conveyor.png";
    constexpr static char* CONVEYOR_IMG = "/Users/alexandermordovsky/Documents/XCodeProjects/MyGame/MyGame/Assets/conveyorx2.png";
    
    constexpr static char* HERO_IMG = "/Users/alexandermordovsky/Documents/XCodeProjects/MyGame/MyGame/Assets/pandax2.png";
};


#endif /* Constants_h */
