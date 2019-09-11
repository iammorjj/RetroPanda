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
#include "Constants.h"

using namespace CONSTANTS;

namespace {
    const std::string fCenter = PATH+"background.png";
    const std::string fSides = PATH+"sidesBillys.png";
    
    const int backgroundWidth = 461;
    const int backgroundHeight = SCREEN_HEIGHT;
    const int sidesWidth = 282;
    const int sidesHeight = SCREEN_HEIGHT;
    const int sidesFrameRateMs = 200;
    const int maxFrames = 3;
    
    const int xCenter = SCREEN_WIDTH / 2 - backgroundWidth / 2;
    const int yCenter = 0;
    const int xLeftSide = 0;
    const int yLeftSide = 0;
    const int xRightSide = SCREEN_WIDTH / 2 + backgroundWidth / 2;
    const int yRightSide = 0;
}

Background::Background() : sCenter(nullptr), sSides(nullptr) {}

bool Background::load() {
    sCenter = CSurfaceOldVersion::OnLoad(fCenter.c_str());
    sSides = CSurfaceOldVersion::OnLoad(fSides.c_str());
    
    if(!sCenter || !sSides)
        return false;
    
    sidesAnimation.setSpriteInfo(sidesWidth, sidesHeight, maxFrames);
    sidesAnimation.setFrameRateMs(sidesFrameRateMs);
    
    return true;
}

void Background::loop() {
    sidesAnimation.animate();
}

void Background::render(SDL_Surface* display) {
    CSurfaceOldVersion::OnDraw(display, sCenter, xCenter, yCenter);
    sidesAnimation.draw(display, sSides, xLeftSide, yLeftSide);
    sidesAnimation.draw(display, sSides, xRightSide, yRightSide);
}

void Background::cleanup() {
    SDL_FreeSurface(sCenter);
    SDL_FreeSurface(sSides);
}
