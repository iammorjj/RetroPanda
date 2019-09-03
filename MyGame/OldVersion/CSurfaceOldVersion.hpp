//
//  CSurfaceOldVersion.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef _CSURFACE_H_
#define _CSURFACE_H_

#include <SDL/SDL.h>

#ifndef MAC
#include <SDL/SDL_image.h>
#else
#include <SDL_image/SDL_image.h>
#endif

class CSurfaceOldVersion {
public:
    CSurfaceOldVersion();
    
public:
    static SDL_Surface* OnLoad(const char* File);
    
    static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);
    
    static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H);
    
};

#endif
