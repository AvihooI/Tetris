//
// Created by Avihoo on 13/06/2020.
//

#include <SDL.h>
#include "events.h"

unsigned int baseEventsSDLTick;

void initEvents()
{
	baseEventsSDLTick = SDL_GetTicks();
}

int doEvents()
{
	SDL_Event e;

	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
		return 0;

	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.scancode)
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
				return 0;
			case SDL_SCANCODE_SPACE:
				doAction(DROP);
				break;

		}
	}

	unsigned int currentSDLTick = SDL_GetTicks();

	if (currentSDLTick - baseEventsSDLTick >= MILLISECONDS_PER_TICK)
	{
		baseEventsSDLTick = currentSDLTick;

		doAction(TICK);
	}

	return 1;
}

