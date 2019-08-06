//
//  CApp_OnInit.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

bool CApp::OnInit() {
    //Initialize all SDL subsystems
    if(SDL_Init( SDL_INIT_EVERYTHING ) < 0) {
        return false;
    }

    if((Surf_Display = SDL_SetVideoMode( Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, Constants::SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }
    
    if((Surf_Background = CSurface::OnLoad(Constants::BACKGROUND_IMG.c_str())) == NULL) {
        return false;
    }
    
    if(!Conveyor.OnLoad(Constants::CONVEYOR_IMG.c_str(), Constants::CONVEYOR_WIDTH, Constants::CONVEYOR_HEIGHT, Constants::CONVEYOR_MAX_FRAMES)) {
        return false;
    }
    
    if(!Hero.OnLoad(Constants::HERO_IMG.c_str(), Constants::HERO_WIDTH, Constants::HERO_HEIGHT, Constants::HERO_MAX_FRAMES)) {
        return false;
    }
    
    CEntity::EntityList.push_back(&Conveyor);
    CEntity::EntityList.push_back(&Hero);
    
    return true;
}
