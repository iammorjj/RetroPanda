//
//  CScore.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 11/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CScore.hpp"

CScore::CScore() {
    textColorWhite = {255, 255, 255};
    textColorBlack = {0, 0, 0};
    
    font = NULL;
    Surf_Score_Black = NULL;
    Surf_Score_White = NULL;
    
    score = 0;
}

bool CScore::OnLoad(const char* File, int Size) {
    return TTF_Init() > -1 && (font = TTF_OpenFont(File, Size)) != NULL;
}

void CScore::OnRender(SDL_Surface* Surf_Display) {
    sprintf(buf, "%d", score);
    Surf_Score_Black = TTF_RenderText_Solid( font, buf, textColorBlack );
    Surf_Score_White = TTF_RenderText_Solid( font, buf, textColorWhite );
    
    if(Surf_Score_Black == NULL || Surf_Score_White == NULL || Surf_Display == NULL) return;
    
    CSurface::OnDraw(Surf_Display, Surf_Score_Black, CONSTANTS::BACKGROUND_WIDTH / 2 - Surf_Score_Black->clip_rect.w / 2 + 10, 60 + 10);
    CSurface::OnDraw(Surf_Display, Surf_Score_White, CONSTANTS::BACKGROUND_WIDTH / 2 - Surf_Score_Black->clip_rect.w / 2, 60);
}

void CScore::OnCleanup() {
    SDL_FreeSurface(Surf_Score_Black);
    SDL_FreeSurface(Surf_Score_White);
    TTF_CloseFont(font);
}
