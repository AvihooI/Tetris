#include <SDL.h>
#include "logic.h"
#include "events.h"
#include "rendering.h"
#include "menu.h"

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
	initMenu();

	gameLoop();

	destroyMenu();
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