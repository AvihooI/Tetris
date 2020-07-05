//
// Created by Avihoo on 05/07/2020.
//

#include "logic_event_handlers.h"

void movementEvent(void)
{

}

void pieceLandedEvent(void)
{
	playSoundLand();
}

void lineClearedEvent(void)
{
	startAnimation();
	playSoundLineClear();
}

void tetrisEvent(void)
{
	startAnimation();
	playSoundTetris();
}

void rotateEvent(void)
{
	playSoundRotate();
}

void levelUpEvent(void)
{
	playSoundLevelUp();
}

void hookEvents()
{
	gameEvents.movement = movementEvent;
	gameEvents.rotate = rotateEvent;
	gameEvents.pieceLanded = pieceLandedEvent;
	gameEvents.lineCleared = lineClearedEvent;
	gameEvents.tetris = tetrisEvent;
	gameEvents.levelUp = levelUpEvent;
}