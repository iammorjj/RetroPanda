//
//  CScoreOldVersion.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 11/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CScore_hpp
#define CScore_hpp

#include "CEntityOldVersion.hpp"
#include "Title.hpp"

#ifndef MAC
#include <SDL/SDL_ttf.h>
#else
#include <SDL_ttf/SDL_ttf.h>
#endif

class CScoreOldVersion: public CEntityOldVersion {
    friend class CApp;
private:
    int     score;
    int     bestScore;
    Title   tScore;
    char    buf[5];
    
    CScoreOldVersion();
    
    bool OnLoad(const char* File, int Size);
    
    void OnRender(SDL_Surface* Surf_Display);
    
    void OnCleanup() {}
};

#endif /* CScore_hpp */
