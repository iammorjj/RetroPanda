//
//  CApp_OnLoop.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"
#include "LocationOldVersion.h"

void CApp::OnLoop() {
    
    for(int i = 0;i < CEntityOldVersion::EntityList.size();i++) {
        if(!CEntityOldVersion::EntityList[i]) continue;
        
        CEntityOldVersion::EntityList[i]->OnLoop();
        
    }
    
    if(hero.canCatch(burger)) {
        hero.catchBurger(burger);
        Score.score++;
        Music.pointSoundPlay();
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
