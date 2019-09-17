//
//  Background.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 10/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Background.hpp"
#include "Surface.hpp"
#include <string>
#include "Global.hpp"

using namespace Global;

namespace {
    const std::string file = path+"background.png";
    
    const int backgroundWidth = 461;
    
    const int x = scrWidth / 2 - backgroundWidth / 2;
    const int y = 0;
}

Background::Background() : surface(nullptr) {}

bool Background::load() {
    surface = Surface::load(file.c_str());
    
    return surface != nullptr;
}

void Background::loop() {}

void Background::render(SDL_Surface* display) {
    Surface::draw(display, surface, x, y);
}

void Background::cleanup() {
    SDL_FreeSurface(surface);
}
