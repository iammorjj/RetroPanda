//
//  BurgerItem.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 02/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef BurgerItem_hpp
#define BurgerItem_hpp

#include "Location.hpp"

class BurgerItem: public Location {
private:
    int xDirectionSign();
public:
    BurgerItem(int location);
    
    static int xVel;
    static int yVel;
    
    static void resetVelocity();
    
    bool canMoveSideway();
    bool canMoveDown();
    void move(double deltaTicks);
    
    bool isGameOver();    
};

#endif /* BurgerItem_hpp */
