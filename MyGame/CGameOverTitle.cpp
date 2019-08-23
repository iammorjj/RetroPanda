//
//  CGameOverTitle.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 20/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CGameOverTitle.hpp"
#include "Constants.h"

using namespace CONSTANTS;

bool CGameOverTitle::isTitlesLoaded() {
    if( !bestScore.OnLoad(bestScoreFont, textColorWhite, "best score") ||
       
       !welcome.OnLoad(welcomeFont, textColorWhite, "press f to pay for burger") ||
       
       !leaderLine1.OnLoad(leaderFont, textColorGold, "you're the leader now!") ||
       !leaderLine2.OnLoad(leaderFont, textColorGold, "make #billyssubs screen photo") ||
       !leaderLine3.OnLoad(leaderFont, textColorGold, "to take part in the daily draw!") )
        return false;
    
    return true;
}

bool CGameOverTitle::OnLoad() {
    const char* File = FONT.c_str();
    
    if(!TTF_WasInit() && TTF_Init() < 0)
        return false;

    if( !( bestScoreFont = TTF_OpenFont(File, 60)) ||
        !( welcomeFont = TTF_OpenFont(File, 35)) ||
        !(leaderFont = TTF_OpenFont(File, 30)) )
        return false;
    
    if( !isTitlesLoaded() )
        return false;
    
    return true;
}

void CGameOverTitle::hidingEffect() {
    if(prevTime + rate > SDL_GetTicks())
        return;
    
    prevTime = SDL_GetTicks();
    isHide = !isHide;
}

void CGameOverTitle::OnRender(SDL_Surface* Surf_Display) {
    if( !isTitlesLoaded() ) return;
    
    if(GLOBAL::GameOver) {
        hidingEffect();
        
        if(GLOBAL::isLeader) {
            leaderLine1.OnDraw(Surf_Display, SCREEN_WIDTH / 2 - leaderLine1.sFront->clip_rect.w / 2, 630, 3);
            leaderLine2.OnDraw(Surf_Display, SCREEN_WIDTH / 2 - leaderLine2.sFront->clip_rect.w / 2, 650, 3);
            leaderLine3.OnDraw(Surf_Display, SCREEN_WIDTH / 2 - leaderLine3.sFront->clip_rect.w / 2, 670, 3);
            
            bestScore.OnLoad(textColorGold);
        }
        
        bestScore.OnDraw(Surf_Display, SCREEN_WIDTH / 2 - bestScore.sFront->clip_rect.w / 2, 90, 5);
        if(!isHide)
            welcome.OnDraw(Surf_Display, SCREEN_WIDTH / 2 - welcome.sFront->clip_rect.w / 2, 600, 3);
        
    } else
        isHide = true;
}
