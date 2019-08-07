//
//  CApp.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL/SDL.h>

#include "Constants.h"
#include "CSurface.hpp"
#include "CAnimation.hpp"
#include "CEntity.hpp"
#include "CConveyor.hpp"
#include "CHero.hpp"
#include "CBurger.hpp"

class CApp {
private:
    bool            Running;
    
    SDL_Surface*    Surf_Display;
    SDL_Surface*    Surf_Background;
    
    SDL_Surface*    Surf_Conveyor;
    
    CBurger         Burger;
    
    CConveyor       Conveyor;
    
    CHero           Hero;
    
//    
//    const int SCREEN_WIDTH = 640;
//    const int SCREEN_HEIGHT = 480;
//    const int SCREEN_BPP = 32;
    
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
