//
//  Animation.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Animation.hpp"

Animation::Animation() {
    frameWidth = frameHeight = 0;
    
    currentFrame    = 0;
    maxFrames       = 0;
    frameInc        = 1;
    
    frameRate       = 125;
    oldTime         = 0;
}

void Animation::animate() {
    if(oldTime + frameRate > SDL_GetTicks()) {
        return;
    }
    
    oldTime = SDL_GetTicks();
    
    currentFrame += frameInc;
    
    if(currentFrame >= maxFrames) {
        currentFrame = 0;
    }
}

void Animation::setFrameRate(int rate) {
    frameRate = rate;
}

void Animation::setCurrentFrame(int frame) {
    if(frame < 0 || frame >= maxFrames) return;
    
    currentFrame = frame;
}

int Animation::getCurrentFrame() {
    return currentFrame * frameWidth;
}

void Animation::stopFrameInc() {
    frameInc = 0;
}

void Animation::returnFrameInc() {
    frameInc = 1;
}
