//
//  TitleTmp.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "TitleTmp.hpp"
#include <string>
#include "Global.hpp"
#include "Surface.hpp"

using namespace Global;

namespace {
    const std::string file = path+"acknowtt.ttf";
}

bool TitleTmp::load(int fontSize) {
    xFront = scrWidth / 2;
    offset = 5; // make calc depending fontSize
    return font = TTF_OpenFont(file.c_str(), fontSize);
}

void TitleTmp::setFrontColor(SDL_Color frontColor) {
    this->frontColor = frontColor;
}
void TitleTmp::setText(const char* text) {
    sFront = TTF_RenderText_Solid( font, text, frontColor );
    sShadow = TTF_RenderText_Solid( font, text, shadowColor );
}
void TitleTmp::setYCoordinate(int y) {
    yFront = y;
}

int TitleTmp::xCenterCalc() {
    return xFront - sFront->clip_rect.w / 2;
}

void TitleTmp::render(SDL_Surface* display) {
    Surface::draw(display, sShadow, xCenterCalc() + offset, yFront + offset);
    Surface::draw(display, sFront, xCenterCalc(), yFront);
}
void TitleTmp::cleanup() {
    if(sFront) SDL_FreeSurface(sFront);
    if(sShadow) SDL_FreeSurface(sShadow);
    // bad, very bad
    if(font) TTF_CloseFont(font);
}
