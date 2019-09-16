//
//  App.hpp
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
#include "Surface.hpp"
//#include "CAnimationOldVersion.hpp"
//#include "CConveyorOldVersion.hpp"
//#include "CEntityOldVersion.hpp"
//#include "CHeroOldVersion.hpp"
//#include "CBurgerOldVersion.hpp"
//#include "./OldVersion/CScoreOldVersion.hpp"
//#include "./OldVersion/CBackgroundOldVersion.hpp"
#include "Score.hpp"
#include "Background.hpp"
#include "CGameOverTitle.hpp"
#include "Music.hpp"

#include "Hero.hpp"
#include "Burger.hpp"
#include "Conveyor.h"

class App {
private:
    SDL_Surface* display;
    bool running;
    
    Background background;
    
    CGameOverTitle  GameOverTitle;
    
    Music music;
    
    Score score;

    Hero hero;
    Burger burger;
    Conveyor conveyor;
private:
    bool windowInit();
    bool resourceInit();
    
    void newGame();
    void gameOver();
    
    bool isNewLevel();
    void newLevel();
public:
    App();
    
    int execute();
public:
    bool init();
    void eventHandler(SDL_Event* event);
    void loop();
    void render();
    void cleanup();
};

#endif
