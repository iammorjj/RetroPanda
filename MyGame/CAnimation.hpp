//
//  CAnimation.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CAnimation_hpp
#define CAnimation_hpp

#include <SDL/SDL.h>

class CAnimation {
private:
    int    CurrentFrame;
    
    int     FrameInc;
    
private:
    int     FrameRate; //Milliseconds
    
    long    OldTime;
    
public:
    int    MaxFrames;
    
public:
    CAnimation();
    
    void OnAnimate();
    
public:
    void SetFrameRate(int Rate);
    
    void SetCurrentFrame(int Frame);
    
    int GetCurrentFrame();
};

#endif /* CAnimation_hpp */
