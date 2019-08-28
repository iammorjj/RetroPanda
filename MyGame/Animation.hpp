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
#include "CSurface.hpp"

class Animation {
private:
    int frameWidth;
    int frameHeight;
    
private:
    int maxFrames;
    int currentFrame;
    int frameInc;
    
private:
    int frameRate;
    int oldTime;
    
private:
    int getXPosCurrentFrame() {
        return currentFrame * frameWidth;
    }
    int getYPosCurrentFrame() {
        return currentFrameRow * frameHeight;
    }
    
private:
    int currentFrameRow;
    
public:
    void setCurrentFrameRow(int row) { currentFrameRow = row; }
    
public:
    Animation();
    
    void animate();
    
public:
    void draw(SDL_Surface* display, SDL_Surface* surface, int displayX, int displayY) {
        CSurface::OnDraw(display, surface, displayX, displayY,
                         getXPosCurrentFrame(), getYPosCurrentFrame(), frameWidth, frameHeight);
    }
    
    
    
public:
    void setSpriteInfo(int frameWidth, int frameHeight, int maxFrames) {
        this->frameWidth = frameWidth;
        this->frameHeight = frameHeight;
        this->maxFrames = maxFrames;
    }
    
public:
    void setFrameRate(int rate);
    
    void setCurrentFrame(int frame);
    
    int getCurrentFrame();
    
    void stopFrameInc();
    
    void returnFrameInc();
};

#endif /* Animation_hpp */
