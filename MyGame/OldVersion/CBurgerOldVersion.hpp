//
//  CBurgerOldVersion.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 07/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef CBurger_hpp
#define CBurger_hpp

#include "CEntityOldVersion.hpp"
#include "BurgerOldVersion.hpp"
#include "Timer.hpp"
#include <vector>
#include <list>

class CBurgerOldVersion: public CEntityOldVersion {
private:
    Timer timer;
    Uint32 deltaTicks;
    
    int gameOverHidingBurgersRate;
    int oldTimeGameOver;
    bool isHide;
    
    Uint32 createNewBurgerDelay;
    SDL_TimerID createNewBurgerTimer;
    
    bool changeAppearanceSpeed;
    
public:
    std::list<BurgerOldVersion> burger[CONSTANTS::CONVEYORS_NUM];
    
    CBurgerOldVersion();

    void addBurgerToRandomConveyor();
    
    void gameOver();
    
    bool hasBurger(LocationOldVersion location);
    
    void newLevelMovementSpeed();
    void newLevelAppearanceSpeed();
    
    void StartMove();
    
    void newGame();
    
    bool isGameOverCollisions();
    
    void createBurgers();
public:
    void OnLoop();
    
    void OnRender(SDL_Surface* Surf_Display);
};

#endif /* CBurger_hpp */
