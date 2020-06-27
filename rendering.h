//
// Created by Avihoo on 13/06/2020.
//

#ifndef TETRIS_RENDERING_H
#define TETRIS_RENDERING_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "tetris.h"
#include "logic.h"
#include "menu.h"
#include "animation.h"

#define BLOCK_SIZE 30
#define MILLISECONDS_PER_FRAME 33
#define COLOR_COUNT 13
#define FONT_FILENAME "hemi_head.ttf"

struct
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	TTF_Font *mainFont;
	TTF_Font *smallFont;
} graphics;

unsigned int baseRenderingSDLTick;

SDL_Color interpolate(SDL_Color color1, SDL_Color color2, unsigned int factorNumerator, unsigned int factorDenominator);

SDL_Color dim(SDL_Color originalColor, unsigned int dimNumerator, unsigned int dimDenominator);

SDL_Color colors[COLOR_COUNT];

int initRendering();

void destroyRendering();

void doRendering();

void renderBlock(unsigned int x, unsigned int y, unsigned int colorIndex, unsigned int dimNumerator,
                 unsigned int dimDenominator);

void renderBoundaries();

void renderFrame(unsigned int top, unsigned int left, unsigned int height, unsigned int width, unsigned int colorIndex);

void renderPiece(unsigned int pieceType, unsigned int pieceConfiguration, int top, int left, unsigned int visibleTop);

void renderGridAndPiece();

void renderEnqueuedPiece();

void initColors();

void printText(int left, int top, unsigned int leftCentered, unsigned int topCentered, SDL_Color color, TTF_Font *font,
               const char *fmt, ...);

#endif //TETRIS_RENDERING_H
