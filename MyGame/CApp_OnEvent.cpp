//
//  CApp_OnEvent.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

void CApp::OnEvent(SDL_Event* Event) {
    
    if(Event->type == SDL_KEYDOWN) {
        
        // keyboard delay after gameover
        if(GLOBAL::keyboardDelay) {
            printf("ticks = %d\n", GLOBAL::timer.get_ticks());
            if(GLOBAL::timer.get_ticks() > 2000)
                GLOBAL::keyboardDelay = false;
            else
                return;
        }
        
        if(GLOBAL::GameOver) {
            GLOBAL::GameOver = false;
            Score.score = 0;
            Burger.newGame();
        }
        
        switch(Event->key.keysym.sym) {
            
            case SDLK_q: Running = false; break;
               
            case SDLK_LCTRL:
            case SDLK_1: Hero.MoveLeftDown(); break;
            case SDLK_LALT:
            case SDLK_2: Hero.MoveLeftMid(); break;
            case SDLK_SPACE:
            case SDLK_3: Hero.MoveLeftUp(); break;
            case SDLK_LSHIFT:
            case SDLK_4: Hero.MoveRightDown(); break;
            case SDLK_z:
            case SDLK_5: Hero.MoveRightMid(); break;
            case SDLK_x:
            case SDLK_6: Hero.MoveRightUp(); break;
                
            default:;
        }
    }
    
    if(Event->type == SDL_QUIT) {
        Running = false;
    }
    
}
