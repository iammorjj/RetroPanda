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

#include "Global.hpp"
using namespace Global;

namespace {
    const std::string file = path+"hero.png";
    const int frameWidth = 400;
    const int frameHeight = 400;
    const int maxFrames = 4;
    
    const int xSpritePos = scrWidth / 2.0 - frameWidth / 2.0;
    const int ySpritePos = scrHeight - frameHeight - 20;
}

Hero::Hero(): surface(nullptr) {}

void Hero::changeLocation(int location) {
    animation.setCurrentFrameRow(this->location = location);
}

bool Hero::canCatch(const Burger &obj) {
    return obj.canBeCaught(location);
}
void Hero::catchBurger(Burger &obj) {
    obj.deleteBurger(location);
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
    animation.draw(display, surface, xSpritePos, ySpritePos);
}
void Hero::cleanup() {
    SDL_FreeSurface(surface);
}

