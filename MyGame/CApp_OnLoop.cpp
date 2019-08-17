//
//  CApp_OnLoop.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"
#include "Location.h"

void CApp::OnLoop() {
    
    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;
        
        CEntity::EntityList[i]->OnLoop();
    }
    
    // refactor this place pls
    
//    if(Burger.hasBurger(Hero.location)) {
//        printf("HERO AND BURGER LOCATION IS THE SAME!\n");
//    }
    
//    if(Burger.hasBurger(Hero.location))
//    if(LocationClass::isHeroCollision(Burger.burger[Hero.location].back())) {
//        printf("HERO COLLISION IS DETECTED!\n");
//    }
       
    if(Burger.hasBurger(Hero.location) &&
       LocationClass::isHeroCollision(Burger.burger[Hero.location].back())) {
        Burger.burger[Hero.location].pop_back();
        Score.score++;
        if(Score.score % 3 == 0)
            Burger.newLevelSpeedMovement();
        if(Score.score % 5 == 0)
            Burger.newLevelSpeedAppearence();
    }
    
    Burger.checkGameOverCollisions();
    
}
