//
//  CAnimationOldVersion.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CAnimation_hpp
#define CAnimation_hpp

#include <SDL/SDL.h>

class CAnimationOldVersion {
private:
    int    CurrentFrame;
    
    int     FrameInc;
    
private:
    int     FrameRate; //Milliseconds
    
    long    OldTime;
    
public:
    int    MaxFrames;
    
public:
    int   CurrentFrameRow;
    
public:
    CAnimationOldVersion();
    
    void OnAnimate();
    
public:
    void SetFrameRate(int Rate);
    
    void SetCurrentFrame(int Frame);
    
    int GetCurrentFrame();
    
    void StopFrameInc();
    
    void ReturnFrameInc();
};

#endif /* CAnimation_hpp */
