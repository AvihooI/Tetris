//
// Created by Avihoo on 13/06/2020.
//

#include <SDL.h>
#include "events.h"

unsigned int baseEventsSDLTick;
unsigned int baseKeyboardStateSDLTick;


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

void initEvents()
{
	baseEventsSDLTick = SDL_GetTicks();
	baseKeyboardStateSDLTick = SDL_GetTicks();

	clearCooldowns();

	hookEvents();

	initAnimation();
}

void clearCooldowns()
{
	keyboardCooldowns.downCooldown = 0;
	keyboardCooldowns.leftCooldown = 0;
	keyboardCooldowns.rightCooldown = 0;
	keyboardCooldowns.rotateClockwiseCooldown = 0;
	keyboardCooldowns.rotateCounterClockwiseCooldown = 0;
	keyboardCooldowns.dropCooldown = 0;
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

int doEvents()
{
	if (menuState.wantsToQuit)
	{
		return 0;
	}

	SDL_Event e;

	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
	{
		return 0;
	}

	if (!menuState.isActive)
	{
		handleGameInput(&e);
		handleTicks();
	}
	else
	{
		handleMenuInput(&e);
	}

	return 1;
}

void handleMenuInput(SDL_Event *e)
{
	if ((*e).type == SDL_KEYDOWN)
	{

		switch ((*e).key.keysym.scancode)
		{
			case SDL_SCANCODE_RETURN2:
			case SDL_SCANCODE_RETURN:
				menuActionReturn();
				break;
			case SDL_SCANCODE_LEFT:
				menuActionLeft();
				break;
			case SDL_SCANCODE_RIGHT:
				menuActionRight();
				break;
			case SDL_SCANCODE_UP:
				menuActionUp();
				break;
			case SDL_SCANCODE_DOWN:
				menuActionDown();
				break;
			case SDL_SCANCODE_ESCAPE:
				menuState.isActive = 0;
				break;
			default:
				break;
		}
	}
}

void handleGameInput(SDL_Event *e)
{
	if ((*e).type == SDL_KEYDOWN)
	{
		switch ((*e).key.keysym.scancode)
		{
			case SDL_SCANCODE_RETURN2:
			case SDL_SCANCODE_RETURN:
				pause_unpause();
				break;
			case SDL_SCANCODE_ESCAPE:
				activateMenu();
				break;
			default:
				break;
		}
	}

	else if ((*e).type == SDL_KEYUP)
	{
		switch ((*e).key.keysym.scancode)
		{
			case SDL_SCANCODE_UP:
			case SDL_SCANCODE_X:
				keyboardCooldowns.rotateClockwiseCooldown = 0;
				break;
			case SDL_SCANCODE_Z:
			case SDL_SCANCODE_LCTRL:
				keyboardCooldowns.rotateCounterClockwiseCooldown = 0;
				break;
			case SDL_SCANCODE_DOWN:
				keyboardCooldowns.downCooldown = 0;
				break;
			case SDL_SCANCODE_LEFT:
				keyboardCooldowns.leftCooldown = 0;
				break;
			case SDL_SCANCODE_RIGHT:
				keyboardCooldowns.rightCooldown = 0;
				break;
			case SDL_SCANCODE_SPACE:
				keyboardCooldowns.dropCooldown = 0;
				break;
			default:
				break;

		}
	}
}

void handleTicks()
{
	unsigned int currentSDLTick = SDL_GetTicks();

	if (currentSDLTick - baseEventsSDLTick >= MILLISECONDS_PER_LOGIC_TICK)
	{
		baseEventsSDLTick = currentSDLTick;

		if (!animationState.ongoing)
		{
			doAction(TICK);
		}

		animationTick();

	}

	if (currentSDLTick - baseKeyboardStateSDLTick >= MILLISECONDS_PER_KEYBOARD_CHECK)
	{
		baseKeyboardStateSDLTick = currentSDLTick;

		if (!animationState.ongoing)
		{
			doRawInput();
		}
	}

}

unsigned int rawInputProcess(unsigned const char *keyboardState, unsigned char scanCode,
                             int *currentCooldown, int maxCooldown)
{
	if (keyboardState[scanCode])
	{
		if (*currentCooldown == 0)
		{
			*currentCooldown = maxCooldown;
			return 1;
		}
		else if (*currentCooldown > 0)
		{
			(*currentCooldown)--;
		}
	}

	return 0;
}

void doRawInput()
{
	unsigned const char *keyboardState = SDL_GetKeyboardState(NULL);

	if (rawInputProcess(keyboardState, SDL_SCANCODE_LEFT, &keyboardCooldowns.leftCooldown, MOVEMENT_KEYBOARD_COOLDOWN))
	{
		doAction(MOVE_LEFT);
	}

	if (rawInputProcess(keyboardState, SDL_SCANCODE_RIGHT, &keyboardCooldowns.rightCooldown,
	                    MOVEMENT_KEYBOARD_COOLDOWN))
	{
		doAction(MOVE_RIGHT);
	}

	if (rawInputProcess(keyboardState, SDL_SCANCODE_DOWN, &keyboardCooldowns.downCooldown, MOVEMENT_KEYBOARD_COOLDOWN))
	{
		doAction(MOVE_DOWN);
	}

	if (rawInputProcess(keyboardState, SDL_SCANCODE_SPACE, &keyboardCooldowns.dropCooldown, DROP_KEYBOARD_COOLDOWN))
	{
		doAction(DROP);
	}

	if (rawInputProcess(keyboardState, SDL_SCANCODE_UP, &keyboardCooldowns.rotateClockwiseCooldown,
	                    ROTATION_KEYBOARD_COOLDOWN) ||
	    rawInputProcess(keyboardState, SDL_SCANCODE_X, &keyboardCooldowns.rotateClockwiseCooldown,
	                    ROTATION_KEYBOARD_COOLDOWN))
	{
		doAction(ROTATE_CLOCKWISE);
	}

	if (rawInputProcess(keyboardState, SDL_SCANCODE_LCTRL, &keyboardCooldowns.rotateCounterClockwiseCooldown,
	                    ROTATION_KEYBOARD_COOLDOWN) ||
	    rawInputProcess(keyboardState, SDL_SCANCODE_Z, &keyboardCooldowns.rotateCounterClockwiseCooldown,
	                    ROTATION_KEYBOARD_COOLDOWN))
	{
		doAction(ROTATE_COUNTER_CLOCKWISE);
	}
}
