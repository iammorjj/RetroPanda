//
//  Hero.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "HeroRefactoring.hpp"
#include "BurgerRefactoring.hpp"

bool HeroRefactoring::canCatch(const BurgerRefactoring& obj) {
    return obj.canBeCaught(location);
}

void HeroRefactoring::catchBurger(BurgerRefactoring& obj) {
        obj.burger[location].pop_back();
}
