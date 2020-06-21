//
// Created by Avihoo on 13/06/2020.
//

#ifndef TETRIS_RENDERING_H
#define TETRIS_RENDERING_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "tetris.h"
#include "logic.h"

#define BLOCK_SIZE 30
#define MILLISECONDS_PER_FRAME 33
#define COLOR_COUNT 10
#define FONT_FILENAME "hemi_head.ttf"

struct
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font;
} graphics;

struct RGB
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
};

unsigned int baseRenderingSDLTick;

struct RGB dim(struct RGB originalColor, unsigned int dimNumerator, unsigned int dimDenominator);

struct RGB colors[COLOR_COUNT];

int initRendering();
void destroyRendering();
void doRendering();
void renderBlock(unsigned int x, unsigned int y, unsigned int colorIndex, unsigned int dimNumerator, unsigned int dimDenominator);
void renderBoundaries();
void renderFrame(unsigned int top, unsigned int left, unsigned int height, unsigned int width, unsigned int colorIndex);
void renderPiece(unsigned int pieceType, unsigned int pieceConfiguration, int top, int left, unsigned int visibleTop);
void renderGridAndPiece();
void renderEnqueuedPiece();
void initColors();

#endif //TETRIS_RENDERING_H
