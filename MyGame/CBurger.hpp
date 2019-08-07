//
//  CBurger.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 07/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CBurger_hpp
#define CBurger_hpp

#include "CEntity.hpp"

class CBurger: public CEntity {
public:
    
    const int VERTICAL_DISTANCE_BETWEEN_BURGERS = 80;
    const int LEFT_SIDE_COORD = 40;
    const int RIGHT_SIDE_COORD = Constants::SCREEN_WIDTH - Constants::BURGER_WIDTH + 12;
    const int TOP_COORD = 120;
    
    void OnRender(SDL_Surface* Surf_Display) {
        if(Surf_Entity == NULL || Surf_Display == NULL) return;

        CSurface::OnDraw(Surf_Display, Surf_Entity, LEFT_SIDE_COORD + X,
                         TOP_COORD,
                         0, 0, Width, Height);
    }
    
    void moveLeft() { X -= 2; }
    void moveRight() { X += 2; }
};

#endif /* CBurger_hpp */
