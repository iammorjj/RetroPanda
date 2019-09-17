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

namespace {
    const int fontSize = 200;
    
    const int yTitle = 80;
}

Score::Score() : bestScore(2), score(bestScore) {}

void Score::newGame() {
    score = 0;
    ttScore.setFrontColor(whiteColor);
}

bool Score::load() {
    if(!ttScore.load(fontSize))
        return false;
    
    ttScore.setYCoordinate(yTitle);
    ttScore.setFrontColor(whiteColor);
    
    return true;
}

void Score::render(SDL_Surface* display) {
    sprintf(buf, "%d", score);
    ttScore.setText(buf);

    if(isGameOver) {
        if(score > bestScore) {
            isLeader = true;
            bestScore = score;
            ttScore.setFrontColor(goldColor);
        }
        score = bestScore;
    } else
        isLeader = false;
    
    ttScore.render(display);
}

void Score::loop() {}
void Score::cleanup() {
    ttScore.cleanup();
}
