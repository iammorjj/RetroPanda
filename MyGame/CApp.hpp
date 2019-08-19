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
#include <SDL_ttf/SDL_ttf.h>
#include <SDL_mixer/SDL_mixer.h>

#include <stdio.h>

#include "Constants.h"
#include "CSurface.hpp"
#include "CAnimation.hpp"
#include "CConveyor.hpp"
#include "CEntity.hpp"
#include "CHero.hpp"
#include "CBurger.hpp"
#include "CScore.hpp"
#include "CWelcome.hpp"

class CApp {
    
private:
    bool            Running;
    
    SDL_Surface*    Surf_Display;
    
    SDL_Surface*    Surf_Background;
    SDL_Surface*    Surf_Pizza1;
    SDL_Surface*    Surf_Pizza2;
    
    CWelcome        Welcome;
    
    Mix_Music*      music;
    
    CScore          Score;
    
    CHero           Hero;
    CBurger         Burger;
    CConveyor       Conveyor;
    
    SDL_TimerID     timerLevelUpBurgerSpeedMovement;
    
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
};

#endif
