//
//  CApp_OnCleanup.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

void CApp::OnCleanup() {
    for(int i = 0;i < CEntityOldVersion::EntityList.size();i++) {
        if(!CEntityOldVersion::EntityList[i]) continue;
        
        CEntityOldVersion::EntityList[i]->OnCleanup();
    }
    
    CEntityOldVersion::EntityList.clear();
    
    Music.OnCleanup();
    
    SDL_FreeSurface(Surf_Display);
    
    SDL_Quit();
}
