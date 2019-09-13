//
//  GlobalObjects.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 13/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef GlobalObjects_hpp
#define GlobalObjects_hpp

#include "Timer.hpp"

namespace GlobalObjects {
    extern Timer tKeyboardDelay;
    const int keyboardDelay = 2000;
    
    const int speedLevelUp = 3;
    const int appearanceLevelUp = 5;
}

#endif /* GlobalObjects_hpp */
