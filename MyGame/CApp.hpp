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
#include "CConveyor.hpp"
#include "CEntity.hpp"
#include "CHero.hpp"
#include "CBurger.hpp"

class CApp {
    
private:
    bool            Running;
    bool            GameOver;
    
    SDL_Surface*    Surf_Display;
    SDL_Surface*    Surf_Background;
    
    CHero           Hero;
    CBurger         Burger;
    CConveyor       Conveyor;
    
private:
    bool isWindowInit();
    bool isRecourceInit();
    
public:
    CApp();
    
    int OnExecute();
    
public:
    bool OnInit();
    
    void OnEvent(SDL_Event* Event);
    
    void OnLoop();
    
    void OnRender();
    
    void OnCleanup();
    
private:
    void StartGame();
    
};

#endif
