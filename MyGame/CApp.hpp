//
//  CApp.hpp
//  SDL_Test1
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL/SDL.h>

#include "CSurface.hpp"

class CApp {
private:
    bool            Running;
    
    SDL_Surface*    Surf_Display;
    
    SDL_Surface*    Surf_Test;
    
public:
    CApp();
    
    int OnExecute();
    
public:
    bool OnInit();
    
    void OnEvent(SDL_Event* Event);
    
    void OnLoop();
    
    void OnRender();
    
    void OnCleanup();
};

#endif
