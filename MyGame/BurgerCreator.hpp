//
//  BurgerCreator.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 12/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef BurgerAppearance_hpp
#define BurgerAppearance_hpp

#include "SDL/SDL.h"

class Burger;

class BurgerCreator {
private:
    SDL_TimerID timer;
    Uint32 delay;
    
    bool isDelayChanged;
    
    Burger* burger;
public:
    BurgerCreator(Burger* burger);
    
    void start();
    void stop();
    void restartTimer();
    
    void createBurger();
    
    void changeDelay();
};

#endif /* Appearance_hpp */
