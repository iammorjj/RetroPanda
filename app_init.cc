//
//  app_init.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "app.h"

#include "global.h"

bool App::Init() {
  if (WindowInit() && TTF_Init() != -1 && ResourceInit()) {
    Entity::entity_list_.push_back(&background_);
    Entity::entity_list_.push_back(&conveyor_);
    Entity::entity_list_.push_back(&burger_);
    // adv after burger cause we hide textures
    Entity::entity_list_.push_back(&advertising_);
    Entity::entity_list_.push_back(&hero_);
    Entity::entity_list_.push_back(&score_);
    Entity::entity_list_.push_back(&game_over_title_);
    
    return true;
  }
  
  return false;
}

bool App::WindowInit() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return false;
  
  if (!(display_ = SDL_SetVideoMode(global::kScrWidth, global::kScrHeight,
                                    global::kScrBpp,
                                    SDL_HWSURFACE | SDL_DOUBLEBUF)))
    return false;
  
  return true;
}

bool App::ResourceInit() {
  if (!music_.Load() ||
     
      !background_.Load() ||
     
      !advertising_.Load() ||
     
      !score_.Load() ||
     
      !conveyor_.Load() ||
     
      !hero_.Load() ||
     
      !burger_.Load() ||
     
      !game_over_title_.Load())
      return false;
  
  return true;
}
