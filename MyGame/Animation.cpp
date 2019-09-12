//
//  Animation.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 11/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Animation.hpp"

Animation::Animation() : frameWidth(0), frameHeight(0), maxFrames(0),
currentFrame(0), frameInc(1), frameRateMs(125), oldTimeMs(0), currentFrameRow(0) {}

int Animation::getXCurrentFrame() {
    return currentFrame * frameWidth;
}
int Animation::getYCurrentFrame() {
    return currentFrameRow * frameHeight;
}

void Animation::setCurrentFrameRow(int row) {
    currentFrameRow = row;
}

void Animation::setFrameRateMs(int ms) {
    frameRateMs = ms;
}

void Animation::setSpriteInfo(int frameWidth, int frameHeight, int maxFrames) {
    this->frameWidth = frameWidth;
    this->frameHeight = frameHeight;
    this->maxFrames = maxFrames;
}

void Animation::animate() {
    if(oldTimeMs + frameRateMs > SDL_GetTicks())
        return;
    
    oldTimeMs = SDL_GetTicks();
    
    currentFrame += frameInc;
    
    if(currentFrame >= maxFrames)
        currentFrame = 0;
}

void Animation::draw(SDL_Surface* display, SDL_Surface* surface, int displayX, int displayY) {
    Surface::draw(display, surface, displayX, displayY,
                  getXCurrentFrame(), getYCurrentFrame(), frameWidth, frameHeight);
}
