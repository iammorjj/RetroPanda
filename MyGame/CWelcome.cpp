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
    Surf_Welcome_Black = NULL;
    Surf_Welcome_White = NULL;

    gameOverHidding = false;
    oldTimeGameOver = 0;
    gameOverHidingRate = 300;
}

bool CWelcome::OnLoad(const char* File, int Size) {
    if(TTF_Init() < 0 || (font = TTF_OpenFont(File, Size)) == NULL)
        return false;
    Surf_Welcome_Black = TTF_RenderText_Solid( font, "press f to pay for burger", textColorBlack );
    Surf_Welcome_White = TTF_RenderText_Solid( font, "press f to pay for burger", textColorWhite );
    if(Surf_Welcome_Black == NULL || Surf_Welcome_White == NULL)
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
        CSurface::OnDraw(Surf_Display, Surf_Welcome_Black, SCREEN_WIDTH / 2 - Surf_Welcome_Black->clip_rect.w / 2 + 5, 600 + 2);
        CSurface::OnDraw(Surf_Display, Surf_Welcome_White, SCREEN_WIDTH / 2 - Surf_Welcome_White->clip_rect.w / 2, 600);
    }
}

void CWelcome::OnCleanup() {
    SDL_FreeSurface(Surf_Welcome_Black);
    SDL_FreeSurface(Surf_Welcome_White);
    TTF_CloseFont(font);
}
