//
//  burger.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 03/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "burger.h"

#include "burger_constants.h"
#include "global.h"
#include "surface.h"

Burger::Burger()
    : surface_(nullptr),
      is_running_(false),
      burger_line_(std::vector<std::list<BurgerItem>>(global::kLineAmount)),
      creator_(this) {}

void Burger::Move() {
  int delta_ticks = move_timer_.GetTicks();
  for (auto &line: burger_line_) {
    for (auto &burger: line)
      burger.Move(delta_ticks);
  }
  
  move_timer_.Start();
}

void Burger::DrawBurgers(SDL_Surface* display) {
  for (auto line: burger_line_) {
    for (auto burger: line)
      Surface::Draw(display, surface_, burger.x(), burger.y());
  }
}

bool Burger::IsMissed() {
  for (auto line: burger_line_) {
    if (!line.empty()) {
      auto burger = line.back();
      if (!burger.CanMoveDown())
        return true;
      }
  }
  
  return false;
}

bool Burger::CanBeCaught(int location) const {
  if (burger_line_[location].empty())
    return false;
  
  return burger_line_[location].back().x() >
         burger_constants::kXCanBeCaughtLeft &&
         burger_line_[location].back().x() <
         burger_constants::kXCanBeCaughtRight;
}

void Burger::NewGame() {
  CleanBurgers();
  
  BurgerItem::ResetVelocity();
  creator_.ResetDelay();
  creator_.Start();
  
  move_timer_.Start();
  is_running_ = true;
}

void Burger::GameOver() {
  creator_.Stop();
  move_timer_.Stop();
  is_running_ = false;
}

void Burger::CleanBurgers() {
  for (auto& line: burger_line_)
    line.clear();
}

void Burger::MovementSpeedNewLevel() {
  BurgerItem::x_vel_ += burger_constants::kXVelNewLevel;
  BurgerItem::y_vel_ += burger_constants::kYVelNewLevel;
}

void Burger::AppearanceSpeedNewLevel() {
  creator_.ChangeDelay();
}

bool Burger::Load() {
  surface_ = Surface::Load(burger_constants::kFile);
  if (!surface_)
    return false;
  
  return true;
}

void Burger::Loop() {
  if (is_running_)
    Move();
}

void Burger::Render(SDL_Surface* display) {
  if (is_running_ || (static_cast<void>(effect_.Hide()), !effect_.is_hide_))
    DrawBurgers(display);
}

void Burger::Cleanup() {
  CleanBurgers();
  SDL_FreeSurface(surface_);
}
