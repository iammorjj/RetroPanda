//
//  surface.h
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_SURFACE_H_
#define MY_GAME_SURFACE_H_

#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>

class Surface {
 public:
  static SDL_Surface* Load(const char* const file);
  
  static void Draw(SDL_Surface* destination, SDL_Surface* source,
                   int x, int y);
  static void Draw(SDL_Surface* destination, SDL_Surface* source,
                   int x_destination, int y_destination,
                   int x_source, int y_source, int width, int height);
};

#endif  // MY_GAME_SURFACE_H_
