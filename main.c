#include <SDL.h>
#include "settings.h"
#include "sound.h"
#include "logic.h"
#include "menu.h"
#include "events.h"
#include "rendering.h"

void gameLoop();

int main(int argc, char *argv[])
{
	initSettings();

	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		return -1;
	}

	int status;
	if ((status = initGraphics() != 0))
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
	destroyGraphics();
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

/*
 * TODO: code documentation
 * TODO: missing files error handling
 * TODO: refactor menu system
 * */