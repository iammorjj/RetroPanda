//
//  Timer.hpp
//  MyGame
//
//  Created by Alexander Mordovsky on 30/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

class Timer {
private:
    int startTicks;
    int pausedTicks;
    
    bool paused;
    bool started;
public:
    Timer();
    
    void start();
    void stop();
    
    int getTicks();
};

#endif /* Timer_hpp */
