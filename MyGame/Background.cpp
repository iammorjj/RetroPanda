//
//  Background.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 10/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Background.hpp"
#include "OldVersion/CSurfaceOldVersion.hpp"
#include <string>

namespace {
    const std::string fCenter = "name1";
    const std::string fSides = "name2";
    
    const int sidesWidth = 400;
    const int sidesHeight = 400;
    const int sidesFrameRateMs = 200;
    const int maxFrames = 3;
    
    const int xCenter = 0;
    const int yCenter = 0;
    const int xLeftSide = 0;
    const int yLeftSide = 0;
    const int xRightSide = 0;
    const int yRightSide = 0;
}

Background::Background() : sCenter(nullptr), sSides(nullptr) {}

bool Background::load() {
    sCenter = CSurfaceOldVersion::OnLoad(fCenter.c_str());
    sSides = CSurfaceOldVersion::OnLoad(fSides.c_str());
    
    if(!sCenter || !sSides)
        return false;
    
    animation.setSpriteInfo(sidesWidth, sidesHeight, maxFrames);
    animation.setFrameRateMs(sidesFrameRateMs);
    
    return true;
}

void Background::loop() {
    animation.animate();
}

void Background::render(SDL_Surface* display) {
    CSurfaceOldVersion::OnDraw(display, sCenter, xCenter, yCenter);
    animation.draw(display, sSides, xLeftSide, yLeftSide);
    animation.draw(display, sSides, xRightSide, yRightSide);
}

void Background::cleanup() {
    SDL_FreeSurface(sCenter);
    SDL_FreeSurface(sSides);
}
