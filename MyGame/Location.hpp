//
//  Location.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 28/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Location_hpp
#define Location_hpp

class Location {
public:
    enum { LEFT_DOWN, LEFT_MID, LEFT_UP,
        RIGHT_DOWN, RIGHT_MID, RIGHT_UP
    };
    
protected:
    double x = 0, y = 0;
    int location = LEFT_DOWN;
    
public:
    double getXCoord() const { return x; }
    double getYCoord() const { return y; }
    
};

#endif /* Location_hpp */
