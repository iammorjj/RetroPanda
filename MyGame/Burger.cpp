//
//  Burger.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 03/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Burger.hpp"
#include "Surface.hpp"
#include "BurgerConstants.h"

using namespace burgerConstants;

Burger::Burger(): surface(nullptr), running(false),
    burgerLine(std::vector< std::list<BurgerItem> >(lineNumber)), creator(this) {}

void Burger::move() {
    int deltaTicks = moveTimer.getTicks();
    
    for(auto &line: burgerLine)
        for(auto &burger: line)
            burger.move(deltaTicks);
    
    moveTimer.start();
}

void Burger::drawBurgers(SDL_Surface* display) {
    for(auto line: burgerLine)
        for(auto burger: line)
            Surface::draw(display, surface, burger.getXCoord(), burger.getYCoord());
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

bool Burger::canBeCaught(int location) const {
    if(burgerLine[location].empty())
        return false;
    
    return burgerLine[location].back().getXCoord() > xCanBeCaughtLeft &&
        burgerLine[location].back().getXCoord() < xCanBeCaughtRight;
}
void Burger::deleteBurger(int location) {
    burgerLine[location].pop_back();
}

void Burger::newGame() {
    cleanBurgers();
    
    BurgerItem::resetVelocity();
    creator.resetDelay();
    creator.start();
    
    moveTimer.start();
    running = true;
}
void Burger::gameOver() {
    creator.stop();
    moveTimer.stop();
    running = false;
}

void Burger::cleanBurgers() {
    for(auto& line: burgerLine)
        line.clear();
}

void Burger::newLevelMovementSpeed() {
    BurgerItem::xVel += xVelNewLevel;
    BurgerItem::yVel += yVelNewLevel;
}
void Burger::newLevelAppearanceSpeed() {
    creator.changeDelay();
}

bool Burger::load() {
    surface = Surface::load(file.c_str());
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
    cleanBurgers();
    SDL_FreeSurface(surface);
}
