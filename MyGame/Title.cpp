//
//  Title.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Title.hpp"
#include <string>
#include "Global.hpp"
#include "Surface.hpp"

using namespace Global;

namespace {
    const std::string file = path+"acknowtt.ttf";
}

Title::Title() : font(nullptr), sFront(nullptr), sShadow(nullptr), xFront(scrWidth / 2), yFront(0), frontColor(whiteColor), offset(5) {}

bool Title::load(int fontSize) {
    return font = TTF_OpenFont(file.c_str(), fontSize);
}

void Title::setFrontColor(SDL_Color frontColor) {
    this->frontColor = frontColor;
}
void Title::setText(const char* text) {
    sFront = TTF_RenderText_Solid( font, text, frontColor );
    sShadow = TTF_RenderText_Solid( font, text, shadowColor );
}
void Title::setYCoordinate(int y) {
    yFront = y;
}

int Title::xCenterCalc() {
    return xFront - sFront->clip_rect.w / 2;
}

void Title::render(SDL_Surface* display) {
    Surface::draw(display, sShadow, xCenterCalc() + offset, yFront + offset);
    Surface::draw(display, sFront, xCenterCalc(), yFront);
}
void Title::cleanup() {
    if(sFront) SDL_FreeSurface(sFront);
    if(sShadow) SDL_FreeSurface(sShadow);
    if(font) TTF_CloseFont(font);
}
