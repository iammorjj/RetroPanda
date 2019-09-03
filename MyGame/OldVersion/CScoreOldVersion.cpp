//
//  CScoreOldVersion.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 11/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CScoreOldVersion.hpp"
using namespace CONSTANTS;

CScoreOldVersion::CScoreOldVersion() {
    score = bestScore = 2;
}

bool CScoreOldVersion::OnLoad(const char* File, int Size) {
    if( !TTF_WasInit() && TTF_Init() < 0 )
        return false;
    
    return tScore.OnLoadFont(TTF_OpenFont(File, Size));
}

void CScoreOldVersion::OnRender(SDL_Surface* Surf_Display) {
    sprintf(buf, "%d", score);
    
    tScore.changeTitle(buf);
    tScore.OnRender();
    
    if(GLOBAL::GameOver) {
        if(score > bestScore) {
            GLOBAL::isLeader = true;
            bestScore = score;
        }
        score = bestScore;
    } else {
        GLOBAL::isLeader = false;
    }

    tScore.OnDraw(Surf_Display, SCREEN_WIDTH / 2 - tScore.sFront->clip_rect.w / 2, 80, 16);
}
