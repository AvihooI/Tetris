//
// Created by Avihoo on 26/06/2020.
//

#ifndef TETRIS_ANIMATION_H
#define TETRIS_ANIMATION_H

#include "logic.h"
#include "tetris.h"

#define ANIMATION_TICKS 50

typedef struct animation_state
{
	unsigned int ticksRemaining;
	unsigned int ongoing;

} animation_state;

extern animation_state animationState;

void initAnimation();

void startAnimation();

void animationTick();

#endif //TETRIS_ANIMATION_H
