//
//  Burger.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 03/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Burger.hpp"

namespace {
    const std::string file = "kek";
    const int lineNumber = 6;
}

Burger::Burger(): surface(nullptr), running(false),
    burgerLine(std::vector< std::list<BurgerItem> >(lineNumber)) {}

void Burger::move() {
    for(auto &line: burgerLine)
        for(auto &burger: line)
            burger.move(228);
}

void Burger::drawBurgers(SDL_Surface* display) {
    for(auto line: burgerLine)
        for(auto burger: line)
            CSurfaceOldVersion::OnDraw(display, surface, burger.getXCoord(), burger.getYCoord());
}

bool Burger::isMissed() {
    for(auto line: burgerLine)
        if(!line.empty()) {
            auto burger = line.back();
            if(!burger.canMoveDown())
                return true;
        }
    
    return false;
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
