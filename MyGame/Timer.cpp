//
//  Timer.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 30/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Timer.hpp"
#include <SDL/SDL.h>

Timer::Timer() : startTicks(0), pausedTicks(0), paused(false), started(false) {}

void Timer::start() {
    started = true;
    paused = false;
    startTicks = SDL_GetTicks();
}

void Timer::stop() {
    started = false;
    paused = false;
}

int Timer::getTicks() {
    if(started) {
        if(paused)
            return pausedTicks;
        else
            return SDL_GetTicks() - startTicks;
    }

    return 0;
}
