//
//  CAnimationOldVersion.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CAnimationOldVersion.hpp"

CAnimationOldVersion::CAnimationOldVersion() {
    CurrentFrame    = 0;
    MaxFrames       = 0;
    FrameInc        = 1;
    
    FrameRate       = 125; //Milliseconds
    OldTime         = 0;
}

void CAnimationOldVersion::OnAnimate() {
    if(OldTime + FrameRate > SDL_GetTicks()) {
        return;
    }
    
    OldTime = SDL_GetTicks();
    
    CurrentFrame += FrameInc;
    
    if(CurrentFrame >= MaxFrames) {
        CurrentFrame = 0;
    }
}

void CAnimationOldVersion::SetFrameRate(int Rate) {
    FrameRate = Rate;
}

void CAnimationOldVersion::SetCurrentFrame(int Frame) {
    if(Frame < 0 || Frame >= MaxFrames) return;
    
    CurrentFrame = Frame;
}

int CAnimationOldVersion::GetCurrentFrame() {
    return CurrentFrame;
}

void CAnimationOldVersion::StopFrameInc() {
    FrameInc = 0;
}

void CAnimationOldVersion::ReturnFrameInc() {
    FrameInc = 1;
}
