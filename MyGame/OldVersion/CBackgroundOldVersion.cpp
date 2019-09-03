//
//  CBackgroundOldVersion.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 18/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CBackgroundOldVersion.hpp"
using namespace CONSTANTS;

CBackgroundOldVersion::CBackgroundOldVersion() {
    Surf_Background = NULL;
    Surf_Sides = NULL;
    
    Anim_Control.MaxFrames = 3;
    Anim_Control.SetFrameRate(200);
}

bool CBackgroundOldVersion::OnLoad() {
    if((Surf_Background = CSurfaceOldVersion::OnLoad(BACKGROUND_IMG.c_str())) == NULL)
        return false;
    if((Surf_Sides = CSurfaceOldVersion::OnLoad(SIDES_IMG.c_str())) == NULL)
        return false;
    
    return true;
}

void CBackgroundOldVersion::OnRender(SDL_Surface *Surf_Display) {
    CSurfaceOldVersion::OnDraw(Surf_Display, Surf_Background, CONSTANTS::SCREEN_WIDTH / 2 - CONSTANTS::BACKGROUND_WIDTH / 2, 0);
}

void CBackgroundOldVersion::RenderSides(SDL_Surface* Surf_Display) {
    CSurfaceOldVersion::OnDraw(Surf_Display, Surf_Sides, 0,
                     0,
                     Anim_Control.GetCurrentFrame() * 282, 0, 282, SIDES_HEIGHT);
    
    CSurfaceOldVersion::OnDraw(Surf_Display, Surf_Sides, CONSTANTS::SCREEN_WIDTH / 2 + CONSTANTS::BACKGROUND_WIDTH / 2, 0,
                     Anim_Control.GetCurrentFrame() * 282, 0, 282, SIDES_HEIGHT);
}

void CBackgroundOldVersion::OnCleanup() {
    SDL_FreeSurface(Surf_Background);
    SDL_FreeSurface(Surf_Sides);
}
