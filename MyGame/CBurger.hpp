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
    long long    oldTime;
    
    int gameOverHidingBurgersRate;
    int oldTimeGameOver;
    bool gameOverHidding;
    
    int frameRateGravity;
    long long oldTimeGravity;
    
    Uint32 createNewBurgerDelay;
    SDL_TimerID createNewBurgerTimer;
public:
    
    std::vector<Burger> burger[CONSTANTS::CONVEYORS_NUM];
    
    CBurger();

    void addBurgerToRandomConveyor() {
        
        Location location = (Location) (rand() % CONSTANTS::CONVEYORS_NUM);
        
        // debug
        //location = LEFT_UP;

        burger[location].push_back(Burger(location));
    }
    
    bool checkHide = false;
    
    void OnRender(SDL_Surface* Surf_Display) {
        for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location) {
            for(auto burg: burger[location]) {
                if(GLOBAL::GameOver)
                    gameOver();
                if(!gameOverHidding)
                    CSurface::OnDraw(Surf_Display, Surf_Entity, burg.x,
                                 burg.y,
                                 0, 0, Width, Height);
            }
        }
    }
    
    void gameOver() {
        if(oldTimeGameOver + this->gameOverHidingBurgersRate > SDL_GetTicks())
            return;
        
        oldTimeGameOver = SDL_GetTicks();
        gameOverHidding = !gameOverHidding;
    }
    
    bool hasBurger(Location location) {
        return !burger[location].empty();
    }
    
    void gravity() {
        for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location) {
            for(auto &burg: burger[location]) {
                if(!burg.canMoveSideway() && burg.canMoveDown())
                    burg.y += 2;
            }
        }
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
    
    void moveDownLeftSide() {
        
        for(int location = LEFT_DOWN; location <= LEFT_UP; ++location) {
            for(auto &burg: burger[location]) {
                if(burg.canMoveDown()) {
                    if(burg.canMoveSideway())
                        burg.y += 1;
                }
            }
        }
    }
    
    void moveDownRightSide() {
        
        for(int location = RIGHT_DOWN; location <= RIGHT_UP; ++location) {
            for(auto &burg: burger[location]) {
                if(burg.canMoveDown()) {
                    if(burg.canMoveSideway())
                        burg.y += 1;
                }
            }
        }
    }
    
    
    void setLevel(int l) { level = l; }
    
    void moveFromLeft() { moveRight(); moveDownLeftSide(); }
    void moveFromRight() { moveLeft(); moveDownRightSide(); }
    
    
    void StartMove() {
        
        if(oldTime + this->frameRate < SDL_GetTicks()) {
            oldTime = SDL_GetTicks();
            
            //printf("oldTime %lld\n", oldTime);
            
            moveFromLeft();
            moveFromRight();
        }
        
        if(oldTimeGravity + this->frameRateGravity < SDL_GetTicks()) {
            oldTimeGravity = SDL_GetTicks();
            
            //printf("oldTimeGravity %lld\n", oldTimeGravity);
            
            gravity();
        }
        
    }
    
    void newGame() {
        gameOverHidding = false;
        for(int location = LEFT_DOWN; location <= RIGHT_UP; ++location)
            burger[location].clear();
    }
    
    void checkGameOverCollisions() {
        for(auto burger: burger) {
            if(burger.empty())
                continue;

            auto burg = burger.back();
            if(burg.isGameOver())
                GLOBAL::GameOver = true;
        }
    }
    
    void createBurgers(CBurger* Burger);

    void printCoordinate(int xx, int yy) { printf("X coordinate is %d\nY coordinate is %d\n", xx, yy); }
    
    void OnLoop() {
        if(!GLOBAL::GameOver) {
            createBurgers(this);
            StartMove();
        }
    }
};

#endif /* CBurger_hpp */
