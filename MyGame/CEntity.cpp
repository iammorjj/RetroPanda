//
//  CEntity.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CEntity.hpp"

std::vector<CEntity*> CEntity::EntityList;

CEntity::CEntity() {
    Surf_Entity = NULL;
    
    //location = LEFT_DOWN;
    
    X = Y = 0.0f;
    
    Width = Height = 0;
    
    AnimState = 0;
    
    CurrentFrameRow = 0;
}

CEntity::~CEntity() {
}

//static void CheckCollisions(Location HeroLocation, CBurger& BurgerClass) {
//    
//}

bool CEntity::OnLoad(const char* File, int Width, int Height, int MaxFrames) {
    if((Surf_Entity = CSurface::OnLoad(File)) == NULL) {
        return false;
    }
    
    //CSurface::Transparent(Surf_Entity, 255, 0, 255);
    
    this->Width = Width;
    this->Height = Height;
    
    Anim_Control.MaxFrames = MaxFrames;
    
    return true;
}

void CEntity::OnLoop() {
    Anim_Control.OnAnimate();
}

void CEntity::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_Entity == NULL || Surf_Display == NULL) return;
    
    CSurface::OnDraw(Surf_Display, Surf_Entity, X, Y, Anim_Control.GetCurrentFrame() * Width, 0, Width, Height);
}

void CEntity::OnCleanup() {
    if(Surf_Entity) {
        SDL_FreeSurface(Surf_Entity);
    }
    
    Surf_Entity = NULL;
}
