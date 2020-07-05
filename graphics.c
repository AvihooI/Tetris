//
// Created by Avihoo on 05/07/2020.
//

#include "graphics.h"

void refreshWindowSize()
{
	SDL_SetWindowSize(graphics.window, BLOCK_SIZE * WINDOW_WIDTH, BLOCK_SIZE * WINDOW_HEIGHT);

	initFonts();
}

int initGraphics()
{
	SDL_Window *window = SDL_CreateWindow("Tetris", 100, 100, BLOCK_SIZE * WINDOW_WIDTH, BLOCK_SIZE * WINDOW_HEIGHT, 0);

	if (!window)
	{
		return -1;
	}

	graphics.window = window;

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
	                                            (Uint32) SDL_RENDERER_ACCELERATED | (Uint32) SDL_RENDERER_PRESENTVSYNC);

	if (!renderer)
	{
		SDL_DestroyWindow(window);
		return -1;
	}

	graphics.renderer = renderer;

	TTF_Init();

	initFonts();

	SDL_GetTicks();

	initColors();

	return 0;
}

void destroyGraphics()
{
	SDL_DestroyRenderer(graphics.renderer);
	SDL_DestroyWindow(graphics.window);

	closeFonts();

	TTF_Quit();
}