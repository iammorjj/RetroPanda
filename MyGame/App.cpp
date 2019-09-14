//
//  App.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "App.hpp"
#include "Global.hpp"

App::App() : display(nullptr), running(true), isGameOver(false) {}

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
    score.score = 0;
    
    burger.newGame();
    conveyor.newGame();
}
void App::gameOver() {
    isGameOver = true;
    Global::tKeyboardDelay.start();
    
    burger.gameOver();
    conveyor.gameOver();
}

bool App::isNewLevel() {
    return score.score % Global::speedLevelUp == 0 ||
        score.score % Global::appearanceLevelUp == 0;
}
void App::newLevel() {
    if(score.score % Global::speedLevelUp == 0)
        burger.newLevelMovementSpeed();
    else
        burger.newLevelAppearanceSpeed();
}
