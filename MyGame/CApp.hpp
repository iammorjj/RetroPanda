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

#ifndef MAC
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#else
#include <SDL_ttf/SDL_ttf.h>
#include <SDL_mixer/SDL_mixer.h>
#endif

#include <stdio.h>

#include "Constants.h"
#include "CSurface.hpp"
#include "CAnimation.hpp"
#include "CConveyor.hpp"
#include "CEntity.hpp"
#include "CHero.hpp"
#include "CBurger.hpp"
#include "CScore.hpp"
#include "CBackground.hpp"
#include "CGameOverTitle.hpp"
#include "CMusic.hpp"

#include "Hero.hpp"

class CApp {
private:
    bool            Running;
    
    SDL_Surface*    Surf_Display;
    
    CBackground     Background;
    
    CGameOverTitle  GameOverTitle;
    
    CMusic          Music;
    
    CScore          Score;
    
    CHero           Hero;
    CBurger         Burger;
    CConveyor       Conveyor;
    
    //ref
    class Hero      HeroRefactoring;
    
private:
    bool isWindowInit();
    bool isRecourceInit();
    
private:
    void startNewGame();
    
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
