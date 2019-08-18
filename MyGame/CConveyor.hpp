//
//  CConveyor.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CConveyor_hpp
#define CConveyor_hpp

#include "CEntity.hpp"
#include <queue>

class CConveyor: public CEntity {
public:
    
    const int VERTICAL_DISTANCE_BETWEEN_CONVEYORS = 130;
    const int LEFT_SIDE_COORD = CONSTANTS::SCREEN1024X768::SCREEN_WIDTH / 2. - CONSTANTS::SCREEN1024X768::BACKGROUND_WIDTH / 2. - 60;
    const int RIGHT_SIDE_COORD = CONSTANTS::SCREEN1024X768::SCREEN_WIDTH / 2. + 90;
    const int TOP_COORD = 190;
    
    void OnRender(SDL_Surface* Surf_Display);
};

#endif /* CConveyor_hpp */
