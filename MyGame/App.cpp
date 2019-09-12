//
//  App.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "App.hpp"

App::App() : display(nullptr), running(true) {}

int App::execute() {
    if(init() == false)
        return -1;
    
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

void App::gameOver() {
    
}

bool App::isNewLevel() {
    return true;
}
void App::newLevel() {
    
}
