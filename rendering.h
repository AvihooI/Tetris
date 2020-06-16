//
// Created by Avihoo on 13/06/2020.
//

#ifndef TETRIS_RENDERING_H
#define TETRIS_RENDERING_H

#include <SDL.h>
#include "tetris.h"
#include "logic.h"



#define BLOCK_SIZE 30
#define MILLISECONDS_PER_FRAME 33
#define COLOR_COUNT 10

struct
{
	SDL_Window* window;
	SDL_Renderer* renderer;
} graphics;

struct RGB
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
};

struct RGB dim(struct RGB originalColor);

struct RGB colors[COLOR_COUNT];

int initRendering();
void destroyRendering();
void doRendering();
void renderBlock(int x, int y, unsigned int colorIndex);
void renderBoundaries();


#endif //TETRIS_RENDERING_H
