//
//  App_event.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "App.hpp"
#include "Global.hpp"

using namespace Global;

inline bool isKeyboardDelayFinished() {
    return tKeyboardDelay.getTicks() > keyboardDelay || isFirstGame;
}

inline bool isQuitGame(SDL_Event* event) {
    return event->type == SDL_QUIT ||
        event->key.keysym.sym == SDLK_q;
}

void App::eventHandler(SDL_Event* event) {
    
    if(isQuitGame(event)) {
        running = false;
        return;
    }
    
    if(event->type == SDL_KEYDOWN) {
        
        if(Global::isGameOver) {
            if(isKeyboardDelayFinished())
                newGame();
            else
                return;
        }
        
        switch(event->key.keysym.sym) {
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
