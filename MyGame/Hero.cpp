//
//  Hero.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 03/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Hero.hpp"
#include "Burger.hpp"

const std::string Hero::file = std::string("fileName");

Hero::Hero(): surface(nullptr) {}

void Hero::changeLocation(int location) {
    animation.setCurrentFrameRow(this->location = location);
}

bool Hero::canCatch(const Burger &obj) {
    return true;
}

void Hero::catchBurger(Burger &obj) {
    obj.burgerLine[location].pop_back();
}


