//
//  CBackground.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 18/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CBackground_hpp
#define CBackground_hpp

#include "CEntity.hpp"

class CBackground: public CEntity {
private:
    SDL_Surface*    Surf_Background;
    SDL_Surface*    Surf_Sides;
    
public:
    bool OnLoad(const char* File, int Size);
    
    void OnRender(SDL_Surface* Surf_Display);
    
    void OnCleanup();

    CBackground();
    
    bool OnLoad();
    
    void RenderSides(SDL_Surface* Surf_Display);
};

#endif /* CBackground_hpp */
