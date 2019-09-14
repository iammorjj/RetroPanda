//
//  Global.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 13/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef GlobalObjects_hpp
#define GlobalObjects_hpp

#include "Timer.hpp"
#include <string>

namespace Global {
    extern Timer tKeyboardDelay;
    const int keyboardDelay = 2000;
    
    const int speedLevelUp = 3;
    const int appearanceLevelUp = 5;
    
    const std::string path =
#ifdef MAC
    "/Users/alexandermordovsky/Documents/XCodeProjects/MyGame/MyGame/Assets/";
#else
    "./Assets/";
#endif
    
}

#endif /* GlobalObjects_hpp */
