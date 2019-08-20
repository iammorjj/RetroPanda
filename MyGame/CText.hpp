//
//  CText.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 20/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CText_hpp
#define CText_hpp

#ifndef MAC
#include <SDL/SDL_ttf.h>
#else
#include <SDL_ttf/SDL_ttf.h>
#endif

class CText {
private:
    static const SDL_Color textColorWhite;
    static const SDL_Color textColorBlack;
    
    TTF_Font*    font;
    SDL_Surface*    Surf_Text_White;
    SDL_Surface*    Surf_Text_Black;

public:
    CText();
    
};

#endif /* CText_hpp */
