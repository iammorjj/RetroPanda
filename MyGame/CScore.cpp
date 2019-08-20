//
//  CScore.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 11/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CScore.hpp"
using namespace CONSTANTS;

CScore::CScore() {
    textColorWhite = {255, 255, 255};
    textColorBlack = {0, 0, 0};
    textColorGold = {255, 215, 0};
    
    leaderFont = bestScoreFont = font = NULL;
    Surf_Score_Black = NULL;
    Surf_Score_White = NULL;
    Surf_BestScore_Black = NULL;
    Surf_BestScore = NULL;
    Surf_Participate_Black = Surf_Participate_Black2 = NULL;
    Surf_Participate_Gold = Surf_Participate_Gold2 = NULL;
    
    Surf_Leader_Black = NULL;
    Surf_Leader_Gold = NULL;
    
    gameOverHidding = false;
    leader = false;
    
    score = bestScore = 2;
}

bool CScore::OnLoad(const char* File, int Size) {
    TTF_Init() > -1 && (font = TTF_OpenFont(File, Size)) && (bestScoreFont = TTF_OpenFont(File, 60)) && (leaderFont = TTF_OpenFont(File, 30))
    != NULL;
    Surf_BestScore_Black = TTF_RenderText_Solid( bestScoreFont, "best score", textColorBlack );
    Surf_BestScore = TTF_RenderText_Solid( bestScoreFont, "best score", textColorWhite );
    Surf_Leader_Black = TTF_RenderText_Solid( leaderFont, "you're the leader now!", textColorBlack );
    Surf_Leader_Gold = TTF_RenderText_Solid( leaderFont, "you're the leader now!", textColorGold );
    Surf_Participate_Black = TTF_RenderText_Solid( leaderFont, "make #billyssubs screen photo", textColorBlack );
    Surf_Participate_Gold = TTF_RenderText_Solid( leaderFont, "make #billyssubs screen photo", textColorGold );
    Surf_Participate_Black2 = TTF_RenderText_Solid( leaderFont, "to take part in the daily draw!", textColorBlack );
    Surf_Participate_Gold2 = TTF_RenderText_Solid( leaderFont, "to take part in the daily draw!", textColorGold );
    // omg
    return true;
}

void CScore::OnRender(SDL_Surface* Surf_Display) {
    sprintf(buf, "%d", score);
    Surf_Score_Black = TTF_RenderText_Solid( font, buf, textColorBlack );
    Surf_Score_White = TTF_RenderText_Solid( font, buf, textColorWhite );
    
    if(Surf_Score_Black == NULL || Surf_Score_White == NULL ||
       Surf_BestScore_Black == NULL || Surf_BestScore == NULL ||
       Surf_Display == NULL) return;
    
    if(GLOBAL::GameOver) {
        if(score > bestScore) {
            leader = true;
            bestScore = score;
            Surf_BestScore = TTF_RenderText_Solid( bestScoreFont, "best score", textColorGold );
        }
        score = bestScore;
        gameOverHidding = false;
    } else {
        leader = false;
        gameOverHidding = true;
        Surf_BestScore = TTF_RenderText_Solid( bestScoreFont, "best score", textColorWhite );
    }
    
    if(!gameOverHidding) {
        CSurface::OnDraw(Surf_Display, Surf_BestScore_Black, SCREEN_WIDTH / 2 - Surf_BestScore_Black->clip_rect.w / 2 + 5, 90 + 5);
        CSurface::OnDraw(Surf_Display, Surf_BestScore, SCREEN_WIDTH / 2 - Surf_BestScore->clip_rect.w / 2, 90);
        if(leader) {
            CSurface::OnDraw(Surf_Display, Surf_Leader_Black, SCREEN_WIDTH / 2 - Surf_Leader_Black->clip_rect.w / 2 + 5, 630 + 3);
            CSurface::OnDraw(Surf_Display, Surf_Leader_Gold, SCREEN_WIDTH / 2 - Surf_Leader_Gold->clip_rect.w / 2, 630 + 3);
            
            CSurface::OnDraw(Surf_Display, Surf_Participate_Black, SCREEN_WIDTH / 2 - Surf_Participate_Black->clip_rect.w / 2 + 5, 650 + 3);
            CSurface::OnDraw(Surf_Display, Surf_Participate_Gold, SCREEN_WIDTH / 2 - Surf_Participate_Gold->clip_rect.w / 2, 650 + 3);
            CSurface::OnDraw(Surf_Display, Surf_Participate_Black2, SCREEN_WIDTH / 2 - Surf_Participate_Black2->clip_rect.w / 2 + 5, 670 + 3);
            CSurface::OnDraw(Surf_Display, Surf_Participate_Gold2, SCREEN_WIDTH / 2 - Surf_Participate_Gold2->clip_rect.w / 2, 670 + 3);
        }
    }
    
    CSurface::OnDraw(Surf_Display, Surf_Score_Black, SCREEN_WIDTH / 2 - Surf_Score_Black->clip_rect.w / 2 + 16, 80 + 16);
    CSurface::OnDraw(Surf_Display, Surf_Score_White, SCREEN_WIDTH / 2 - Surf_Score_White->clip_rect.w / 2, 80);
}

void CScore::OnCleanup() {
    SDL_FreeSurface(Surf_Score_Black);
    SDL_FreeSurface(Surf_Score_White);
    SDL_FreeSurface(Surf_BestScore_Black);
    SDL_FreeSurface(Surf_BestScore);
    SDL_FreeSurface(Surf_Leader_Black);
    SDL_FreeSurface(Surf_Leader_Gold);
    SDL_FreeSurface(Surf_Participate_Black);
    SDL_FreeSurface(Surf_Participate_Gold);
    SDL_FreeSurface(Surf_Participate_Black2);
    SDL_FreeSurface(Surf_Participate_Gold2);
    TTF_CloseFont(font);
}
