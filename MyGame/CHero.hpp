//
//  CHero.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CHero_hpp
#define CHero_hpp

#include "CEntity.hpp"
#include "Location.h"

class CHero: public CEntity, public LocationClass {
public:
    Location location;
public:

    CHero() {
        X = CONSTANTS::SCREEN_WIDTH / 2.0 - CONSTANTS::HERO_WIDTH / 2.0;
        Y = CONSTANTS::SCREEN_HEIGHT - CONSTANTS::HERO_HEIGHT - 20;
        
        location = LEFT_DOWN;
    }
    
    void OnRender(SDL_Surface* Surf_Display) {
        if(Surf_Entity == NULL || Surf_Display == NULL) return;

        CSurface::OnDraw(Surf_Display, Surf_Entity, X, Y,
                         Anim_Control.GetCurrentFrame() * Width, CurrentFrameRow * Height, Width, Height);
    }
    
    void MoveLeftDown() { CurrentFrameRow = 0; location = LEFT_DOWN; }
    void MoveLeftMid() { CurrentFrameRow = 2; location = LEFT_MID; }
    void MoveLeftUp() { CurrentFrameRow = 4; location = LEFT_UP; }
    void MoveRightDown() { CurrentFrameRow = 1; location = RIGHT_DOWN; }
    void MoveRightMid() { CurrentFrameRow = 3; location = RIGHT_MID; }
    void MoveRightUp() { CurrentFrameRow = 5; location = RIGHT_UP; }
    
};

#endif /* CHero_hpp */
