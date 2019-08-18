//
//  CBurger.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 07/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CBurger.hpp"

using namespace CONSTANTS::SCREEN1024X768::BURGER;

CBurger::CBurger() {
    deltaTicks = 0;

    gameOverHidingBurgersRate = 500;
    oldTimeGameOver = 0;
    gameOverHidding = false;
    
    createNewBurgerDelay = CREATE_NEW_BURGER_DELAY_START;
    createNewBurgerTimer = nullptr;
    
    changeAppearanceSpeed = false;
}

void CBurger::newLevelMovementSpeed() {
    double addVelX = 7, addVelY = 4;
    Burger::xVel += addVelX;//*= 1.1;
    Burger::yVel += addVelY;//*= 1.1;
}

void CBurger::newLevelAppearanceSpeed() {
    if(createNewBurgerDelay > 300) {
        createNewBurgerDelay -= 250;
        changeAppearanceSpeed = true;
    }
//    createNewBurgerDelay *= 0.85;
//    changeAppearanceSpeed = true;
}

void CBurger::addBurgerToRandomConveyor() {
    Location location = (Location) (rand() % CONSTANTS::SCREEN1024X768::CONVEYORS_NUM);
    
    // debug
    //location = LEFT_UP;
    
    burger[location].push_front(Burger(location));
    
    if(changeAppearanceSpeed && createNewBurgerTimer && SDL_RemoveTimer(createNewBurgerTimer)) {
        createNewBurgerTimer = NULL;
        changeAppearanceSpeed = false;
        createBurgers();
    }
}

void CBurger::OnRender(SDL_Surface* Surf_Display) {
    for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location) {
        for(auto burg: burger[location]) {
            if(GLOBAL::GameOver)
                gameOver();
            if(!gameOverHidding)
                CSurface::OnDraw(Surf_Display, Surf_Entity, burg.x,
                                 burg.y,
                                 0, 0, Width, Height);
        }
    }
}

void CBurger::gameOver() {
    if(oldTimeGameOver + this->gameOverHidingBurgersRate > SDL_GetTicks())
        return;

    oldTimeGameOver = SDL_GetTicks();
    gameOverHidding = !gameOverHidding;
}

bool CBurger::hasBurger(Location location) {
    return !burger[location].empty();
}

void CBurger::StartMove() {
    deltaTicks = timer.get_ticks();
    
    for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location) {
        for(auto &burg: burger[location])
            burg.move(deltaTicks);
    }
    
    timer.start();
}

void CBurger::newGame() {
    for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location)
        burger[location].clear();
    
    gameOverHidding = false;
    changeAppearanceSpeed = false;
    
    Burger::xVel = X_VEL_START;
    Burger::yVel = Y_VEL_START;
    createNewBurgerDelay = CREATE_NEW_BURGER_DELAY_START;
    
    if(createNewBurgerTimer)
        SDL_RemoveTimer(createNewBurgerTimer);
    createNewBurgerTimer = NULL;
    
    timer.start();
    
    createBurgers();
}

void CBurger::checkGameOverCollisions() {
    for(auto burger: burger) {
        if(burger.empty())
            continue;
        
        auto burg = burger.back();
        if(burg.isGameOver())
            GLOBAL::GameOver = true;
    }
}

void CBurger::OnLoop() {
    if(!GLOBAL::GameOver) {
        StartMove();
    }
}

Uint32 addBurgerK(Uint32 interval, void* param) {
    CBurger* Burger = (CBurger*)param;
    Burger->addBurgerToRandomConveyor();
    
    return interval;
}

void CBurger::createBurgers() {
    if(!createNewBurgerTimer)
        createNewBurgerTimer = SDL_AddTimer(createNewBurgerDelay, addBurgerK, this);
}
