//
//  CApp_OnCleanup.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

void CApp::OnCleanup() {
    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;
        
        CEntity::EntityList[i]->OnCleanup();
    }
    
    CEntity::EntityList.clear();
    
    SDL_FreeSurface(Surf_Display);
    
    Music.OnCleanup();
    
    SDL_Quit();
}
