//
// Created by Avihoo on 13/06/2020.
//

#ifndef TETRIS_EVENTS_H
#define TETRIS_EVENTS_H

#include "tetris.h"
#include "logic.h"
#include "menu.h"

#define MAX_MOVEMENT_KEYBOARD_COOLDOWN 85
#define MAX_ROTATION_KEYBOARD_COOLDOWN -1
#define MAX_DROP_KEYBOARD_COOLDOWN -1

struct
{
	signed int leftCooldown;
	signed int rightCooldown;
	signed int downCooldown;
	signed int dropCooldown;
	signed int rotateClockwiseCooldown;
	signed int rotateCounterClockwiseCooldown;
} keyboardCooldowns;

#define MILLISECONDS_PER_KEYBOARD_CHECK 1

void initEvents();

int doEvents();

#endif //TETRIS_EVENTS_H
