//
//  CApp_OnRender.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

void CApp::OnRender() {
    //CSurface::OnDraw(Surf_Display, Surf_Background, 0, 0);
    CSurface::OnDraw(Surf_Display, Surf_Background, CONSTANTS::SCREEN_WIDTH / 2 - CONSTANTS::BACKGROUND_WIDTH / 2, 0);
    
    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;
        
        CEntity::EntityList[i]->OnRender(Surf_Display);
    }
    
    CSurface::OnDraw(Surf_Display, Surf_Pizza1, 0, 0);
    CSurface::OnDraw(Surf_Display, Surf_Pizza2, CONSTANTS::SCREEN_WIDTH / 2 + CONSTANTS::BACKGROUND_WIDTH / 2, 0);
    
    SDL_Flip(Surf_Display);
}
