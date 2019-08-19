//
//  CWelcome.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 18/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CWelcome_hpp
#define CWelcome_hpp

#include "CEntity.hpp"

#ifndef MAC
#include <SDL/SDL_ttf.h>
#else
#include <SDL_ttf/SDL_ttf.h>
#endif

class CWelcome: public CEntity {
    friend class CApp;
private:
    SDL_Color       textColorWhite;
    SDL_Color       textColorBlack;
    
    TTF_Font*       font;
    SDL_Surface*    Surf_Score_Black;
    SDL_Surface*    Surf_Score_White;
    
    bool            gameOverHidding;
    Uint32          oldTimeGameOver;
    Uint32          gameOverHidingRate;
    
    char            buf[30];
    
    CWelcome();
    
    void gameOver();
    
    bool OnLoad(const char* File, int Size);
    
    void OnRender(SDL_Surface* Surf_Display);
    
    void OnCleanup();
    
};

#endif /* CWelcome_hpp */
