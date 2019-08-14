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
    level = 0;
    
    frameRate = 50; //Milliseconds
    
    oldTime = 0;
    
    gameOverHidingBurgersRate = 500;
    oldTimeGameOver = 0;
    gameOverHidding = false;
    
    frameRateGravity = FRAME_RATE_GRAVITY;
    oldTimeGravity = 0;
    
    createNewBurgerDelay = 3000;
    createNewBurgerTimer = nullptr;
}

void CBurger::addBurgerToRandomConveyor() {
    Location location = (Location) (rand() % CONSTANTS::CONVEYORS_NUM);
    burger[location].push_back(Burger(location));
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

void CBurger::gravity() {
    for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location) {
        for(auto &burg: burger[location]) {
            if(!burg.canMoveSideway() && burg.canMoveDown())
                burg.y += 1;
        }
    }
}

void CBurger::moveLeft() {
    
    for(int location = RIGHT_DOWN; location <= RIGHT_UP; ++location) {
        for(auto &burg: burger[location]) {
            if(burg.canMoveSideway())
                burg.x -= 2;
        }
    }
}

void CBurger::moveRight() {
    
    for(int location = LEFT_DOWN; location <= LEFT_UP; ++location) {
        for(auto &burg: burger[location]) {
            if(burg.canMoveSideway())
                burg.x += 2;
        }
    }
}

void CBurger::moveUp() {
    
    for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location) {
        for(auto &burg: burger[location]) {
            if(burg.y > CONSTANTS::BURGER::STOP_BURGER_Y_UP)
                burg.y -= 1;
        }
    }
}

void CBurger::moveDownLeftSide() {
    
    for(int location = LEFT_DOWN; location <= LEFT_UP; ++location) {
        for(auto &burg: burger[location]) {
            if(burg.canMoveDown()) {
                if(burg.canMoveSideway())
                    burg.y += 1;
            }
        }
    }
}

void CBurger::moveDownRightSide() {
    
    for(int location = RIGHT_DOWN; location <= RIGHT_UP; ++location) {
        for(auto &burg: burger[location]) {
            if(burg.canMoveDown()) {
                if(burg.canMoveSideway())
                    burg.y += 1;
            }
        }
    }
}


void CBurger::setLevel(int l) { level = l; }

void CBurger::moveFromLeft() { moveRight(); moveDownLeftSide(); }
void CBurger::moveFromRight() { moveLeft(); moveDownRightSide(); }


void CBurger::StartMove() {
    
    if(oldTime + this->frameRate < SDL_GetTicks()) {
        oldTime = SDL_GetTicks();
        
        moveFromLeft();
        moveFromRight();
    }
    
    if(oldTimeGravity + this->frameRateGravity < SDL_GetTicks()) {
        oldTimeGravity = SDL_GetTicks();
        
        gravity();
    }
    
}

void CBurger::newGame() {
    gameOverHidding = false;
    for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location)
        burger[location].clear();
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
        createBurgers();
        StartMove();
    }
}


Uint32 addBurgerK(Uint32 interval, void* param) {
    CBurger* Burger = (CBurger*)param;
    Burger->addBurgerToRandomConveyor();
    
    return interval;
}

Uint32 changeMovementSpeedTimer(Uint32 interval, void* param) {
    int* frameRate = (int*)param;
    if(*frameRate > 10)
        (*frameRate)--;
    
    return interval;
}

void CBurger::changeMovementSpeed(SDL_TimerID& timer) {
    timer = SDL_AddTimer(4000, changeMovementSpeedTimer, &frameRate);
}

void CBurger::createBurgers() {
    if(!createNewBurgerTimer)
        createNewBurgerTimer = SDL_AddTimer(createNewBurgerDelay, addBurgerK, this);
}
