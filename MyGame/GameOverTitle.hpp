//
//  GameOverTitle.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef GameOverTitle_hpp
#define GameOverTitle_hpp

#include "HideEffect.h"
#include "Entity.hpp"
#include "Title.hpp"

class GameOverTitle : public Entity {
    Title bestScore;
    Title welcome;
    Title leader[3];
    
    bool loadLeader(); 
    
    HideEffect welcomeEffect;
public:
    void newGame();
    void gameOver();
    
    bool load();
    void loop();
    void render(SDL_Surface* display);
    void cleanup();
};

#endif /* GameOverTitle_hpp */
