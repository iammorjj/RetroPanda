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
    
    if(Burger.hasBurger(Hero.location) &&
       LocationClass::isHeroCollision(Burger.burger[Hero.location].back())) {
        Burger.burger[Hero.location].pop_back();
        //score++;
    }
    
    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;
        
        CEntity::EntityList[i]->OnLoop();
    }
    
}
