//
//  CConveyor.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CConveyor.hpp"

void CConveyor::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_Entity == NULL || Surf_Display == NULL) return;
    
    for(int i = 0; i < 3; ++i) {
        // LEFT CONVEYORS
        CSurface::OnDraw(Surf_Display, Surf_Entity, LEFT_SIDE_COORD,
                         TOP_COORD + i*VERTICAL_DISTANCE_BETWEEN_CONVEYORS,
                         Anim_Control.GetCurrentFrame() * Width, Height, Width, Height);
        
        // RIGHT CONVEYORS
        CSurface::OnDraw(Surf_Display, Surf_Entity, RIGHT_SIDE_COORD,
                         TOP_COORD + i*VERTICAL_DISTANCE_BETWEEN_CONVEYORS,
                         Anim_Control.GetCurrentFrame() * Width, 0, Width, Height);
    }
}
