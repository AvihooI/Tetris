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
		switch(e.key.keysym.scancode)
		{
			case SDL_SCANCODE_RETURN2:
			case SDL_SCANCODE_RETURN:
				pause_unpause();
				break;
			case SDL_SCANCODE_LEFT:
				left();
				break;
			case SDL_SCANCODE_RIGHT:
				right();
				break;
			case SDL_SCANCODE_UP:
				rotate(1);
				break;
			case SDL_SCANCODE_DOWN:
				step();
				break;
			case SDL_SCANCODE_ESCAPE:
				return 0;
			case SDL_SCANCODE_SPACE:
				drop();
				break;

		}
	}


	unsigned int currentSDLTick = SDL_GetTicks();

	if (currentSDLTick - baseEventsSDLTick >= MILLISECONDS_PER_TICK)
	{
		baseEventsSDLTick = currentSDLTick;

		tick();
	}

	return 1;
}

