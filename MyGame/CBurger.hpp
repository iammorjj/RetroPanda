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
        
        Location location = (Location) (rand() % CONSTANTS::CONVEYORS_NUM);
        
        // debug
        //location = LEFT_UP;
        
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
            if(conv.isRightSide())
                for(auto &burg: conv.burger)
                    if(burg.canMoveSideway())
                        burg.coord.x -= 2;
    }
    
    void moveRight() {
        for(auto &conv: conveyor)
            if(conv.isLeftSide())
                for(auto &burg: conv.burger)
                    if(burg.canMoveSideway())
                        burg.coord.x += 2;
    }
    
    void moveUp() {
        for(auto &conv: conveyor)
            for(auto &burg: conv.burger) {
                if(burg.coord.y > CONSTANTS::BURGER::STOP_BURGER_Y_UP)
                burg.coord.y -= 1;
            }
    }
    
    void moveDown() {
        for(auto &conv: conveyor)
            for(auto &burg: conv.burger)
                if(burg.canMoveDown())
                    burg.coord.y += 1;
    }
    
    void SetUpLevel1() { level = 1; }
    
    void setLevel(int l) { level = l; }
    
    
    
    void StartMove() {
        if(oldTime + this->frameRate > SDL_GetTicks())
            return;

        oldTime = SDL_GetTicks();
        
        moveRight();
        moveLeft();
        moveDown();
    }

    void printCoordinate(int xx, int yy) { printf("X coordinate is %d\nY coordinate is %d\n", xx, yy); }
    
    void OnLoop() {
        if(level > 0)
            StartMove();
    }
};

#endif /* CBurger_hpp */
