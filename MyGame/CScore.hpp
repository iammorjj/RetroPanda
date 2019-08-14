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
    SDL_Color       textColorWhite;
    SDL_Color       textColorBlack;
    
    TTF_Font*       font;
    SDL_Surface*    Surf_Score_Black;
    SDL_Surface*    Surf_Score_White;
    
    int             score;
    char            buf[5];
    
    CScore();
    
    bool OnLoad(const char* File, int Size);
    
    void OnRender(SDL_Surface* Surf_Display);
    
    void OnCleanup();
};

#endif /* CScore_hpp */
