#include <SDL.h>
#include "logic.h"
#include "events.h"
#include "rendering.h"
#include "menu.h"
#include "settings.h"
#include "sound.h"

void gameLoop();

int main(int argc, char *argv[])
{
	initSettings();

	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		return -1;
	}

	int status;
	if ((status = initRendering() != 0))
	{
		return status;
	}

	initSound();
	initLogic();
	initEvents();
	initMenu();

	gameLoop();

	destroyMenu();
	destroySound();
	destroyRendering();
	SDL_Quit();

	saveSettings();

	return 0;
}

void gameLoop()
{
	while (doEvents())
	{
		doRendering();
	}
}