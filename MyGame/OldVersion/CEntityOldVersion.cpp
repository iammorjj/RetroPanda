//
//  CEntityOldVersion.cpp
//  MyGame
//
//  Created by Alexander Mordovsky on 06/08/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#include "CEntityOldVersion.hpp"

std::vector<CEntityOldVersion*> CEntityOldVersion::EntityList;

CEntityOldVersion::CEntityOldVersion() {
    Surf_Entity = NULL;
    
    X = Y = 0.0f;
    
    Width = Height = 0;
    
    AnimState = 0;
    
    CurrentFrameRow = 0;
}


CEntityOldVersion::~CEntityOldVersion() {
}

bool CEntityOldVersion::OnLoad(const char* File, int Width, int Height, int MaxFrames) {
    if((Surf_Entity = Surface::load(File)) == NULL) {
        return false;
    }
    
    this->Width = Width;
    this->Height = Height;
    
    Anim_Control.MaxFrames = MaxFrames;
    
    return true;
}

void CEntityOldVersion::OnLoop() {
    Anim_Control.OnAnimate();
}

void CEntityOldVersion::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_Entity == NULL || Surf_Display == NULL) return;
    
    Surface::draw(Surf_Display, Surf_Entity, X, Y, Anim_Control.GetCurrentFrame() * Width, 0, Width, Height);
}

void CEntityOldVersion::OnCleanup() {
    if(Surf_Entity) {
        SDL_FreeSurface(Surf_Entity);
    }
    
    Surf_Entity = NULL;
}
