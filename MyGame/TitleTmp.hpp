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

//class Title {
//private:
//    TTF_Font* font;
//    
//    SDL_Surface* sFront;
//    SDL_Surface* sShadow;
//    
//    const static SDL_Color whiteColor;
//    const static SDL_Color goldColor;
//    const static SDL_Color shadowColor;
//public:
//    bool load(int fontSize);
//};

#endif /* TitleTmp_hpp */
