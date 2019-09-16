//
//  Score.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 11/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "Score.hpp"
#include <string>
#include "Global.hpp"

using namespace Global;

bool isLeader = false;

namespace {
    const std::string file = path+"acknowtt.ttf";
    const int fontSize = 200;
}

Score::Score() : bestScore(2), score(bestScore) {}

bool Score::load() {
    if(!TTF_WasInit() && TTF_Init() < 0)
        return false;
    
    return tScore.OnLoadFont(TTF_OpenFont(file.c_str(), fontSize));
}

void Score::render(SDL_Surface* display) {
    sprintf(buf, "%d", score);
    
    tScore.changeTitle(buf);
    tScore.OnRender();
    
    if(GLOBAL::GameOver) {
        if(score > bestScore) {
            isLeader = true;
            bestScore = score;
        }
        score = bestScore;
    } else
        isLeader = false;
    
    tScore.OnDraw(display, scrWidth / 2 - tScore.sFront->clip_rect.w / 2, 80, 16);
}

void Score::loop() {}
void Score::cleanup() {}
