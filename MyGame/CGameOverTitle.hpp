//
//  CGameOverTitle.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 20/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CGameOverTitle_hpp
#define CGameOverTitle_hpp

#include "Title.hpp"

class CGameOverTitle {
    friend class CApp;
private:
    SDL_Color       textColorWhite = {255, 255, 255};
    SDL_Color       textColorGold = {255, 215, 0};
    
    bool            isHide = false;
    
    TTF_Font*       bestScoreFont = nullptr;
    TTF_Font*       welcomeFont = nullptr;
    TTF_Font*       leaderFont = nullptr;
    
    Title           bestScore;
    Title           welcome;
    Title           leaderLine1, leaderLine2, leaderLine3;
    
    Title leaderLine[3];
    
    bool            isTitlesLoaded();
    
    Uint32          prevTime = 0;
    int             rate = 300;
    void            hidingEffect();
    
    ~CGameOverTitle() {
        TTF_CloseFont(bestScoreFont);
        TTF_CloseFont(welcomeFont);
        TTF_CloseFont(leaderFont);
    }
    
    bool OnLoad();
    
    void OnRender(SDL_Surface* Surf_Display);
};

#endif /* CGameOverTitle_hpp */
