//
//  CApp_OnRender.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 27/07/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CApp.hpp"

void CApp::OnRender() {
    CSurface::OnDraw(Surf_Display, Surf_Background, 0, 0);
    
    sprintf(buf, "%d", score);
    Surf_Score_Black = TTF_RenderText_Solid( font, buf, textColorBlack );
    Surf_Score_White = TTF_RenderText_Solid( font, buf, textColorWhite );
    printf("font width is %hu\n", Surf_Score_White->clip_rect.w);
    CSurface::OnDraw(Surf_Display, Surf_Score_Black, CONSTANTS::BACKGROUND_WIDTH / 2 - Surf_Score_Black->clip_rect.w / 2 + 10, 60 + 10);
    CSurface::OnDraw(Surf_Display, Surf_Score_White, CONSTANTS::BACKGROUND_WIDTH / 2 - Surf_Score_Black->clip_rect.w / 2, 60);
    
    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;
        
        CEntity::EntityList[i]->OnRender(Surf_Display);
    }
    
    SDL_Flip(Surf_Display);
}
