//
//  CConveyorOldVersion.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CConveyor_hpp
#define CConveyor_hpp

#include "CEntityOldVersion.hpp"
#include <queue>

class CConveyorOldVersion: public CEntityOldVersion {
public:
    
    void OnRender(SDL_Surface* Surf_Display);
};

#endif /* CConveyor_hpp */
