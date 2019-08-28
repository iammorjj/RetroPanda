//
//  Hero.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Hero_hpp
#define Hero_hpp

#include "Entity.hpp"
#include "Location.h"
#include "Animation.hpp"
#include "CSurface.hpp"

const char* file = "";
const int frameWidth = 0;
const int frameHeight = 0;
const int maxFrames = 0;

const int xPosition = 0;
const int yPosition = 0;

class Hero: public Entity, public LocationClass {
private:
    SDL_Surface* surface = nullptr;
    Animation animation;
    
public:
    bool load() {
        surface = CSurface::OnLoad(file);
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

public:
    void changeLocation(Location location) {
        animation.setCurrentFrameRow(this->location = location);
    }
};

#endif /* Hero_hpp */
