//
//  CBackground.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 18/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CBackground.hpp"
using namespace CONSTANTS;

CBackground::CBackground() {
    Surf_Background = NULL;
    Surf_Sides = NULL;
    
    Anim_Control.MaxFrames = 3;
    Anim_Control.SetFrameRate(200);
}

bool CBackground::OnLoad() {
    if((Surf_Background = CSurface::OnLoad(BACKGROUND_IMG.c_str())) == NULL)
        return false;
    if((Surf_Sides = CSurface::OnLoad(SIDES_IMG.c_str())) == NULL)
        return false;
    
    return true;
}

void CBackground::OnRender(SDL_Surface *Surf_Display) {
    CSurface::OnDraw(Surf_Display, Surf_Background, CONSTANTS::SCREEN_WIDTH / 2 - CONSTANTS::BACKGROUND_WIDTH / 2, 0);
}

void CBackground::RenderSides(SDL_Surface* Surf_Display) {
    CSurface::OnDraw(Surf_Display, Surf_Sides, 0,
                     0,
                     Anim_Control.GetCurrentFrame() * 282, 0, 282, SIDES_HEIGHT);
    
    CSurface::OnDraw(Surf_Display, Surf_Sides, CONSTANTS::SCREEN_WIDTH / 2 + CONSTANTS::BACKGROUND_WIDTH / 2, 0,
                     Anim_Control.GetCurrentFrame() * 282, 0, 282, SIDES_HEIGHT);
}

void CBackground::OnCleanup() {
    SDL_FreeSurface(Surf_Background);
    SDL_FreeSurface(Surf_Sides);
}
