//
//  timer.h
//  MyGame
//
//  Created by Alexander Mordovsky on 30/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_TIMER_H_
#define MY_GAME_TIMER_H_

class Timer {
 public:
  Timer();
  
  void Start();
  void Stop();
  
  int GetTicks();
  
 private:
  int start_ticks_;
  int paused_ticks_;
  
  bool is_paused_;
  bool is_started_;
};

#endif  // MY_GAME_TIMER_H_
