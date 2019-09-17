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

class Score : public Entity {
private:
    int score;
    int bestScore;
    Title tScore;
    
    char buf[5];
private:
    void writeBestScore();
public:
    Score();
    
    void newGame();
    
    void incrScore();
    int getScore();
    
    bool load();
    void loop();
    void render(SDL_Surface* display);
    void cleanup();
};

#endif /* Score_hpp */
