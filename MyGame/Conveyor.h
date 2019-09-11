//
//  Conveyor.h
//  MyGame
//
//  Created by Alexander Mordovsky on 28/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Conveyor_h
#define Conveyor_h

#include "Entity.hpp"
#include "Animation.hpp"

class Conveyor: public Entity {
private:
    SDL_Surface* surface;
    
    bool running;
    
    Animation animation;
private:
    void drawSide(SDL_Surface* display, int side);
public:
    Conveyor();
    
    void stop();
    void start();
public:
    bool load();
    void loop();
    void render(SDL_Surface* display);
    void cleanup();
};

#endif /* Conveyor_h */
