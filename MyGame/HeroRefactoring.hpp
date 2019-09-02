//
//  HeroRefactoring.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef HeroRefactoring_hpp
#define HeroRefactoring_hpp

#include "Entity.hpp"
#include "Animation.hpp"
#include "CSurface.hpp"

#include "LocationRefactoring.hpp"

#include <string>

class BurgerRefactoring;

class HeroRefactoring: public Entity, public LocationRefactoring {
    static const std::string file;
    static const int frameWidth = 0;
    static const int frameHeight = 0;
    static const int maxFrames = 0;
    
    static const int xPosition = 0;
    static const int yPosition = 0;

private:
    SDL_Surface* surface = nullptr;
    Animation animation;
    
    bool hasBurger = false;
    
public:
    void changeLocation(Location location) {
        animation.setCurrentFrameRow(this->location = location);
    }
    
    bool canCatch(const BurgerRefactoring& obj);
    void catchBurger(BurgerRefactoring& obj);
    
public:
    bool load() {
        surface = CSurface::OnLoad(file.c_str());
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
