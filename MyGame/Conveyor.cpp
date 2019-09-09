//
//  Conveyor.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 08/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Conveyor.h"
#include "Location.hpp"
#include <string>

#include "Constants.h"
using namespace CONSTANTS;

namespace {
    const std::string file = PATH+"conveyor.png";
    const int frameWidth = 192;
    const int frameHeight = 192;
    const int maxFrames = 16;
    
    const int yDistanceBetweenLines = 120;
    const int leftSideCoord = SCREEN_WIDTH / 2. - BACKGROUND_WIDTH / 2. - 60;
    const int rightSideCoord = SCREEN_WIDTH / 2. + 90;
    const int yUp = 200;
    
    enum { RIGHT, LEFT };
    
    const int x[] = {leftSideCoord, leftSideCoord, leftSideCoord,
        rightSideCoord, rightSideCoord, rightSideCoord};
    const int y[] = {yUp + yDistanceBetweenLines * 2, yUp + yDistanceBetweenLines, yUp,
        yUp + yDistanceBetweenLines * 2, yUp + yDistanceBetweenLines, yUp};
}

Conveyor::Conveyor() : surface(nullptr), running(false) {}

void Conveyor::stop() {
    running = false;
}
void Conveyor::start() {
    running = true;
}

void Conveyor::drawSide(SDL_Surface* display, int side) {
    animation.setCurrentFrameRow(side);
    int location = (side == LEFT ? Location::LEFT_DOWN : Location::RIGHT_DOWN);
    for(int i = 0; i < 3; ++i, ++location)
        animation.draw(display, surface, x[location], y[location]);
}

bool Conveyor::load() {
    surface = CSurfaceOldVersion::OnLoad(file.c_str());
    if(!surface)
        return false;
    
    animation.setSpriteInfo(frameWidth, frameHeight, maxFrames);
    return true;
}
void Conveyor::loop() {
    if(running)
        animation.animate();
}
void Conveyor::render(SDL_Surface* display) {
    drawSide(display, LEFT);
    drawSide(display, RIGHT);
}
void Conveyor::cleanup() {
    SDL_FreeSurface(surface);
}
