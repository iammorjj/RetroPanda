//
//  CBackgroundOldVersion.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 18/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CBackground_hpp
#define CBackground_hpp

#include "CEntityOldVersion.hpp"

class CBackgroundOldVersion: public CEntityOldVersion {
private:
    SDL_Surface*    Surf_Background;
    SDL_Surface*    Surf_Sides;
    
public:
    bool OnLoad(const char* File, int Size);
    
    void OnRender(SDL_Surface* Surf_Display);
    
    void OnCleanup();

    CBackgroundOldVersion();
    
    bool OnLoad();
    
    void RenderSides(SDL_Surface* Surf_Display);
};

#endif /* CBackground_hpp */
