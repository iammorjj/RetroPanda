//
//  Burger.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 28/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Burger_hpp
#define Burger_hpp

#include "SDL/SDL.h"

#include <list>
#include <vector>

#include "HideEffect.h"
#include "Entity.hpp"
#include "Timer.hpp"
#include "BurgerItem.hpp"
#include "BurgerCreator.hpp"

#include "Global.hpp"
using namespace Global;

class Burger: public Entity {
private:
    SDL_Surface* surface;
    
    bool running;
    
    std::vector< std::list<BurgerItem> > burgerLine;
    
    BurgerCreator creator;
    
    HideEffect effect;
    
    Timer moveTimer;
private:
    void move();
    
    void drawBurgers(SDL_Surface* display);
    
    friend void BurgerCreator::createBurger();
public:
    Burger();
    
    bool isMissed();
    
    bool canBeCaught(int location) const;
    void deleteBurger(int location);
    
    void newGame();
    void gameOver();
    
    void cleanBurgers();
    
    void newLevelMovementSpeed();
    void newLevelAppearanceSpeed();
    
    bool load();
    void loop();
    void render(SDL_Surface* display);
    void cleanup();
};

#endif /* Burger_hpp */
