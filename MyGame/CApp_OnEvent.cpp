//
//  CApp_OnEvent.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

bool isNewGame() { return GLOBAL::GameOver; }
bool isWaitingTimePassed();
bool isQuitGame(SDL_Event* Event);

//#include "LocationRefactoring.hpp"

void CApp::OnEvent(SDL_Event* Event) {
    
    if(isQuitGame(Event)) {
        Running = false;
        //LocationRefactoring::RIGHT_UP;
        return;
    }
    
    if(Event->type == SDL_KEYDOWN) {
        
        if(isNewGame()) {
            if(isWaitingTimePassed())
                startNewGame();
            else
                return;
        }
        
        // TODO: make sensible names for arcade machine
        switch(Event->key.keysym.sym) {
            case SDLK_LCTRL:
            case SDLK_v:
                Hero.MoveLeftDown();
                HeroRefactoring.changeLocation(LEFT_DOWN);
                break;
            case SDLK_LALT:
            case SDLK_f:
                Hero.MoveLeftMid();
                HeroRefactoring.changeLocation(LEFT_MID);
                break;
            case SDLK_SPACE:
            case SDLK_r:
                Hero.MoveLeftUp();
                HeroRefactoring.changeLocation(LEFT_UP);
                break;
            case SDLK_LSHIFT:
            case SDLK_n:
                Hero.MoveRightDown();
                HeroRefactoring.changeLocation(RIGHT_DOWN);
                break;
            case SDLK_z:
            case SDLK_j:
                Hero.MoveRightMid();
                HeroRefactoring.changeLocation(RIGHT_MID);
                break;
            case SDLK_x:
            case SDLK_i:
                Hero.MoveRightUp();
                HeroRefactoring.changeLocation(RIGHT_UP);
                break;
                
            default:;
        }
    }
}

bool isQuitGame(SDL_Event* Event) {
    return Event->type == SDL_QUIT ||
        Event->key.keysym.sym == SDLK_q;
}

void CApp::startNewGame() {
    GLOBAL::GameOver = false;
    Score.score = 0;
    Burger.newGame();
}

bool isWaitingTimePassed() {
    if(GLOBAL::keyboardDelay) {
        if(GLOBAL::timer.get_ticks() > 2000) {
            GLOBAL::keyboardDelay = false;
            return true;
        }
        
        return false;
    }
    
    return true;
}
