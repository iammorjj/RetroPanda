//
//  CApp_OnRender.cpp
//  SDL_Test1
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

void CApp::OnRender() {
    CSurface::OnDraw(Surf_Display, Surf_Test, 0, 0);
    CSurface::OnDraw(Surf_Display, Surf_Test, 100, 100, 0, 0, 50, 50);
    
    SDL_Flip(Surf_Display);
}
