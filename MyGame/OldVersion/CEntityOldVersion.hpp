//
//  CEntityOldVersion.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CEntity_hpp
#define CEntity_hpp

#include <vector>
#include "CAnimationOldVersion.hpp"
#include "Constants.h"
#include "Surface.hpp"

class CEntityOldVersion {
public:
    static std::vector<CEntityOldVersion*>    EntityList;
    
protected:
    CAnimationOldVersion      Anim_Control;
    
    SDL_Surface*    Surf_Entity;
    
protected:
    int             CurrentFrameRow;
    
public:
    float           X;
    float           Y;
    
    int             Width;
    int             Height;
    
    int             AnimState;
    
public:
    CEntityOldVersion();
    
    virtual ~CEntityOldVersion();
    
public:
    virtual bool OnLoad(const char* File, int Width, int Height, int MaxFrames);
    
    virtual void OnLoop();
    
    virtual void OnRender(SDL_Surface* Surf_Display);
    
    virtual void OnCleanup();
};

#endif /* CEntity_hpp */
