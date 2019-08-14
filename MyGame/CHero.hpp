//
//  CHero.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CHero_hpp
#define CHero_hpp

#include "CEntity.hpp"
#include "Location.h"

class CHero: public CEntity, public LocationClass {
public:
    Location location;
public:

    CHero();
    
    void OnRender(SDL_Surface* Surf_Display);
    
    void MoveLeftDown();
    void MoveLeftMid();
    void MoveLeftUp();
    void MoveRightDown();
    void MoveRightMid();
    void MoveRightUp();
    
};

#endif /* CHero_hpp */
