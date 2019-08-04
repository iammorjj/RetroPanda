//
//  CApp_OnCleanup.cpp
//  SDL_Test1
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

void CApp::OnCleanup() {
    SDL_FreeSurface(Surf_Test);
    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}
