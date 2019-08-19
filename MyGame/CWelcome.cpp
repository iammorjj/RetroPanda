//
//  CWelcome.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 18/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CWelcome.hpp"
using namespace CONSTANTS;

CWelcome::CWelcome() {
    textColorWhite = {255, 255, 255};
    textColorBlack = {0, 0, 0};
    
    font = NULL;
    Surf_Score_Black = NULL;
    Surf_Score_White = NULL;
    
    gameOverHidding = false;
    oldTimeGameOver = 0;
    gameOverHidingRate = 300;
    
    strncpy(buf, "press f to pay for burger", 30);
}

bool CWelcome::OnLoad(const char* File, int Size) {
    if(TTF_Init() < 0 || (font = TTF_OpenFont(File, Size)) == NULL)
        return false;
    Surf_Score_Black = TTF_RenderText_Solid( font, buf, textColorBlack );
    Surf_Score_White = TTF_RenderText_Solid( font, buf, textColorWhite );
    if(Surf_Score_Black == NULL || Surf_Score_White == NULL)
        return false;
    
    return true;
}

void CWelcome::gameOver() {
    if(oldTimeGameOver + this->gameOverHidingRate > SDL_GetTicks())
        return;
    
    oldTimeGameOver = SDL_GetTicks();
    gameOverHidding = !gameOverHidding;
}

void CWelcome::OnRender(SDL_Surface* Surf_Display) {
    if(GLOBAL::GameOver)
        gameOver();
    else
        gameOverHidding = true;
    
    if(!gameOverHidding) {
        CSurface::OnDraw(Surf_Display, Surf_Score_Black, SCREEN_WIDTH / 2 - Surf_Score_Black->clip_rect.w / 2 + 5, 600 + 5);
        CSurface::OnDraw(Surf_Display, Surf_Score_White, SCREEN_WIDTH / 2 - Surf_Score_Black->clip_rect.w / 2, 600);
    }
}

void CWelcome::OnCleanup() {
    SDL_FreeSurface(Surf_Score_Black);
    SDL_FreeSurface(Surf_Score_White);
    TTF_CloseFont(font);
}
