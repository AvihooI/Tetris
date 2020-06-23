//
// Created by Avihoo on 13/06/2020.
//

#include <SDL.h>
#include "events.h"

unsigned int baseEventsSDLTick;

void handleGameInput(SDL_Event *e);

void handleTicks();

void handleMenuInput(SDL_Event *e);

void initEvents()
{
	baseEventsSDLTick = SDL_GetTicks();
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

void handleTicks()
{
	unsigned int currentSDLTick = SDL_GetTicks();

	if (currentSDLTick - baseEventsSDLTick >= MILLISECONDS_PER_TICK)
	{
		baseEventsSDLTick = currentSDLTick;

		doAction(TICK);
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
			case SDL_SCANCODE_LEFT:
				doAction(MOVE_LEFT);
				break;
			case SDL_SCANCODE_RIGHT:
				doAction(MOVE_RIGHT);
				break;
			case SDL_SCANCODE_UP:
				doAction(ROTATE_CLOCKWISE);
				break;
			case SDL_SCANCODE_LCTRL:
				doAction(ROTATE_COUNTER_CLOCKWISE);
				break;
			case SDL_SCANCODE_DOWN:
				doAction(MOVE_DOWN);
				break;
			case SDL_SCANCODE_ESCAPE:
				menuState.isActive = 1;
				break;
			case SDL_SCANCODE_SPACE:
				doAction(DROP);
				break;

		}
	}
}

