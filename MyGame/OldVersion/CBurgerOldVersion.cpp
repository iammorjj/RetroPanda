//
//  CBurgerOldVersion.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 07/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CBurgerOldVersion.hpp"

using namespace CONSTANTS::BURGER;

CBurgerOldVersion::CBurgerOldVersion() {
    deltaTicks = 0;

    gameOverHidingBurgersRate = 500;
    oldTimeGameOver = 0;
    isHide = false;
    
    createNewBurgerDelay = CREATE_NEW_BURGER_DELAY_START;
    createNewBurgerTimer = nullptr;
    
    changeAppearanceSpeed = false;
}

void CBurgerOldVersion::newLevelMovementSpeed() {
    double addVelX = 7, addVelY = 4;
    //BurgerOldVersion::xVel += addVelX;//*= 1.1;
    //BurgerOldVersion::yVel += addVelY;//*= 1.1;
}

void CBurgerOldVersion::newLevelAppearanceSpeed() {
    if(createNewBurgerDelay > 900) {
        createNewBurgerDelay -= 250;
        changeAppearanceSpeed = true;
    }
//    createNewBurgerDelay *= 0.85;
//    changeAppearanceSpeed = true;
}

void CBurgerOldVersion::addBurgerToRandomConveyor() {
    LocationOldVersion location = (LocationOldVersion) (rand() % CONSTANTS::CONVEYORS_NUM);
    
    // debug
    //location = LEFT_UP;
    
    burger[location].push_front(BurgerOldVersion(location));
    
    if(changeAppearanceSpeed && createNewBurgerTimer && SDL_RemoveTimer(createNewBurgerTimer)) {
        createNewBurgerTimer = NULL;
        changeAppearanceSpeed = false;
        createBurgers();
    }
}

void CBurgerOldVersion::OnRender(SDL_Surface* Surf_Display) {
    for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location) {
        for(auto burg: burger[location]) {
            if(GLOBAL::GameOver)
                gameOver();
            if(!isHide)
                CSurfaceOldVersion::OnDraw(Surf_Display, Surf_Entity, burg.x,
                                 burg.y,
                                 0, 0, Width, Height);
        }
    }
}

void CBurgerOldVersion::gameOver() {
    if(oldTimeGameOver + this->gameOverHidingBurgersRate > SDL_GetTicks())
        return;

    oldTimeGameOver = SDL_GetTicks();
    isHide = !isHide;
}

bool CBurgerOldVersion::hasBurger(LocationOldVersion location) {
    return !burger[location].empty();
}

void CBurgerOldVersion::StartMove() {
    deltaTicks = timer.get_ticks();
    
    for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location) {
        for(auto &burg: burger[location])
            burg.move(deltaTicks);
    }
    
    timer.start();
}

void CBurgerOldVersion::newGame() {
    for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location)
        burger[location].clear();
    
    isHide = false;
    changeAppearanceSpeed = false;
    
    BurgerOldVersion::xVel = X_VEL_START;
    BurgerOldVersion::yVel = Y_VEL_START;
    createNewBurgerDelay = CREATE_NEW_BURGER_DELAY_START;
    
    if(createNewBurgerTimer)
        SDL_RemoveTimer(createNewBurgerTimer);
    createNewBurgerTimer = NULL;
    
    timer.start();
    
    createBurgers();
}

bool CBurgerOldVersion::isGameOverCollisions() {
    for(auto burger: burger) {
        if(burger.empty())
            continue;
        
        auto burg = burger.back();
        if(burg.isGameOver()) {
            return true;
        }
    }
    
    return false;
}

void CBurgerOldVersion::OnLoop() {
    if(!GLOBAL::GameOver) {
        StartMove();
    }
}

Uint32 addBurgerK(Uint32 interval, void* param) {
    CBurgerOldVersion* Burger = (CBurgerOldVersion*)param;
    Burger->addBurgerToRandomConveyor();
    
    return interval;
}

void CBurgerOldVersion::createBurgers() {
    if(!createNewBurgerTimer)
        createNewBurgerTimer = SDL_AddTimer(createNewBurgerDelay, addBurgerK, this);
}
