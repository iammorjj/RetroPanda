//
//  Advertising.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Advertising.hpp"
#include "Surface.hpp"
#include <string>
#include "Global.hpp"

using namespace Global;

namespace {
    const std::string file = path+"sidesBillys.png";
    
    const int advWidth = 282;
    const int advHeight = scrHeight;
    const int advFrameRateMs = 200;
    const int maxFrames = 3;
    
    const int xLeftSide = 0;
    const int yLeftSide = 0;
    const int xRightSide = scrWidth - advWidth;
    const int yRightSide = 0;
}

Advertising::Advertising() : surface(nullptr) {}

bool Advertising::load() {
    surface = Surface::load(file.c_str());
    
    if(!surface)
        return false;
    
    animation.setSpriteInfo(advWidth, advHeight, maxFrames);
    animation.setFrameRateMs(advFrameRateMs);
    
    return true;
}

void Advertising::loop() {
    animation.animate();
}

void Advertising::render(SDL_Surface* display) {
    animation.draw(display, surface, xLeftSide, yLeftSide);
    animation.draw(display, surface, xRightSide, yRightSide);
}

void Advertising::cleanup() {
    SDL_FreeSurface(surface);
}
