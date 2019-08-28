//
//  Entity.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include "SDL/SDL.h"

class Entity {
public:
    virtual bool load() = 0;
    virtual void loop() = 0;
    virtual void render(SDL_Surface* Surf_Display) = 0;
    virtual void cleanup() = 0;
};

#endif /* Entity_hpp */
