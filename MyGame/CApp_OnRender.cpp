//
//  CApp_OnRender.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

void CApp::OnRender() {
    CSurface::OnDraw(Surf_Display, Surf_Background, 0, 0);
    
//    CSurface::OnDraw(Surf_Display, Surf_Conveyor, Constants::BACKGROUND_WIDTH-Constants::CONVEYOR_WIDTH, Constants::BACKGROUND_HEIGHT/2.0, conveyor.GetCurrentFrame() * Constants::CONVEYOR_WIDTH, 0, Constants::CONVEYOR_WIDTH, Constants::CONVEYOR_HEIGHT);
//    CSurface::OnDraw(Surf_Display, Surf_Conveyor, 97, 97, conveyor.GetCurrentFrame() * Constants::CONVEYOR_WIDTH, 0, Constants::CONVEYOR_WIDTH, Constants::CONVEYOR_HEIGHT);
//
    
    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;
        
        CEntity::EntityList[i]->OnRender(Surf_Display);
    }
    
    SDL_Flip(Surf_Display);
}
