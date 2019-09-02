//
//  LocationRefactoring.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 28/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef LocationRefactoring_hpp
#define LocationRefactoring_hpp

//#include "Constants.h"

class LocationRefactoring {
public:
    enum { LEFT_DOWN, LEFT_MID, LEFT_UP,
        RIGHT_DOWN, RIGHT_MID, RIGHT_UP
    };
    
protected:
    double x = 0, y = 0;
    int location = LEFT_DOWN;
    
public:
    double getXCoord() { return x; }
    double getYCoord() { return y; }
    
};

#endif /* LocationRefactoring_hpp */
