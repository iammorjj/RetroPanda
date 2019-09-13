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

#include "HideEffect.h"

#include "Entity.hpp"
#include <list>
#include <vector>

#include "Hero.hpp"
#include "BurgerItem.hpp"

#include "BurgerCreator.hpp"

class Burger: public Entity {
    friend class BurgerCreator;
private:
    SDL_Surface* surface;
    
    bool running;
    
    std::vector< std::list<BurgerItem> > burgerLine;
    
    BurgerCreator creator;
    
    HideEffect effect;
private:
    void move();
    
    void drawBurgers(SDL_Surface* display);
    
    friend bool Hero::canCatch(const Burger& obj);
    friend void Hero::catchBurger(Burger& obj);
public:
    Burger();
    
    bool isMissed();
    
    void newGame();
    void gameOver();
    
    void newLevelMovementSpeed();
    void newLevelAppearanceSpeed();
    
    bool load();
    void loop();
    void render(SDL_Surface* display);
    void cleanup();
};

#endif /* Burger_hpp */
