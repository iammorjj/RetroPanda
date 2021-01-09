//
//  burger.h
//  MyGame
//
//  Created by Alexander Mordovsky on 28/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_BURGER_H_
#define MY_GAME_BURGER_H_

#include <list>
#include <vector>

#include "SDL.h"

#include "burger_creator.h"
#include "burger_item.h"
#include "entity.h"
#include "global.h"
#include "hide_effect.h"
#include "timer.h"

class Burger : public Entity {
public:
  Burger();

  bool IsMissed();

  bool CanBeCaught(int location) const;
  inline void DeleteBurger(int location) { burger_line_[location].pop_back(); }

  void NewGame();
  void GameOver();

  void CleanBurgers();

  void MovementSpeedNewLevel();
  void AppearanceSpeedNewLevel();

  bool Load();
  void Loop();
  void Render(SDL_Surface *display);
  void Cleanup();

private:
  SDL_Surface *surface_;

  bool is_running_;

  std::vector<std::list<BurgerItem>> burger_line_;

  BurgerCreator creator_;

  HideEffect effect_;

  Timer move_timer_;

  void Move();

  void DrawBurgers(SDL_Surface *display);

  friend void BurgerCreator::CreateBurger();
};

#endif // MY_GAME_BURGER_H_
