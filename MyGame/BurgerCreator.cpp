//
//  BurgerApperance.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 13/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "BurgerCreator.hpp"
#include "Burger.hpp"

namespace {
    const int startDelayMs = 3000;
    
    const int minDelayMs = 700;
    const int delayDecrementMs = 300;
    
    const int linesNum = 6;
}

BurgerCreator::BurgerCreator(Burger* burger) : timer(nullptr), delay(startDelayMs), isDelayChanged(false), burger(burger) {}

void BurgerCreator::createBurger() {
    int location = rand() % linesNum;
    burger->burgerLine[location].push_front(BurgerItem(location));
    
    if(isDelayChanged)
        restartTimer();
}

void BurgerCreator::changeDelay() {
    if(delay > minDelayMs)
        delay -= delayDecrementMs;
    
    isDelayChanged = true;
}

void BurgerCreator::start() {
    timer = SDL_AddTimer(delay, [](Uint32 interval, void* param) -> Uint32 {
        BurgerCreator* creator = (BurgerCreator*)param;
        creator->createBurger();
        
        return interval;
    }, this);
}

void BurgerCreator::stop() {
    isDelayChanged = false;
    if(timer)
        SDL_RemoveTimer(timer);
}

void BurgerCreator::restartTimer() {
    stop();
    start();
}
