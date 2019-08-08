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
#include "Conveyor.hpp"
#include <vector>

class CBurger: public CEntity {
    
private:
    int     level;
    
    int     frameRate; //Milliseconds
    
    long    oldTime;
    
private:
    std::vector<Conveyor> conveyor;
    
public:
    
    CBurger();
    
    void addBurgerToRandomConveyor() {
        
        LOCATION location = (LOCATION) (rand() % CONSTANTS::CONVEYORS_NUM);
        
        // debug
        location = RIGHT_UP;
        
        conveyor[location].addBurger();
        
    }
    
    void OnRender(SDL_Surface* Surf_Display) {
        if(Surf_Entity == NULL || Surf_Display == NULL) return;
        
        for(auto conv: conveyor) {
            for(auto burg: conv.burger) {
                CSurface::OnDraw(Surf_Display, Surf_Entity, burg.coord.x,
                                 burg.coord.y,
                                 0, 0, Width, Height);
            }
        }
    }
    
    void moveLeft() {
        for(auto &conv: conveyor)
            for(auto &burg: conv.burger)
                burg.coord.x -= 2;
    }
    
    void moveRight() {
        for(auto &conv: conveyor)
            for(auto &burg: conv.burger)
                burg.coord.x += 2;
    }
    
    void moveUp() {
        for(auto &conv: conveyor)
            for(auto &burg: conv.burger)
                burg.coord.y -= 1;
        
        addBurgerToRandomConveyor();
    }
    
    void moveDown() {
        for(auto &conv: conveyor)
            for(auto &burg: conv.burger)
                burg.coord.y += 1;
    }
    
    void SetUpLevel1() { level = 1; }
    
    void setLevel(int l) { level = l; }
    
    void StartMove() {
        
        if(oldTime + this->frameRate > SDL_GetTicks())
            return;

        oldTime = SDL_GetTicks();
        
        //moveFromLeftSide();
        moveFromRightSide();
    }
    
    void moveFromLeftSide() { moveRight(); moveDown(); }
    void moveFromRightSide() { moveLeft(); moveDown(); }
    
    void printCoordinate() { printf("X coordinate is %f\nY coordinate is %f\n", X, Y); }
    
    void OnLoop() {
        if(level > 0)
            StartMove();
    }
};

#endif /* CBurger_hpp */
