//
//  Advertising.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Advertising_hpp
#define Advertising_hpp

#include "SDL/SDL.h"
#include "Entity.hpp"
#include "Animation.hpp"

class Advertising : public Entity {
private:
    SDL_Surface* surface;
    
    Animation animation;
public:
    Advertising();
    
    bool load();
    void loop();
    void render(SDL_Surface* display);
    void cleanup();
};

#endif /* Advertising_hpp */
