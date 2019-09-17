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
#include "Surface.hpp"

class Animation {
private:
    int frameWidth;
    int frameHeight;
    
    int maxFrames;
    int currentFrame;
    int frameInc;
    
    int frameRateMs;
    int oldTimeMs;
    
    int currentFrameRow;
private:
    int getXCurrentFrame();
    int getYCurrentFrame();
public:
    Animation();
    
    void setCurrentFrameRow(int row);
    
    void setFrameRateMs(int ms);
    
    void setSpriteInfo(int frameWidth, int frameHeight, int maxFrames);
    
    void animate();
    
    void draw(SDL_Surface* display, SDL_Surface* surface, int displayX, int displayY);
};

#endif /* Animation_hpp */
