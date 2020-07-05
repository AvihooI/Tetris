//
// Created by Avihoo on 05/07/2020.
//

#ifndef TETRIS_GRAPHICS_H
#define TETRIS_GRAPHICS_H

#include <SDL.h>
#include "tetris.h"
#include "text.h"

/*Graphical resources*/

struct
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} graphics;

/*Window and graphical device initialization and destruction*/

int initGraphics();

void destroyGraphics();

void refreshWindowSize();

#endif //TETRIS_GRAPHICS_H
