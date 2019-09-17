//
//  Burger.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 03/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Burger.hpp"
#include "Global.hpp"
using namespace Global;

#include "Surface.hpp"

namespace {
    const std::string file = Global::path+"burger.png";
    const int frameWidth = 192;
    
    const int lineNumber = 6;
    
    const double xVelNewLevel = 7.;
    const double yVelNewLevel = xVelNewLevel * 4./7.;
    
    const int xStopLeft = 300;
    const int xStopRight = scrWidth - frameWidth - xStopLeft;
    const int xCanBeCaughtLeft = xStopLeft - 15;
    const int xCanBeCaughtRight = xStopRight + 15;
}

Burger::Burger(): surface(nullptr), running(false),
    burgerLine(std::vector< std::list<BurgerItem> >(lineNumber)), creator(this) {}

void Burger::move() {
    int deltaTicks = moveTimer.get_ticks();
    
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
    return burgerLine[location].back().getXCoord() > xCanBeCaughtLeft &&
        burgerLine[location].back().getXCoord() < xCanBeCaughtRight;
}
void Burger::deleteBurger(int location) {
    burgerLine[location].pop_back();
}

void Burger::newGame() {
    creator.start();
    running = true;
}
void Burger::gameOver() {
    creator.stop();
    moveTimer.stop();
    running = false;
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
    SDL_FreeSurface(surface);
}
