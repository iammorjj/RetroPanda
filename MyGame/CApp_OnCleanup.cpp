//
//  CApp_OnCleanup.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

void CApp::cleanup() {
    for(int i = 0; i < Entity::entityList.size(); i++) {
        if(!Entity::entityList[i])
            continue;
        
        Entity::entityList[i]->cleanup();
    }
    
    Entity::entityList.clear();
    
    Music.OnCleanup();
    
    SDL_FreeSurface(display);
    
    SDL_Quit();
}
