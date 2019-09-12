//
//  App_loop.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "App.hpp"
#include "LocationOldVersion.h"

void App::loop() {
    for(int i = 0; i < Entity::entityList.size(); i++) {
        if(!Entity::entityList[i])
            continue;
        
        Entity::entityList[i]->loop();
    }
    
    if(hero.canCatch(burger)) {
        hero.catchBurger(burger);
        //score.score++;
        music.pointSoundPlay();
        if(isNewLevel())
            newLevel();
    }
    
    if(burger.isMissed())
        gameOver();
    
    // refactor this place pls
    
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
    
}
