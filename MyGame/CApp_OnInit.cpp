//
//  CApp_OnInit.cpp
//  SDL_Test1
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    
    if((Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }
    
    if((Surf_Test = CSurface::OnLoad("/Users/alexandermordovsky/Documents/XCodeProjects/SDL_Test1/SDL_Test1/2706-21.jpg")) == NULL) {
        return false;
    }
    
    return true;
}
