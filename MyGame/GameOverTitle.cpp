//
//  GameOverTitle.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "GameOverTitle.hpp"
#include <string>
#include "Global.hpp"

using namespace Global;

namespace {
    const int bestScoreFontSize = 60;
    const int welcomeFontSize = 35;
    const int leaderFontSize = 30;
    
    const int leaderLines = 3;
    
    const std::string bestScoreText = "best score";
    const std::string welcomeText = "press f to pay for burger";
    const std::string leaderText[] =
    {"you're the leader now!", "make #billyssubs screen photo", "to take part in the daily draw!"};
    
    const int yBestScore = 90;
    const int yWelcome = 600;
    const int yLeader[] = {630, 650, 670};
}

void GameOverTitle::newGame() {
    bestScore.setFrontColor(whiteColor);
}
void GameOverTitle::gameOver() {
    bestScore.setFrontColor(goldColor);
}

inline bool GameOverTitle::loadLeader() {
    for(int i = 0; i < leaderLines; ++i)
        if(!leader[i].load(leaderFontSize))
            return false;
    
    return true;
}

bool GameOverTitle::load() {
    if(!bestScore.load(bestScoreFontSize) ||
       !welcome.load(welcomeFontSize) ||
       !loadLeader())
        return false;
    
    bestScore.setYCoordinate(yBestScore);
    welcome.setYCoordinate(yWelcome);
    for(int i = 0; i < leaderLines; ++i)
        leader[i].setYCoordinate(yLeader[i]);
    
    bestScore.setFrontColor(whiteColor);
    welcome.setFrontColor(whiteColor);
    for(int i = 0; i < leaderLines; ++i)
        leader[i].setFrontColor(goldColor);
    
    bestScore.setText(bestScoreText.c_str());
    welcome.setText(welcomeText.c_str());
    for(int i = 0; i < leaderLines; ++i)
        leader[i].setText(leaderText[i].c_str());
    
    return true;
}

void GameOverTitle::loop() {}

void GameOverTitle::render(SDL_Surface *display) {
    if(!isGameOver)
        return;
    
    bestScore.render(display);
    if(static_cast<void>(welcomeEffect.hide()), !welcomeEffect.isHide)
        welcome.render(display);
    if(isLeader)
        for(int i = 0; i < leaderLines; ++i)
            leader[i].render(display);
}

void GameOverTitle::cleanup() {
    bestScore.cleanup();
    welcome.cleanup();
    for(int i = 0; i < leaderLines; ++i)
        leader[i].cleanup();
}
