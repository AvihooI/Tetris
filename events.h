//
// Created by Avihoo on 13/06/2020.
//

#ifndef TETRIS_EVENTS_H
#define TETRIS_EVENTS_H

#include "tetris.h"
#include "logic.h"
#include "menu.h"
#include "animation.h"
#include "settings.h"

#define MOVEMENT_KEYBOARD_COOLDOWN (currentSettings.movementKeyboardCooldown)
#define ROTATION_KEYBOARD_COOLDOWN (currentSettings.rotationKeyboardCooldown)
#define DROP_KEYBOARD_COOLDOWN (currentSettings.dropKeyboardCooldown)

#define MILLISECONDS_PER_KEYBOARD_CHECK 1

struct
{
	signed int leftCooldown;
	signed int rightCooldown;
	signed int downCooldown;
	signed int dropCooldown;
	signed int rotateClockwiseCooldown;
	signed int rotateCounterClockwiseCooldown;
} keyboardCooldowns;


void initEvents();

int doEvents();

#endif //TETRIS_EVENTS_H
