//
//  CApp_OnEvent.cpp
//  SDL_Test1
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

void CApp::OnEvent(SDL_Event* Event) {
    if(Event->type == SDL_QUIT || Event->type == SDL_KEYDOWN) {
        Running = false;
    }
}
