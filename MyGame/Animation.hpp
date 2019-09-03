//
//  Animation.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Animation_hpp
#define Animation_hpp

#include "SDL/SDL.h"
#include "CSurfaceOldVersion.hpp"

class Animation {
private:
    int frameWidth = 0;
    int frameHeight = 0;
    
    int maxFrames = 0;
    int currentFrame = 0;
    int frameInc = 1;
    
    int frameRateMs = 125;
    int oldTimeMs = 0;
    
    int currentFrameRow = 0;
    
private:
    int getXPosCurrentFrame() {
        return currentFrame * frameWidth;
    }
    int getYPosCurrentFrame() {
        return currentFrameRow * frameHeight;
    }
    
public:
    void setCurrentFrameRow(int row) {
        currentFrameRow = row;
    }
    
    void setSpriteInfo(int frameWidth, int frameHeight, int maxFrames) {
        this->frameWidth = frameWidth;
        this->frameHeight = frameHeight;
        this->maxFrames = maxFrames;
    }
    
    void animate() {
        if(oldTimeMs + frameRateMs > SDL_GetTicks())
            return;
        
        oldTimeMs = SDL_GetTicks();
        
        currentFrame += frameInc;
        
        if(currentFrame >= maxFrames)
            currentFrame = 0;
    }
    
    void draw(SDL_Surface* display, SDL_Surface* surface, int displayX, int displayY) {
        CSurfaceOldVersion::OnDraw(display, surface, displayX, displayY,
                         getXPosCurrentFrame(), getYPosCurrentFrame(), frameWidth, frameHeight);
    }
};

#endif /* Animation_hpp */
