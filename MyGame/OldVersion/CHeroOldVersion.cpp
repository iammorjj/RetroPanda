//
//  CHeroOldVersion.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CHeroOldVersion.hpp"

CHeroOldVersion::CHeroOldVersion() {
    X = CONSTANTS::SCREEN_WIDTH / 2.0 - CONSTANTS::HERO_WIDTH / 2.0;
    Y = CONSTANTS::SCREEN_HEIGHT - CONSTANTS::HERO_HEIGHT - 20;
    
    location = LEFT_DOWN;
}

void CHeroOldVersion::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_Entity == NULL || Surf_Display == NULL) return;
    
    Surface::draw(Surf_Display, Surf_Entity, X, Y,
                     Anim_Control.GetCurrentFrame() * Width, CurrentFrameRow * Height, Width, Height);
//    CSurfaceOldVersion::OnDraw(Surf_Display, Surf_Entity, X, Y,
//                     anim.GetCurrentFrame() * Width, CurrentFrameRow * Height, Width, Height);
}

void CHeroOldVersion::MoveLeftDown() { CurrentFrameRow = 0; location = LEFT_DOWN; }
void CHeroOldVersion::MoveLeftMid() { CurrentFrameRow = 2; location = LEFT_MID; }
void CHeroOldVersion::MoveLeftUp() { CurrentFrameRow = 4; location = LEFT_UP; }
void CHeroOldVersion::MoveRightDown() { CurrentFrameRow = 1; location = RIGHT_DOWN; }
void CHeroOldVersion::MoveRightMid() { CurrentFrameRow = 3; location = RIGHT_MID; }
void CHeroOldVersion::MoveRightUp() { CurrentFrameRow = 5; location = RIGHT_UP; }
