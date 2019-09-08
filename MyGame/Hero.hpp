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
#include "CSurfaceOldVersion.hpp"

#include "Location.hpp"

#include <string>

class Burger;

class Hero: public Entity, public Location {
    static const std::string file;
    static const int frameWidth = 0;
    static const int frameHeight = 0;
    static const int maxFrames = 0;
    
    static const int xPosition = 0;
    static const int yPosition = 0;
    
private:
    SDL_Surface* surface;
    Animation animation;
    
    Hero();
    
public:
    void changeLocation(int location);
    
    bool canCatch(const Burger& obj);
    void catchBurger(Burger& obj);
    
public:
    bool load() {
        surface = CSurfaceOldVersion::OnLoad(file.c_str());
        if(!surface)
            return false;
        
        animation.setSpriteInfo(frameWidth, frameHeight, maxFrames);
        return true;
    }
    void loop() {
        animation.animate();
    }
    void render(SDL_Surface* display) {
        animation.draw(display, surface, xPosition, yPosition);
    }
    void cleanup() {
        SDL_FreeSurface(surface);
    }
};

#endif /* Hero_hpp */
