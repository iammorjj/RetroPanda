//
//  CApp.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

CApp::CApp() {
    Surf_Display = NULL;

    Running = true;
}

int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }
    
    SDL_Event Event;
    
    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
        
        OnLoop();
        OnRender();
    }
    
    OnCleanup();
    
    return 0;
}
