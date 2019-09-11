//
//  CApp_OnRender.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

void CApp::render() {
    for(int i = 0;i < CEntityOldVersion::EntityList.size();i++) {
        if(!CEntityOldVersion::EntityList[i]) continue;
        
        CEntityOldVersion::EntityList[i]->OnRender(display);
    }
    
    GameOverTitle.OnRender(display);
    
    //Background.RenderSides(Surf_Display);
    
    SDL_Flip(display);
}
