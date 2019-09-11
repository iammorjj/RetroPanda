//
//  Score.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 11/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Score.hpp"
#include <string>
#include "Constants.h"

using namespace CONSTANTS;

namespace {
    const std::string file = PATH+"acknowtt.ttf";
    const int size = 200;
}

Score::Score() : bestScore(2), score(bestScore) {}

bool Score::load() {
    if(!TTF_WasInit() && TTF_Init() < 0)
        return false;
    
    return tScore.OnLoadFont(TTF_OpenFont(file.c_str(), size));
}

void Score::render(SDL_Surface* display) {
    sprintf(buf, "%d", score);
    
    tScore.changeTitle(buf);
    tScore.OnRender();
    
    if(GLOBAL::GameOver) {
        if(score > bestScore) {
            GLOBAL::isLeader = true;
            bestScore = score;
        }
        score = bestScore;
    } else {
        GLOBAL::isLeader = false;
    }
    
    tScore.OnDraw(display, SCREEN_WIDTH / 2 - tScore.sFront->clip_rect.w / 2, 80, 16);
}

void Score::loop() {}
void Score::cleanup() {}
