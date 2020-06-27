//
// Created by Avihoo on 13/06/2020.
//

#include <SDL.h>
#include "events.h"



unsigned int baseEventsSDLTick;
unsigned int baseKeyboardStateSDLTick;

void handleGameInput(SDL_Event *e);

void handleTicks();

void handleMenuInput(SDL_Event *e);

void doRawInput();

void initEvents()
{
	baseEventsSDLTick = SDL_GetTicks();
	baseKeyboardStateSDLTick = SDL_GetTicks();

	keyboardCooldowns.downCooldown = 0;
	keyboardCooldowns.leftCooldown = 0;
	keyboardCooldowns.rightCooldown = 0;
	keyboardCooldowns.rotateClockwiseCooldown = 0;
	keyboardCooldowns.rotateCounterClockwiseCooldown = 0;
	keyboardCooldowns.dropCooldown = 0;

	initAnimation();
}

int doEvents()
{
	if (menuState.wantsToQuit)
		return 0;

	SDL_Event e;

	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
		return 0;

	if (!menuState.isActive)
	{
		handleGameInput(&e);
		handleTicks();
	} else
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
		}
	}

	else if ((*e).type == SDL_KEYUP)
	{
		switch((*e).key.keysym.scancode)
		{
			case SDL_SCANCODE_UP:
				keyboardCooldowns.rotateClockwiseCooldown = 0;
				break;
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
			doAction(TICK);

		animationTick();

	}

	if (currentSDLTick - baseKeyboardStateSDLTick >= MILLISECONDS_PER_KEYBOARD_CHECK)
	{
		baseKeyboardStateSDLTick = currentSDLTick;

		if (!animationState.ongoing)
			doRawInput();
	}

}

unsigned int rawInputProcess(unsigned const char* keyboardState, unsigned char scanCode, int *currentCooldown, int maxCooldown)
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
	unsigned const char* keyboardState = SDL_GetKeyboardState(NULL);

	if (rawInputProcess(keyboardState, SDL_SCANCODE_LEFT, &keyboardCooldowns.leftCooldown, MAX_MOVEMENT_KEYBOARD_COOLDOWN))
		doAction(MOVE_LEFT);

	if (rawInputProcess(keyboardState, SDL_SCANCODE_RIGHT, &keyboardCooldowns.rightCooldown, MAX_MOVEMENT_KEYBOARD_COOLDOWN))
		doAction(MOVE_RIGHT);

	if (rawInputProcess(keyboardState, SDL_SCANCODE_DOWN, &keyboardCooldowns.downCooldown, MAX_MOVEMENT_KEYBOARD_COOLDOWN))
		doAction(MOVE_DOWN);

	if (rawInputProcess(keyboardState, SDL_SCANCODE_SPACE, &keyboardCooldowns.dropCooldown, MAX_DROP_KEYBOARD_COOLDOWN))
		doAction(DROP);

	if (rawInputProcess(keyboardState, SDL_SCANCODE_UP, &keyboardCooldowns.rotateClockwiseCooldown, MAX_ROTATION_KEYBOARD_COOLDOWN))
		doAction(ROTATE_CLOCKWISE);

	if (rawInputProcess(keyboardState, SDL_SCANCODE_LCTRL, &keyboardCooldowns.rotateCounterClockwiseCooldown, MAX_ROTATION_KEYBOARD_COOLDOWN))
		doAction(ROTATE_COUNTER_CLOCKWISE);
}
