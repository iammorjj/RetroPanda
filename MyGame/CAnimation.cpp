//
//  CAnimation.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CAnimation.hpp"

CAnimation::CAnimation() {
    CurrentFrame    = 0;
    MaxFrames       = 0;
    FrameInc        = 1;
    
    FrameRate       = 125; //Milliseconds
    OldTime         = 0;
}

void CAnimation::OnAnimate() {
    if(OldTime + FrameRate > SDL_GetTicks()) {
        return;
    }
    
    OldTime = SDL_GetTicks();
    
    CurrentFrame += FrameInc;
    
    if(CurrentFrame >= MaxFrames) {
        CurrentFrame = 0;
    }
}

void CAnimation::SetFrameRate(int Rate) {
    FrameRate = Rate;
}

void CAnimation::SetCurrentFrame(int Frame) {
    if(Frame < 0 || Frame >= MaxFrames) return;
    
    CurrentFrame = Frame;
}

int CAnimation::GetCurrentFrame() {
    return CurrentFrame;
}

void CAnimation::StopFrameInc() {
    FrameInc = 0;
}

void CAnimation::ReturnFrameInc() {
    FrameInc = 1;
}
