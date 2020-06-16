//
// Created by Avihoo on 13/06/2020.
//

#include "rendering.h"

unsigned int baseRenderingSDLTick;

struct RGB dim(struct RGB originalColor, unsigned int dimNumerator, unsigned int dimDenominator)
{
	originalColor.r /= dimDenominator;
	originalColor.r *= dimNumerator;
	originalColor.g /= dimDenominator;
	originalColor.g *= dimNumerator;
	originalColor.b /= dimDenominator;
	originalColor.b *= dimNumerator;

	return originalColor;
}

void renderGridAndPiece();

void renderEnqueuedPiece();

int initRendering()
{
	SDL_Window *window = SDL_CreateWindow("Tetris", 100, 100, BLOCK_SIZE*WINDOW_WIDTH, BLOCK_SIZE*WINDOW_HEIGHT, 0);

	if (!window)
	{
		return -1;
	}

	graphics.window = window;

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!renderer)
	{
		return -1;
	}

	graphics.renderer = renderer;

	baseRenderingSDLTick = SDL_GetTicks();

	colors[0].r = 0;
	colors[0].g = 0;
	colors[0].b = 0;

	colors[1].r = 128;
	colors[1].g = 128;
	colors[1].b = 128;

	colors[2].r = 88;
	colors[2].g = 98;
	colors[2].b = 104;

	colors[3].r = 255;
	colors[3].g = 0;
	colors[3].b = 0;

	colors[4].r = 0;
	colors[4].g = 255;
	colors[4].b = 0;

	colors[5].r = 0;
	colors[5].g = 0;
	colors[5].b = 255;

	colors[6].r = 255;
	colors[6].g = 255;
	colors[6].b = 00;

	colors[7].r = 255;
	colors[7].g = 0;
	colors[7].b = 255;

	colors[8].r = 0;
	colors[8].g = 255;
	colors[8].b = 255;

	colors[9].r = 125;
	colors[9].g = 120;
	colors[9].b = 95;

	return 0;
}

void destroyRendering()
{
	SDL_DestroyRenderer(graphics.renderer);
	SDL_DestroyWindow(graphics.window);
}

void doRendering()
{
	unsigned int currentSDLTick = SDL_GetTicks();

	if (currentSDLTick - baseRenderingSDLTick < MILLISECONDS_PER_FRAME)
	{
		return;
	}

	baseRenderingSDLTick = currentSDLTick;

	SDL_SetRenderDrawColor(graphics.renderer,0,0,0,255);
	SDL_RenderClear(graphics.renderer);

	renderBoundaries();
	renderGridAndPiece();
	renderEnqueuedPiece();

	SDL_RenderPresent(graphics.renderer);

}

void renderFrame(unsigned int top, unsigned int left, unsigned int height, unsigned int width, unsigned int colorIndex)
{
	for (unsigned int i = 0; i < width; i++)
	{
		renderBlock(i+left, top, colorIndex, 1, 1);
		renderBlock(i+left, height+top - 1, colorIndex, 1, 1);
	}

	for (unsigned int j = 0; j < height; j++)
	{
		renderBlock(left, j+top, colorIndex, 1, 1);
		renderBlock(width+left-1, j+top, colorIndex, 1, 1);
	}
}

void renderBoundaries()
{
	/*Main Boundaries*/

	renderFrame(0, 0, WINDOW_HEIGHT, WINDOW_WIDTH, 1);

	/*Game Frame*/

	renderFrame(MAIN_FRAME_TOP, MAIN_FRAME_LEFT, MAIN_FRAME_HEIGHT, MAIN_FRAME_WIDTH, 2);

	/*Enqueued Piece Frame*/
	renderFrame(ENQUEUED_FRAME_TOP-1, ENQUEUED_FRAME_LEFT-1, 6,6,1);
}

void renderPiece(unsigned int pieceType, unsigned int pieceConfiguration, int top, int left)
{
	if (pieceType >= 7)
		return;

	unsigned const int (*currentPiece)[4][4] = &pieces[pieceType].blocks[pieceConfiguration];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if((*currentPiece)[j][i])
			{
				renderBlock(left+i,top+j, (*currentPiece)[j][i], 1, 1);
			}
		}
	}
}

void renderEnqueuedPiece()
{
	/*TODO: correct piece appearance in enqueued frame*/

	renderPiece(gameState.nextPieceType,0,ENQUEUED_FRAME_TOP, ENQUEUED_FRAME_LEFT);
}

void renderGridAndPiece()
{
	/*Grid*/

	for (int i = 0; i < GAME_GRID_WIDTH; i++)
	{
		for (int j = 0; j < GAME_GRID_HEIGHT; j++)
		{
			if(gameState.grid[j][i])
			{
				unsigned int (*temp)[24][10] = &gameState.grid;

				renderBlock(MAIN_FRAME_LEFT+1+i,MAIN_FRAME_TOP+1+j, gameState.grid[j][i], 2, 3);
			}
		}
	}

	/*Piece*/

	renderPiece(gameState.pieceType,gameState.pieceConfiguration,MAIN_FRAME_TOP+1+gameState.pieceTop, MAIN_FRAME_LEFT+1+gameState.pieceLeft);

}

/*TODO: add dim factor*/
void renderBlock(unsigned int x, unsigned int y, unsigned int colorIndex, unsigned int dimNumerator, unsigned int dimDenominator)
{
	SDL_Rect rect;
	rect.w = BLOCK_SIZE;
	rect.h = BLOCK_SIZE;
	rect.x = x*BLOCK_SIZE;
	rect.y = y*BLOCK_SIZE;

	struct RGB innerColor = dim(colors[colorIndex], dimNumerator, dimDenominator);
	struct RGB frameColor = dim(innerColor, 1, 2);

	SDL_SetRenderDrawColor(graphics.renderer, frameColor.r, frameColor.g, frameColor.b, 255);
	SDL_RenderDrawRect(graphics.renderer,&rect);

	rect.x++;
	rect.y++;
	rect.h -=2;
	rect.w -=2;

	SDL_SetRenderDrawColor(graphics.renderer, innerColor.r, innerColor.g, innerColor.b, 255);
	SDL_RenderFillRect(graphics.renderer,&rect);
}
