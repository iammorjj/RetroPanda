//
//  App.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "App.hpp"

App::App() : display(nullptr), running(true) {}

int App::execute() {
    if(init() == false)
        return -1;
    
    SDL_Event Event;
    
    while(running) {
        while(SDL_PollEvent(&Event)) {
            event(&Event);
        }
        
        loop();
        render();
    }
    
    cleanup();
    
    return 0;
}

void App::gameOver() {
    burger.gameOver();
    conveyor.gameOver();
}

bool App::isNewLevel() {
    return score.score % 3 == 0 ||
        score.score % 5 == 0;
}
void App::newLevel() {
    if(score.score % 3 == 0)
        burger.newLevelMovementSpeed();
    else
        burger.newLevelAppearanceSpeed();
}

//    if(Burger.hasBurger(Hero.location) &&
//       LocationClassOldVersion::isHeroCollision(Burger.burger[Hero.location].back())) {
//        Burger.burger[Hero.location].pop_back();
//        Score.score++;
//        Music.pointSoundPlay();
//        if(Score.score % 3 == 0)
//            Burger.newLevelMovementSpeed();
//        if(Score.score % 5 == 0)
//            Burger.newLevelAppearanceSpeed();
//    }
//
//    if(!GLOBAL::GameOver && Burger.isGameOverCollisions()) {
//        GLOBAL::GameOver = true;
//        GLOBAL::keyboardDelay = true;
//        GLOBAL::timer.start();
//    }
