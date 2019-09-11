//
//  Hero.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 03/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Hero.hpp"
#include "Burger.hpp"
#include <string>

#include "Constants.h"
using namespace CONSTANTS;

namespace {
    const std::string file = PATH+"hero.png";
    const int frameWidth = 400;
    const int frameHeight = 400;
    const int maxFrames = 4;
    
    const int x = SCREEN_WIDTH / 2.0 - frameWidth / 2.0;
    const int y = SCREEN_HEIGHT - frameHeight - 20;
}

Hero::Hero(): surface(nullptr) {}

void Hero::changeLocation(int location) {
    animation.setCurrentFrameRow(this->location = location);
}

bool Hero::canCatch(const Burger &obj) {
    return true;
}
void Hero::catchBurger(Burger &obj) {
    obj.burgerLine[location].pop_back();
}

bool Hero::load() {
    surface = Surface::load(file.c_str());
    if(!surface)
        return false;
    
    animation.setSpriteInfo(frameWidth, frameHeight, maxFrames);
    return true;
}
void Hero::loop() {
    animation.animate();
}
void Hero::render(SDL_Surface* display) {
    animation.draw(display, surface, x, y);
}
void Hero::cleanup() {
    SDL_FreeSurface(surface);
}

