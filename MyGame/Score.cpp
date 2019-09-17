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
#include <fstream>

using namespace Global;

namespace {
    const std::string file = path+"bestScore.txt";
    std::ifstream ifScore;
    std::ofstream ofScore;
    
    const int fontSize = 200;
    
    const int yTitle = 80;
}

Score::Score() : bestScore(0), score(0) {
    ifScore.open(file);
    if(ifScore.is_open())
        ifScore >> bestScore;
    score = bestScore;
    ifScore.close();
}

void Score::newGame() {
    score = 0;
    tScore.setFrontColor(whiteColor);
}

void Score::incrScore() {
    score++;
}
int Score::getScore() {
    return score;
}

void Score::writeBestScore() {
    bestScore = score;
    ofScore.open(file);
    ofScore << bestScore;
    ofScore.close();
}

bool Score::load() {
    if(!tScore.load(fontSize))
        return false;
    
    tScore.setYCoordinate(yTitle);
    tScore.setFrontColor(whiteColor);
    
    return true;
}

void Score::render(SDL_Surface* display) {
    sprintf(buf, "%d", score);
    tScore.setText(buf);

    if(isGameOver) {
        if(score > bestScore) {
            isLeader = true;
            writeBestScore();
            tScore.setFrontColor(goldColor);
        }
        score = bestScore;
    } else
        isLeader = false;
    
    tScore.render(display);
}

void Score::loop() {}

void Score::cleanup() {
    tScore.cleanup();
}
