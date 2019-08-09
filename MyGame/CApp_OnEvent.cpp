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
        
        if(GameOver) {
            GameOver = false;
            StartGame();
        }
        
        switch(Event->key.keysym.sym) {
                
            case SDLK_1: Hero.MoveLeftDown(); break;
            case SDLK_2: Hero.MoveLeftMid(); break;
            case SDLK_3: Hero.MoveLeftUp(); break;
            case SDLK_4: Hero.MoveRightDown(); break;
            case SDLK_5: Hero.MoveRightMid(); break;
            case SDLK_6: Hero.MoveRightUp(); break;
                
            case SDLK_a: Burger.addBurgerToRandomConveyor(); break;
                
            case SDLK_9: Burger.setLevel(0); break;
            case SDLK_0: Burger.printCoordinate(); break;
                
            case SDLK_LEFT: Burger.moveLeft(); break;
            case SDLK_RIGHT: Burger.moveRight(); break;
            case SDLK_UP: Burger.moveUp(); break;
            case SDLK_DOWN: Burger.moveDown(); break;
                
            default:;
        }
    }
    
    if(Event->type == SDL_QUIT) {
        Running = false;
    }
    
}
