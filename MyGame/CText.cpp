//
//  CText.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 20/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CText.hpp"

const SDL_Color CText::textColorBlack = {0, 0, 0};
const SDL_Color CText::textColorWhite = {255, 255, 255};

CText::CText() {
    if(TTF_Init() < 0 || (font = TTF_OpenFont("sf", 32)) == NULL) {}
    font = TTF_OpenFont("sf", 52);
}
