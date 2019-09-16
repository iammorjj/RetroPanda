//
//  Title.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 21/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Title_hpp
#define Title_hpp

#include "SDL/SDL.h"
#ifndef MAC
#include <SDL/SDL_ttf.h>
#else
#include <SDL_ttf/SDL_ttf.h>
#endif

#include "Surface.hpp"

struct Title {
private:
    char*       title;
    
    SDL_Color   frontColor = whiteColor;
    TTF_Font*   font;
    
    bool isLoad() {
        return ( sFront = TTF_RenderText_Solid( font, title, frontColor) ) &&
        ( sShadow = TTF_RenderText_Solid( font, title, shadowColor) );
    }
    
    bool isRender() {
        return ( sFront = TTF_RenderText_Solid( font, title, frontColor) ) &&
        ( sShadow = TTF_RenderText_Solid( font, title, shadowColor) );
    }
    
public:
    SDL_Surface* sFront;
    SDL_Surface* sShadow;
    
    const static SDL_Color whiteColor;
    const static SDL_Color goldColor;
    const static SDL_Color shadowColor;
    
public:
    bool OnLoadFont(TTF_Font* font) {
        this->font = font;
        
        return this->font != nullptr;
    }
    
    void changeColor(const SDL_Color& frontColor) {
        this->frontColor = frontColor;
        isRender();
    }
    
    bool OnLoad(TTF_Font* font, const SDL_Color& frontColor = whiteColor, char* title = "") {
        if(!font)
            return false;
        
        this->title = title;
        this->font = font;
        this->frontColor = frontColor;
        return isLoad();
    }
    
    bool OnLoad(SDL_Color& frontColor) {
        this->frontColor = frontColor;
        return isLoad();
    }
    
    void changeTitle(char* title) {
        this->title = title;
        //isRender();
    }
    
    void OnRender() {
        isLoad();
    }
    
    void OnDraw(SDL_Surface* Surf_Display, int x, int y, int k) {
        Surface::draw(Surf_Display, sShadow, x+k, y+k);
        Surface::draw(Surf_Display, sFront, x, y);
    }
    
    ~Title() {
        //if(sFront) SDL_FreeSurface(sFront);
        //if(sShadow) SDL_FreeSurface(sShadow);
        // bad, very bad
        //if(font) TTF_CloseFont(font);
    }
};

#endif /* Title_hpp */
