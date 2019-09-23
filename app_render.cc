//
//  app_render.cc
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "app.h"

void App::Render() {
  for (int i = 0; i < Entity::entity_list_.size(); ++i) {
    if(!Entity::entity_list_[i])
      continue;
    Entity::entity_list_[i]->Render(display_);
  }
  
  SDL_Flip(display_);
}
