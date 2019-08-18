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
#include <list>

class CBurger: public CEntity {
private:
    Timer timer;
    Uint32 deltaTicks;
    
    int gameOverHidingBurgersRate;
    int oldTimeGameOver;
    bool gameOverHidding;
    
    Uint32 createNewBurgerDelay;
    SDL_TimerID createNewBurgerTimer;
    
    bool changeAppearanceSpeed;
    
public:
    std::list<Burger> burger[CONSTANTS::SCREEN1024X768::CONVEYORS_NUM];
    
    CBurger();

    void addBurgerToRandomConveyor();
    
    void gameOver();
    
    bool hasBurger(Location location);
    
    void newLevelMovementSpeed();
    void newLevelAppearanceSpeed();
    
    void StartMove();
    
    void newGame();
    
    void checkGameOverCollisions();
    
    void createBurgers();

    void printCoordinate() {
        for(int i = LEFT_DOWN; i <= RIGHT_UP; ++i) {
            for(auto &burg: burger[i])
                printf("X is %lf, Y is %lf\n", burg.x, burg.y);
        }
    }
    void moveLeft() {
        for(int i = LEFT_DOWN; i <= RIGHT_UP; ++i) {
            for(auto &burg: burger[i])
                burg.x -= 3;
        }
    }
    void moveRight() {
        for(int i = LEFT_DOWN; i <= RIGHT_UP; ++i) {
            for(auto &burg: burger[i])
                burg.x += 3;
        }
    }
    void moveUp() {
        for(int i = LEFT_DOWN; i <= RIGHT_UP; ++i) {
            for(auto &burg: burger[i])
                burg.y -= 3;
        }
    }
    void moveDown() {
        for(int i = LEFT_DOWN; i <= RIGHT_UP; ++i) {
            for(auto &burg: burger[i])
                burg.y += 3;
        }
    }
    
public:
    void OnLoop();
    
    void OnRender(SDL_Surface* Surf_Display);
};

#endif /* CBurger_hpp */
