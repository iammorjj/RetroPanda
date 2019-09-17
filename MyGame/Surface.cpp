//
//  Surface.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Surface.hpp"

SDL_Surface* Surface::load(const char* file) {
    SDL_Surface* sTemp = nullptr;
    SDL_Surface* sReturn = nullptr;
    
    sTemp = IMG_Load(file);
    if(!sTemp)
        return nullptr;
    
    sReturn = SDL_DisplayFormatAlpha(sTemp);
    SDL_FreeSurface(sTemp);
    
    return sReturn;
}

void Surface::draw(SDL_Surface* sDestination, SDL_Surface* sSource, int x, int y) {
    if(sDestination == nullptr || sSource == nullptr)
        return;
    
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    
    SDL_BlitSurface(sSource, nullptr, sDestination, &rect);
}

void Surface::draw(SDL_Surface* sDestination, SDL_Surface* sSource, int xDestination, int yDestination,
                   int xSource, int ySource, int width, int height) {
    if(sDestination == nullptr || sSource == nullptr)
        return;
    
    SDL_Rect destRect;
    destRect.x = xDestination;
    destRect.y = yDestination;
    
    SDL_Rect srcRect;
    srcRect.x = xSource;
    srcRect.y = ySource;
    srcRect.w = width;
    srcRect.h = height;
    
    SDL_BlitSurface(sSource, &srcRect, sDestination, &destRect);
}
