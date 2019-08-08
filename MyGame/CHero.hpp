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

class CHero: public CEntity {
public:

    CHero() {
        X = CONSTANTS::SCREEN_WIDTH / 2.0 - CONSTANTS::HERO_WIDTH / 2.0;
        Y = CONSTANTS::SCREEN_HEIGHT - CONSTANTS::HERO_HEIGHT - 20;
    }
    
    void OnRender(SDL_Surface* Surf_Display) {
        if(Surf_Entity == NULL || Surf_Display == NULL) return;

        CSurface::OnDraw(Surf_Display, Surf_Entity, X, Y,
                         Anim_Control.GetCurrentFrame() * Width, CurrentFrameRow * Height, Width, Height);
    }
    
    void MoveLeftDown() { CurrentFrameRow = 0; }
    void MoveLeftMid() { CurrentFrameRow = 2; }
    void MoveLeftUp() { CurrentFrameRow = 4; }
    void MoveRightDown() { CurrentFrameRow = 1; }
    void MoveRightMid() { CurrentFrameRow = 3; }
    void MoveRightUp() { CurrentFrameRow = 5; }
    
};

#endif /* CHero_hpp */
