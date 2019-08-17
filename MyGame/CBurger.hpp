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
#include "Timer.hpp"
#include <vector>

class CBurger: public CEntity {
private:
    
    double xVel, yVel;
    
    Uint32 deltaTicks;
    
    Timer timer;
    
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
    
    void gravity(double deltaTicks);

    void moveLeft(double deltaTicks);
    void moveRight(double deltaTicks);
    
    void moveUp(double deltaTicks);
    
    void moveDownLeftSide(double deltaTicks);
    void moveDownRightSide(double deltaTicks);
    void moveFromLeft(double deltaTicks);
    void moveFromRight(double deltaTicks);
    
    void setLevel(int l);
    
    void newLevelSpeedMovement();
    void newLevelSpeedAppearence();
    
    void StartMove();
    
    void newGame();
    
    void checkGameOverCollisions();
    
    //void changeMovementSpeed(SDL_TimerID& timer);
    
    void createBurgers();

    void printCoordinate(int xx, int yy);
    
public:
    void OnLoop();
    
    void OnRender(SDL_Surface* Surf_Display);
};

#endif /* CBurger_hpp */
