//
//  burger_constants.h
//  MyGame
//
//  Created by Alexander Mordovsky on 17/09/2019.
//  Copyright © 2019 Alexander Mordovsky. All rights reserved.
//

#ifndef MY_GAME_BURGERCONSTANTS_H_
#define MY_GAME_BURGERCONSTANTS_H_

#include "global.h"

namespace burger_constants {
const char* const kFile = GLOBAL_ASSETS_PATH"burger.png";

const int kFrameWidth = 192;

const double kXVelNewLevel = 7.0;
const double kYVelNewLevel = kXVelNewLevel * 4.0 / 7.0;

const int kXStopLeft = 300;
const int kXStopRight = global::kScrWidth - kFrameWidth - kXStopLeft;
const int kXCanBeCaughtLeft = kXStopLeft - 15;
const int kXCanBeCaughtRight = kXStopRight + 15;

const int kXStartLeft = 160;
const int kXStartRight = global::kScrWidth - kFrameWidth - kXStartLeft;

const int kYDistanceBetweenLines = 120;
const int kYStartUp = 140;
const int kYStartMid = kYStartUp + kYDistanceBetweenLines;
const int kYStartDown = kYStartMid + kYDistanceBetweenLines;
const int kYStopUp = 265;
const int kYStopMid = kYStopUp + kYDistanceBetweenLines;
const int kYStopDown = kYStopMid + kYDistanceBetweenLines;

const int kGravity = 50;
const int kXVelStart = 70;
const int kYVelStart = 40;
}  // namespace burger_constants

#endif  // MY_GAME_BURGERCONSTANTS_H_
