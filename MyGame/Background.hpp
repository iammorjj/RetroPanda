//
//  Background.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 10/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Background_hpp
#define Background_hpp

#include "SDL/SDL.h"
#include "Entity.hpp"

class Background : public Entity {
private:
    SDL_Surface* surface;
public:
    Background();
    
    bool load();
    void loop();
    void render(SDL_Surface* display);
    void cleanup();
};

#endif /* Background_hpp */
