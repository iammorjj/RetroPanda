//
//  CHero.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CHero.hpp"

CHero::CHero() {
    X = CONSTANTS::SCREEN1024X768::SCREEN_WIDTH / 2.0 - CONSTANTS::SCREEN1024X768::HERO_WIDTH / 2.0;
    Y = CONSTANTS::SCREEN1024X768::SCREEN_HEIGHT - CONSTANTS::SCREEN1024X768::HERO_HEIGHT - 20;
    
    location = LEFT_DOWN;
}

void CHero::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_Entity == NULL || Surf_Display == NULL) return;
    
    CSurface::OnDraw(Surf_Display, Surf_Entity, X, Y,
                     Anim_Control.GetCurrentFrame() * Width, CurrentFrameRow * Height, Width, Height);
}

void CHero::MoveLeftDown() { CurrentFrameRow = 0; location = LEFT_DOWN; }
void CHero::MoveLeftMid() { CurrentFrameRow = 2; location = LEFT_MID; }
void CHero::MoveLeftUp() { CurrentFrameRow = 4; location = LEFT_UP; }
void CHero::MoveRightDown() { CurrentFrameRow = 1; location = RIGHT_DOWN; }
void CHero::MoveRightMid() { CurrentFrameRow = 3; location = RIGHT_MID; }
void CHero::MoveRightUp() { CurrentFrameRow = 5; location = RIGHT_UP; }
