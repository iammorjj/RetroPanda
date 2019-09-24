//
//  burger_creator.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 13/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "burger_creator.h"

#include "burger.h"
#include "global.h"

namespace {
const int kStartDelayMs = 3000;
const int kMinDelayMs = 700;
const int kDelayDecrementMs = 300;
}  // namespace

BurgerCreator::BurgerCreator(Burger* burger)
    : timer_(nullptr),
      delay_(kStartDelayMs),
      is_delay_changed_(false),
      burger_(burger) {
  srand(static_cast<unsigned>(time(0)));
}

void BurgerCreator::CreateBurger() {
  int location = rand() % global::kLineAmount;
  burger_->burger_line_[location].push_front(BurgerItem(location));

  if (is_delay_changed_)
    RestartTimer();
}

void BurgerCreator::ResetDelay() {
  is_delay_changed_ = false;
  delay_ = kStartDelayMs;
}

void BurgerCreator::Start() {
  timer_ = SDL_AddTimer(delay_, [](Uint32 interval, void* param) -> Uint32 {
    BurgerCreator* creator = static_cast<BurgerCreator*>param;
    creator->CreateBurger();

    return interval;
  }, this);
}

void BurgerCreator::Stop() {
  is_delay_changed_ = false;
  if (timer_)
    SDL_RemoveTimer(timer_);
}

void BurgerCreator::RestartTimer() {
  Stop();
  Start();
}

void BurgerCreator::ChangeDelay() {
  if (delay_ > kMinDelayMs)
    delay_ -= kDelayDecrementMs;

  is_delay_changed_ = true;
}
