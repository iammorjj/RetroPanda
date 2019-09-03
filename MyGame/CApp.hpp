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
#include "CSurfaceOldVersion.hpp"
#include "CAnimationOldVersion.hpp"
#include "CConveyorOldVersion.hpp"
#include "CEntityOldVersion.hpp"
#include "CHeroOldVersion.hpp"
#include "CBurgerOldVersion.hpp"
#include "CScoreOldVersion.hpp"
#include "CBackgroundOldVersion.hpp"
#include "CGameOverTitle.hpp"
#include "CMusic.hpp"

//#include "Hero.hpp"
#include "Burger.hpp"
#include "Conveyor.h"
//#include "BurgerRefactoring.h"

class CApp {
private:
    bool            Running;
    
    SDL_Surface*    Surf_Display;
    
    CBackgroundOldVersion     Background;
    
    CGameOverTitle  GameOverTitle;
    
    CMusic          Music;
    
    CScoreOldVersion          Score;
    
    //CHeroOldVersion           Hero;
    //CBurgerOldVersion         Burger;
    //CConveyorOldVersion       Conveyor;
    
    //ref
    //Hero   hero;
    
    class Conveyor    conveyor;
    
private:
    bool isWindowInit();
    bool isRecourceInit();
    
    void startNewGame();
    void gameOver();
    
    bool isNewLevel();
    void newLevel();
    
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
