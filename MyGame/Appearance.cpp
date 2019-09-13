//
//  BurgerAppearance.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 12/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "BurgerAppearance.hpp"
#include "Burger.hpp"

Uint32 addBurger(Uint32 interval, void* param) {
    
}

void BurgerAppearance::start(Burger* burger) {
    timer = SDL_AddTimer(delay, addBurger, burger);
}

void BurgerAppearance::changeDelay() {
    
}
