//
//  Hero.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 03/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Hero_hpp
#define Hero_hpp

#include "Entity.hpp"
#include "Animation.hpp"
#include "Surface.hpp"

#include "Location.hpp"

class Burger;

class Hero: public Entity, public Location {    
private:
    SDL_Surface* surface;
    
    Animation animation;
public:
    Hero();
    
    void changeLocation(int location);
    
    bool canCatch(const Burger& obj);
    void catchBurger(Burger& obj);
    
    bool load();
    void loop();
    void render(SDL_Surface* display);
    void cleanup();
};

#endif /* Hero_hpp */
