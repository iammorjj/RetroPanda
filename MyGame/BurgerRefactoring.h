//
//  BurgerRefactoring.h
//  MyGame
//
//  Created by Alexander Mordovsky on 28/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef BurgerRefactoring_h
#define BurgerRefactoring_h

#include "Entity.hpp"
#include <list>
#include <vector>

class BurgerRefactoring: public Entity {
    const char* file = "";
private:
    std::vector< std::list<int> > burger = std::vector< std::list<int> >(6);
    
    SDL_Surface* surface = nullptr;
    
    bool running = false;
    bool hiding = false;
    
private:
    void move();
    
    void drawBurgers(SDL_Surface* display) {
//        CSurface::OnDraw(display, Surf_Entity, burg.x,
//                         burg.y,
//                         0, 0, Width, Height);
    }
    
public:
    bool load() {
        surface = CSurface::OnLoad(file);
        if(!surface)
            return false;

        return true;
    }
    void loop() {
        if(running)
            move();
    }
    void render(SDL_Surface* display) {
        if(running || !hiding)
            drawBurgers(display);
    }
    void cleanup() {
        SDL_FreeSurface(surface);
    }
};

#endif /* BurgerRefactoring_h */
