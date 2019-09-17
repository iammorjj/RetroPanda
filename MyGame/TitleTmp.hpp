//
//  TitleTmp.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef TitleTmp_hpp
#define TitleTmp_hpp

#include "SDL/SDL.h"
#ifndef MAC
#include <SDL/SDL_ttf.h>
#else
#include <SDL_ttf/SDL_ttf.h>
#endif

#include <string>

class TitleTmp {
private:
    TTF_Font* font;
    
    SDL_Surface* sFront;
    SDL_Surface* sShadow;
    
    int xFront, yFront;
    int xShadow, yShadow;
    
    SDL_Color frontColor;
    
    int offset;
    inline int xCenterCalc();
public:
    void setText(const char* text);
    void setFrontColor(SDL_Color frontColor);
    void setYCoordinate(int y);
    
    bool load(int fontSize);
    void render(SDL_Surface* display);
    void cleanup();
};

#endif /* TitleTmp_hpp */
