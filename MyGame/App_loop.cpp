//
//  App_loop.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "App.hpp"
#include "Global.hpp"

void App::loop() {
    for(int i = 0; i < Entity::entityList.size(); i++) {
        if(!Entity::entityList[i])
            continue;
        
        Entity::entityList[i]->loop();
    }
    
    if(Global::isGameOver)
        return;
    
    if(hero.canCatch(burger)) {
        hero.catchBurger(burger);
        score.incrScore();
        music.pointSoundPlay();
        if(isNewLevel())
            newLevel();
    }
    
    if(burger.isMissed())
        gameOver();
}
