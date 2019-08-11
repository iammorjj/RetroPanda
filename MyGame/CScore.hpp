//
//  CScore.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 11/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CScore_hpp
#define CScore_hpp

#include "CEntity.hpp"
#include <SDL_ttf/SDL_ttf.h>

class CScore: public CEntity {
    friend class CApp;
private:
    SDL_Color       textColorWhite = {255, 255, 255};
    SDL_Color       textColorBlack = {0, 0, 0};
    
    TTF_Font*       font = NULL;
    SDL_Surface*    Surf_Score_Black = NULL;
    SDL_Surface*    Surf_Score_White = NULL;
    
    int             score = 0;
    char            buf[5];
    
    bool OnLoad(const char* File, int Size) {
        return TTF_Init() > -1 && (font = TTF_OpenFont(File, Size)) != NULL;
    }
    
    void OnRender(SDL_Surface* Surf_Display) {
        sprintf(buf, "%d", score);
        Surf_Score_Black = TTF_RenderText_Solid( font, buf, textColorBlack );
        Surf_Score_White = TTF_RenderText_Solid( font, buf, textColorWhite );
        
        if(Surf_Score_Black == NULL || Surf_Score_White == NULL || Surf_Display == NULL) return;
        
        CSurface::OnDraw(Surf_Display, Surf_Score_Black, CONSTANTS::BACKGROUND_WIDTH / 2 - Surf_Score_Black->clip_rect.w / 2 + 10, 60 + 10);
        CSurface::OnDraw(Surf_Display, Surf_Score_White, CONSTANTS::BACKGROUND_WIDTH / 2 - Surf_Score_Black->clip_rect.w / 2, 60);
    }
    
    void OnCleanup() {
        SDL_FreeSurface(Surf_Score_Black);
        SDL_FreeSurface(Surf_Score_White);
        TTF_CloseFont(font);
    }

};

#endif /* CScore_hpp */
