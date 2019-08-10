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
#include "Burger.hpp"
#include <vector>

class CBurger: public CEntity {
private:
    int     level;
    int     frameRate; //Milliseconds
    long    oldTime;
    
public:
    
    std::vector<Burger> burger[CONSTANTS::CONVEYORS_NUM];
    
    CBurger();
    
    void addBurgerToRandomConveyor() {
        
        Location location = (Location) (rand() % CONSTANTS::CONVEYORS_NUM);
        
        // debug
        //location = LEFT_UP;

        burger[location].push_back(Burger(location));
    }
    
    void OnRender(SDL_Surface* Surf_Display) {
        for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location) {
            for(auto burg: burger[location]) {
                CSurface::OnDraw(Surf_Display, Surf_Entity, burg.x,
                                 burg.y,
                                 0, 0, Width, Height);
            }
        }
    }
    
    bool hasBurger(Location location) {
        return !burger[location].empty();
    }
    
    void moveLeft() {
        
        for(int location = RIGHT_DOWN; location <= RIGHT_UP; ++location) {
            for(auto &burg: burger[location]) {
                if(burg.canMoveSideway())
                    burg.x -= 2;
            }
        }
    }
    
    void moveRight() {
        
        for(int location = LEFT_DOWN; location <= LEFT_UP; ++location) {
            for(auto &burg: burger[location]) {
                if(burg.canMoveSideway())
                    burg.x += 2;
            }
        }
    }
    
    void moveUp() {
        
        for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location) {
            for(auto &burg: burger[location]) {
                if(burg.y > CONSTANTS::BURGER::STOP_BURGER_Y_UP)
                    burg.y -= 1;
            }
        }
    }
    
    void moveDown() {
        
        for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location) {
            for(auto &burg: burger[location]) {
                if(burg.canMoveDown())
                    burg.y += 1;
            }
        }
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
        
        checkCollisions();
    }
    
    void checkCollisions() {
//        for(auto &conv: conveyor) {
//            if(conv.burger.empty())
//                continue;
//
//            auto burger = conv.burger.back();
//            if(burger.isGameOver()) {
//                level = 0;
//            } else if(burger.isTakenByHero()) {
//                conv.burger.pop_back();
//            }
//        }
    }

    void printCoordinate(int xx, int yy) { printf("X coordinate is %d\nY coordinate is %d\n", xx, yy); }
    
    void OnLoop() {
        if(level > 0)
            StartMove();
    }
};

#endif /* CBurger_hpp */
