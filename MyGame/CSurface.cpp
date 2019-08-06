//
//  CSurface.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CSurface.hpp"

CSurface::CSurface() {
}

SDL_Surface* CSurface::OnLoad(const char* File) {
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;
    
    if((Surf_Temp = IMG_Load(File)) == NULL) {
        return NULL;
    }
    
    Surf_Return = SDL_DisplayFormatAlpha(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);
    
    return Surf_Return;
}

bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }
    
    SDL_Rect DestR;
    
    DestR.x = X;
    DestR.y = Y;
    
    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);
    
    return true;
}

bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H) {
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }
    
    SDL_Rect DestR;
    
    DestR.x = X;
    DestR.y = Y;
    
    SDL_Rect SrcR;
    
    SrcR.x = X2;
    SrcR.y = Y2;
    SrcR.w = W;
    SrcR.h = H;
    
    SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);
    
    return true;
}
