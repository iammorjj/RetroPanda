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
    const char* file = "";
    const int frameWidth = 0;
    const int frameHeight = 0;
    const int maxFrames = 0;
    
    const int xPosition = 0;
    const int yPosition = 0;
    
private:
    SDL_Surface* surface = nullptr;
    Animation animation;
    
    bool running = false;
    
public:
    void stop() {
        running = false;
    }
    void start() {
        running = true;
    }
    
public:
    bool load() {
        surface = CSurfaceOldVersion::OnLoad(file);
        if(!surface)
            return false;
        
        animation.setSpriteInfo(frameWidth, frameHeight, maxFrames);
        return true;
    }
    void loop() {
        if(running)
            animation.animate();
    }
    void render(SDL_Surface* display) {
        // add 2 sides
        animation.draw(display, surface, xPosition, yPosition);
    }
    void cleanup() {
        SDL_FreeSurface(surface);
    }
};

#endif /* Conveyor_h */
