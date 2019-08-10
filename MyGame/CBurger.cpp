//
//  CBurger.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 07/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CBurger.hpp"

using namespace CONSTANTS::BURGER;

CBurger::CBurger() {
//    X = START_BURGER_X_LEFT;
//    Y = START_BURGER_Y_LEFT;
    
    //conveyor.resize(CONSTANTS::CONVEYORS_NUM);
//    burger.resize(CONSTANTS::CONVEYORS_NUM);
    
    level = 0;
    
    frameRate = 50; //Milliseconds
    
    oldTime = 0;
    
    gameOverHidingBurgersRate = 500;
    oldTimeGameOver = 0;
    gameOverHidding = false;
    
    frameRateGravity = 50;
    frameRateGravity = 0;
    
    createNewBurgerDelay = 3000;
    createNewBurgerTimer = nullptr;
}

Uint32 addBurgerK(Uint32 interval, void* param) {
    CBurger* Burger = (CBurger*)param;
    Burger->addBurgerToRandomConveyor();
    
    return interval;
}

void CBurger::createBurgers(CBurger* Burger) {
    if(!createNewBurgerTimer)
        createNewBurgerTimer = SDL_AddTimer(createNewBurgerDelay, addBurgerK, Burger);
}
