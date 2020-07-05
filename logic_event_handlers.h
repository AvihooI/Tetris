//
// Created by Avihoo on 05/07/2020.
//

#ifndef TETRIS_LOGIC_EVENT_HANDLERS_H
#define TETRIS_LOGIC_EVENT_HANDLERS_H

#include "logic.h"
#include "sound.h"
#include "animation.h"

void hookEvents();

/*Event Handlers*/

void movementEvent(void);

void pieceLandedEvent(void);

void lineClearedEvent(void);

void tetrisEvent(void);

void rotateEvent(void);

void levelUpEvent(void);

#endif //TETRIS_LOGIC_EVENT_HANDLERS_H
