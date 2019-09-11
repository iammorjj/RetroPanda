//
//  CApp_OnInit.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

using namespace CONSTANTS;

bool CApp::init() {
    if(windowInit() && recourceInit()) {
        Entity::entityList.push_back(&background);
        Entity::entityList.push_back(&conveyor);
        Entity::entityList.push_back(&burger);
        Entity::entityList.push_back(&hero);
        Entity::entityList.push_back(&score);
        
        return true;
    }
    
    return false;
}

bool CApp::windowInit() {
    if(SDL_Init( SDL_INIT_EVERYTHING ) < 0)
        return false;
    
    if( !(display = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF)) )
        return false;
    
    return true;
}

bool CApp::recourceInit() {
    if( !Music.OnLoad() ||
       
        !background.load() ||
       
        !score.load() ||
       
        !conveyor.load() ||
       
        !hero.load() ||
       
        !burger.load() ||
       
        !GameOverTitle.OnLoad() )
        return false;
    
    return true;
}
