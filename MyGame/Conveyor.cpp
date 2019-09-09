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

namespace {
    const std::string file = "";
    const int frameWidth = 0;
    const int frameHeight = 0;
    const int maxFrames = 0;
    
    enum { RIGHT, LEFT };
    
    const int x[] = {-1, -1, -1, -1, -1, -1};
    const int y[] = {-1, -1, -1, -1, -1, -1};
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
