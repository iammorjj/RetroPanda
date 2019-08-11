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
    Surf_Background = NULL;
    
    score = 0;
    
    font = NULL;
    Surf_Score_Black = Surf_Score_White = NULL;
    textColorWhite = { 255, 255, 255 };
    textColorBlack = { 0, 0, 0 };
    
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
