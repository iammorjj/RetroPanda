//
//  Score.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 11/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Score_hpp
#define Score_hpp

#include "Entity.hpp"
#include "Title.hpp"
#include "TitleTmp.hpp"

class Score : public Entity {
private:
    int bestScore;
    // offset is 16
    TitleTmp ttScore;
    
    char buf[5];
public:
    int score;
public:
    Score();
    
    void newGame();
    
    bool load();
    void loop();
    void render(SDL_Surface* display);
    void cleanup();
};

#endif /* Score_hpp */
