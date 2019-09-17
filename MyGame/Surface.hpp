//
//  Surface.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <SDL/SDL.h>

#ifndef MAC
#include <SDL/SDL_image.h>
#else
#include <SDL_image/SDL_image.h>
#endif

class Surface {
public:
    static SDL_Surface* load(const char* file);
    
    static void draw(SDL_Surface* destination, SDL_Surface* source, int x, int y);
    static void draw(SDL_Surface* destination, SDL_Surface* source, int xDestination, int yDestination,
                     int XSource, int ySource, int width, int height);
};

#endif /* Surface_hpp */
