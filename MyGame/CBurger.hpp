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

    void addBurgerToRandomConveyor();
    
    void gameOver();
    
    bool hasBurger(Location location);
    
    void gravity();

    void moveLeft();
    void moveRight();
    
    void moveUp();
    
    void moveDownLeftSide();
    void moveDownRightSide();
    void moveFromLeft();
    void moveFromRight();
    
    void setLevel(int l);
    
    void StartMove();
    
    void newGame();
    
    void checkGameOverCollisions();
    
    void changeMovementSpeed(SDL_TimerID& timer);
    
    void createBurgers();

    void printCoordinate(int xx, int yy);
    
public:
    void OnLoop();
    
    void OnRender(SDL_Surface* Surf_Display);
};

#endif /* CBurger_hpp */
