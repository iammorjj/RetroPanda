//
//  BurgerRefactoring.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 28/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef BurgerRefactoring_hpp
#define BurgerRefactoring_hpp

#include "SDL/SDL.h"

class HideEffect {
    int oldTime = 0;
    int frameRateMs = 500;
    
public:
    bool hide() {
        if(oldTime + frameRateMs > SDL_GetTicks())
            return false;
        
        oldTime = SDL_GetTicks();
        return true;
    }
};

#include "Entity.hpp"
#include <list>
#include <vector>
#include "BurgerOldVersion.hpp"

#include "HeroRefactoring.hpp"
#include "BurgerItem.hpp"

class BurgerRefactoring: public Entity {
    constexpr static const char * const file = "";
private:
    SDL_Surface* surface;
    std::vector< std::list<BurgerItem> > burgerConveyor;
    HideEffect effect;
    bool running;
private:
    BurgerRefactoring();
    
    void move();
    
    void drawBurgers(SDL_Surface* display);
    
    friend void HeroRefactoring::catchBurger(BurgerRefactoring& obj);
    friend bool HeroRefactoring::canCatch(const BurgerRefactoring& obj);
    
private:
    bool canBeCaught(int location);
    
public:
    bool isMissed();
    
    void newGame();
    void gameOver();
    
public:
    bool load();
    void loop();
    void render(SDL_Surface* display);
    void cleanup();
};

#endif /* BurgerRefactoring_hpp */
