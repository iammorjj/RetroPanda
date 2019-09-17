//
//  HideEffect.h
//  MyGame
//
//  Created by Alexander Mordovsky on 03/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef HideEffect_h
#define HideEffect_h

#include "SDl/SDL.h"

class HideEffect {
private:
    int oldTime = 0;
    int frameRateMs = 500;
public:
    bool isHide = false;
    
    void hide() {
        if(oldTime + frameRateMs > SDL_GetTicks())
            return;
        
        isHide = !isHide;
        oldTime = SDL_GetTicks();
    }
};

#endif /* HideEffect_h */
