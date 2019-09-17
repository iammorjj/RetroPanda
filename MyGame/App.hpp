//
//  App.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef _APP_H_
#define _APP_H_

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
#include "Score.hpp"
#include "Advertising.hpp"
#include "Background.hpp"
#include "CGameOverTitle.hpp"
#include "Music.hpp"
#include "GameOverTitle.hpp"

#include "Hero.hpp"
#include "Burger.hpp"
#include "Conveyor.h"

class App {
private:
    SDL_Surface* display;
    
    bool running;
    
    Background background;
    Advertising advertising;
    
    //Title title;
    //CGameOverTitle GameOverTitle;
    GameOverTitle gameOverTitle;
    
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

#endif /* App_hpp */
