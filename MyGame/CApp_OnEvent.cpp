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

///#include "Location.hpp"

void CApp::event(SDL_Event* Event) {
    
    if(isQuitGame(Event)) {
        running = false;
        //Location::RIGHT_UP;
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
                hero.changeLocation(Location::LEFT_DOWN);
                break;
            case SDLK_LALT:
            case SDLK_f:
                hero.changeLocation(Location::LEFT_MID);
                break;
            case SDLK_SPACE:
            case SDLK_r:
                hero.changeLocation(Location::LEFT_UP);
                break;
            case SDLK_LSHIFT:
            case SDLK_n:
                hero.changeLocation(Location::RIGHT_DOWN);
                break;
            case SDLK_z:
            case SDLK_j:
                hero.changeLocation(Location::RIGHT_MID);
                break;
            case SDLK_x:
            case SDLK_i:
                hero.changeLocation(Location::RIGHT_UP);
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
    score.score = 0;
    burger.newGame();
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
