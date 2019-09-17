//
//  App_cleanup.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "App.hpp"

void App::cleanup() {
    for(int i = 0; i < Entity::entityList.size(); i++) {
        if(!Entity::entityList[i])
            continue;
        
        Entity::entityList[i]->cleanup();
    }
    
    Entity::entityList.clear();
    
    music.cleanup();
    
    SDL_FreeSurface(display);
    
    SDL_Quit();
}
