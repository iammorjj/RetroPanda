//
//  BurgerItem.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 02/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef BurgerItem_hpp
#define BurgerItem_hpp

#include "LocationRefactoring.hpp"

class BurgerItem: public LocationRefactoring {
private:
    static double xVel;
    static double yVel;
private:
    int xDirectionSign();
public:
    BurgerItem(int location = LEFT_DOWN);
    
    bool canMoveSideway();
    bool canMoveDown();
    void move(double deltaTicks);
    
    bool isGameOver();
};

#endif /* BurgerItem_hpp */
