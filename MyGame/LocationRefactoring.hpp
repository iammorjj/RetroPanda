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
    
private:
    double x = 0, y = 0;
    int location = LEFT_DOWN;
    
};

#endif /* LocationRefactoring_hpp */
