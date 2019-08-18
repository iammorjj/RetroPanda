//
//  CApp_OnInit.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

using namespace CONSTANTS::SCREEN1024X768;

bool CApp::OnInit() {
    if(isWindowInit() && isRecourceInit()) {
        CEntity::EntityList.push_back(&Score);
        CEntity::EntityList.push_back(&Conveyor);
        CEntity::EntityList.push_back(&Burger);
        CEntity::EntityList.push_back(&Hero);
        
        return true;
    }
    
    return false;
}

bool CApp::isWindowInit() {
    if(SDL_Init( SDL_INIT_EVERYTHING ) < 0)
        return false;
    
    if((Surf_Display = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
        return false;
    
    return true;
}

bool CApp::isRecourceInit() {
    if((Surf_Background = CSurface::OnLoad(BACKGROUND_IMG.c_str())) == NULL)
        return false;
    
    if((Surf_Pizza1 = CSurface::OnLoad(PIZZA1_IMG.c_str())) == NULL)
        return false;
    if((Surf_Pizza2 = CSurface::OnLoad(PIZZA2_IMG.c_str())) == NULL)
        return false;
    
    if(!Score.OnLoad(CONSTANTS::FONT.c_str(), 200))
        return false;
    
    if(!Conveyor.OnLoad(CONVEYOR_IMG.c_str(), CONVEYOR_WIDTH, CONVEYOR_HEIGHT, CONVEYOR_MAX_FRAMES))
        return false;
    
    if(!Hero.OnLoad(HERO_IMG.c_str(), HERO_WIDTH, HERO_HEIGHT, HERO_MAX_FRAMES))
        return false;
    
    if(!Burger.OnLoad(BURGER_IMG.c_str(), BURGER::BURGER_WIDTH, BURGER::BURGER_HEIGHT, BURGER::BURGER_MAX_FRAMES))
        return false;
    
    return true;
}
