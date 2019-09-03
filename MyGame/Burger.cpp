//
//  Burger.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 03/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Burger.hpp"

const std::string Burger::file = std::string("fileName");

Burger::Burger(): surface(nullptr), running(false),
    burgerLine(std::vector< std::list<BurgerItem> >(lineNumber)) {}

void move() {
    // not completed
}

void Burger::drawBurgers(SDL_Surface* display) {
    for(auto line: burgerLine)
        for(auto burger: line)
            CSurfaceOldVersion::OnDraw(display, surface, burger.getXCoord(), burger.getYCoord());
}

bool Burger::canBeCaught(int location) {
    // not completed
    return true;
}

bool Burger::isMissed() {
    // not completed
    return true;
}

void Burger::newGame() {
    running = true;
}

void Burger::gameOver() {
    running = false;
}

bool Burger::load() {
    surface = CSurfaceOldVersion::OnLoad(file.c_str());
    if(!surface)
        return false;
    
    return true;
}

void Burger::loop() {
    if(running)
        move();
}

void Burger::render(SDL_Surface* display) {
    if(running || (static_cast<void>(effect.hide()), !effect.isHide))
        drawBurgers(display);
}

void Burger::cleanup() {
    SDL_FreeSurface(surface);
}
