#include <SDL.h>
#include "logic.h"
#include "events.h"
#include "rendering.h"

void gameLoop();

int main(int argc, char *argv[])
{

	if (SDL_Init(SDL_INIT_EVERYTHING))
		return -1;

	int status;
	if ((status = initRendering() != 0))
		return status;

	initLogic();
	initEvents();

	gameLoop();

	destroyRendering();
	SDL_Quit();

	return 0;
}

void gameLoop()
{
	while (doEvents())
	{
		doRendering();
	}
}

/*
 * TODO: Heavy refactoring
 * TODO: Start implementing menu system (resume, restart, choose level, about, quit)
 * TODO: Refactor, document code, choose a proper name for the game, enrich README, and make first release (Alpha 0.1)
*/