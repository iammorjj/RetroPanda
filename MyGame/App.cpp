//
//  App.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "App.hpp"
#include "Global.hpp"

using namespace Global;

App::App() : display(nullptr), running(true) {}

int App::execute() {
    if(init() == false)
        return -1;
    
    SDL_Event event;
    
    while(running) {
        while(SDL_PollEvent(&event)) {
            eventHandler(&event);
        }
        
        loop();
        render();
    }
    
    cleanup();
    
    return 0;
}

void App::newGame() {
    isGameOver = false;
    
    score.newGame();
    burger.newGame();
    conveyor.newGame();
}
void App::gameOver() {
    isFirstGame = false;
    isGameOver = true;
    
    tKeyboardDelay.start();
    
    burger.gameOver();
    conveyor.gameOver();
}

bool App::isNewLevel() {
    return score.score % speedLevelUp == 0 ||
        score.score % appearanceLevelUp == 0;
}
void App::newLevel() {
    if(score.score % speedLevelUp == 0)
        burger.newLevelMovementSpeed();
    else
        burger.newLevelAppearanceSpeed();
}
