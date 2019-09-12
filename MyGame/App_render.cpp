//
//  App_render.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "App.hpp"

void App::render() {
    for(int i = 0; i < Entity::entityList.size(); i++) {
        if(!Entity::entityList[i])
            continue;
        
        Entity::entityList[i]->render(display);
    }
    
    GameOverTitle.OnRender(display);
    
    //Background.RenderSides(Surf_Display);
    
    SDL_Flip(display);
}
