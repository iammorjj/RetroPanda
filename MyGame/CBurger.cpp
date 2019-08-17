//
//  CBurger.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 07/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CBurger.hpp"

using namespace CONSTANTS::BURGER;

const int X_VEL_START = 35;
const int Y_VEL_START = 20;
const int GRAVITY = 35;
const int CREATE_NEW_BURGER_DELAY_START = 2400;

CBurger::CBurger() {
    xVel = X_VEL_START;
    yVel = Y_VEL_START;
    
    deltaTicks = 0;
    
    level = 0;
    
    frameRate = 50; //Milliseconds
    
    oldTime = 0;
    
    gameOverHidingBurgersRate = 500;
    oldTimeGameOver = 0;
    gameOverHidding = false;
    
    frameRateGravity = FRAME_RATE_GRAVITY;
    oldTimeGravity = 0;
    
    createNewBurgerDelay = CREATE_NEW_BURGER_DELAY_START;
    createNewBurgerTimer = nullptr;
    
    timer.start();
}

void CBurger::newLevelSpeedMovement() {
    xVel *= 1.1;
    yVel *= 1.1;
}

void CBurger::newLevelSpeedAppearence() {
    createNewBurgerDelay *= 0.75;
    if(createNewBurgerTimer && !SDL_RemoveTimer(createNewBurgerTimer)) {
        printf("timer is not removed, FAULT!\n");
        return;
    }
    createNewBurgerTimer = NULL;
    createBurgers();
}

void CBurger::addBurgerToRandomConveyor() {
    Location location = (Location) (rand() % CONSTANTS::CONVEYORS_NUM);
    
    // debug
    //location = LEFT_UP;
    
    // no vector, need queue
    //burger[location].push_back(Burger(location));
    burger[location].push_front(Burger(location));
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

void CBurger::gravity(double deltaTicks) {
    for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location) {
        for(auto &burg: burger[location]) {
            if(!burg.canMoveSideway() && burg.canMoveDown())
                //burg.y += 1;
                burg.y += GRAVITY * ( deltaTicks / 1000.0 );
        }
    }
}

void CBurger::moveLeft(double deltaTicks) {
    
    for(int location = RIGHT_DOWN; location <= RIGHT_UP; ++location) {
        for(auto &burg: burger[location]) {
            if(burg.canMoveSideway())
                //burg.x -= 2;
                burg.x -= xVel * ( deltaTicks / 1000.0 );
        }
    }
}

void CBurger::moveRight(double deltaTicks) {
    
    for(int location = LEFT_DOWN; location <= LEFT_UP; ++location) {
        //for(int i = 0; i < burger[location].size(); ++i) {
        for(auto &burg: burger[location]) {
            //auto &burg = burger[location][i];
            if(burg.canMoveSideway()) {
                //burg.x += 2;
                burg.x += xVel * ( deltaTicks / 1000.0 );
                //printf("%d burger has x %lf\n", i, burg.x);
            }
        }
    }
}

void CBurger::moveUp(double deltaTicks) {
    
    for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location) {
        for(auto &burg: burger[location]) {
            if(burg.y > CONSTANTS::BURGER::STOP_BURGER_Y_UP)
                //burg.y -= 1;
                burg.y -= yVel * ( deltaTicks / 1000.0 );
        }
    }
}

void CBurger::moveDownLeftSide(double deltaTicks) {
    
    for(int location = LEFT_DOWN; location <= LEFT_UP; ++location) {
        for(auto &burg: burger[location]) {
            if(burg.canMoveDown()) {
                if(burg.canMoveSideway())
                    //burg.y += 1;
                    burg.y += yVel * ( deltaTicks / 1000.0 );
            }
        }
    }
}

void CBurger::moveDownRightSide(double deltaTicks) {
    
    for(int location = RIGHT_DOWN; location <= RIGHT_UP; ++location) {
        for(auto &burg: burger[location]) {
            if(burg.canMoveDown()) {
                if(burg.canMoveSideway())
                    //burg.y += 1;
                    burg.y += yVel * ( deltaTicks / 1000.0 );
            }
        }
    }
}


void CBurger::setLevel(int l) { level = l; }

void CBurger::moveFromLeft(double deltaTicks) {
    moveRight(deltaTicks);
    moveDownLeftSide(deltaTicks); }
void CBurger::moveFromRight(double deltaTicks) {
    moveLeft(deltaTicks);
    moveDownRightSide(deltaTicks); }


void CBurger::StartMove() {
    
    deltaTicks = timer.get_ticks();
    
    moveFromLeft(deltaTicks);
    moveFromRight(deltaTicks);
    gravity(deltaTicks);
    
    timer.start();
//    if(oldTime + this->frameRate < SDL_GetTicks()) {
//        oldTime = SDL_GetTicks();
//
//        moveFromLeft();
//        moveFromRight();
//    }
//
//    if(oldTimeGravity + this->frameRateGravity < SDL_GetTicks()) {
//        oldTimeGravity = SDL_GetTicks();
//
//        gravity();
//    }
    
    
    
}

void CBurger::newGame() {
    gameOverHidding = false;
    for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location)
        burger[location].clear();
    xVel = X_VEL_START;
    yVel = Y_VEL_START;
    createNewBurgerDelay = CREATE_NEW_BURGER_DELAY_START;
    if(createNewBurgerTimer)
        SDL_RemoveTimer(createNewBurgerTimer);
    createNewBurgerTimer = NULL;
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
void CBurger::printCoordinate(int xx, int yy) { printf("X coordinate is %d\nY coordinate is %d\n", xx, yy); }

void CBurger::OnLoop() {
    if(!GLOBAL::GameOver) {
        //createBurgers();
        StartMove();
    }
}


Uint32 addBurgerK(Uint32 interval, void* param) {
    CBurger* Burger = (CBurger*)param;
    Burger->addBurgerToRandomConveyor();
    
    return interval;
}

//Uint32 changeMovementSpeedTimer(Uint32 interval, void* param) {
//    int* frameRate = (int*)param;
//    if(*frameRate > 10)
//        (*frameRate)--;
//
//    return interval;
//}
//
//void CBurger::changeMovementSpeed(SDL_TimerID& timer) {
//    timer = SDL_AddTimer(4000, changeMovementSpeedTimer, &frameRate);
//}

void CBurger::createBurgers() {
    if(!createNewBurgerTimer)
        createNewBurgerTimer = SDL_AddTimer(createNewBurgerDelay, addBurgerK, this);
}
