//
//  CApp.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

CApp::CApp() {
    display = NULL;

    running = true;
}

int CApp::execute() {
    if(init() == false) {
        return -1;
    }
    
    SDL_Event Event;
    
    while(running) {
        while(SDL_PollEvent(&Event)) {
            event(&Event);
        }
        
        loop();
        render();
    }
    
    cleanup();
    
    return 0;
}

void CApp::startNewGame() {
    
}
void CApp::gameOver() {
    
}

bool CApp::isNewLevel() {
    return true;
}
void CApp::newLevel() {
    
}
