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

#ifndef MAC
#include <SDL/SDL_ttf.h>
#else
#include <SDL_ttf/SDL_ttf.h>
#endif

class CScore: public CEntity {
    friend class CApp;
private:
    SDL_Color       textColorWhite;
    SDL_Color       textColorBlack;
    SDL_Color       textColorGold;
    
    int             bestScore;
    bool            gameOverHidding;
    
    bool            leader;
    
    TTF_Font*       font;
    TTF_Font*       bestScoreFont;
    TTF_Font*       leaderFont;
    
    SDL_Surface*    Surf_Score_Black;
    SDL_Surface*    Surf_Score_White;
    
    SDL_Surface*    Surf_Leader_Black;
    SDL_Surface*    Surf_Leader_Gold;
    
    SDL_Surface*    Surf_BestScore_Black;
    SDL_Surface*    Surf_BestScore;
    
    SDL_Surface*    Surf_Participate_Black,* Surf_Participate_Black2;
    SDL_Surface*    Surf_Participate_Gold,* Surf_Participate_Gold2;
    
    int             score;
    char            buf[5];
    
    CScore();
    
    bool OnLoad(const char* File, int Size);
    
    void OnRender(SDL_Surface* Surf_Display);
    
    void OnCleanup();
};

#endif /* CScore_hpp */
