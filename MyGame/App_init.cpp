//
//  App_init.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "App.hpp"
#include "Global.hpp"
using namespace Global;

bool App::init() {
    if(windowInit() && TTF_Init() != -1 && resourceInit()) {
        Entity::entityList.push_back(&background);
        Entity::entityList.push_back(&conveyor);
        Entity::entityList.push_back(&burger);
        // adv after burger cause we hide textures
        Entity::entityList.push_back(&advertising);
        Entity::entityList.push_back(&hero);
        Entity::entityList.push_back(&score);
        Entity::entityList.push_back(&gameOverTitle);
        
        return true;
    }
    
    return false;
}

bool App::windowInit() {
    if(SDL_Init( SDL_INIT_EVERYTHING ) < 0)
        return false;
    
    if( !(display = SDL_SetVideoMode( scrWidth, scrHeight, scrBpp, SDL_HWSURFACE | SDL_DOUBLEBUF)) )
        return false;
    
    return true;
}

bool App::resourceInit() {
    if( !music.load() ||
       
        !background.load() ||
       
        !advertising.load() ||
       
        !score.load() ||
       
        !conveyor.load() ||
       
        !hero.load() ||
       
        !burger.load() ||
       
        !gameOverTitle.load() )
        return false;
    
    return true;
}
