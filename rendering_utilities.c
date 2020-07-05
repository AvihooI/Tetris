//
// Created by Avihoo on 05/07/2020.
//

#include "rendering_utilities.h"

void renderFrame(unsigned int top, unsigned int left, unsigned int height, unsigned int width, unsigned int colorIndex)
{
	for (unsigned int i = 0; i < width; i++)
	{
		renderBlock(i + left, top, colorIndex, 1, 1);
		renderBlock(i + left, height + top - 1, colorIndex, 1, 1);
	}

	for (unsigned int j = 0; j < height; j++)
	{
		renderBlock(left, j + top, colorIndex, 1, 1);
		renderBlock(width + left - 1, j + top, colorIndex, 1, 1);
	}
}

void renderPiece(unsigned int pieceType, unsigned int pieceConfiguration, int top, int left, unsigned int visibleTop)
{
	if (pieceType >= 7)
	{
		return;
	}

	unsigned int (*currentPiece)[4][4] = &pieces[pieceType].blocks[pieceConfiguration];

	for (unsigned int i = 0; i < 4; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			if ((*currentPiece)[j][i] && top + j >= visibleTop)
			{
				renderBlock(left + i, top + j, (*currentPiece)[j][i], 1, 1);
			}
		}
	}
}

void renderGrid(unsigned int animation)
{
	for (unsigned int i = 0; i < GAME_GRID_WIDTH; i++)
	{
		for (unsigned int j = GAME_GRID_INVISIBLE_LINES; j < GAME_GRID_HEIGHT; j++)
		{
			if (!animation && gameState.grid[j][i])
			{
				renderBlock(MAIN_FRAME_LEFT + 1 + i, MAIN_FRAME_TOP + 1 + j - GAME_GRID_INVISIBLE_LINES,
				            gameState.grid[j][i], 2, 3);
			}
			else if (animation && gameState.lastGrid[j][i])
			{
				unsigned int dimNumerator = 2;
				unsigned int dimDenominator = 3;

				if (gameState.reducedLines[j])
				{
					dimNumerator *= animationState.ticksRemaining;
					dimDenominator *= ANIMATION_TICKS;
				}

				renderBlock(MAIN_FRAME_LEFT + 1 + i, MAIN_FRAME_TOP + 1 + j - GAME_GRID_INVISIBLE_LINES,
				            gameState.lastGrid[j][i], dimNumerator, dimDenominator);
			}
		}
	}
}

void renderBlock(unsigned int x, unsigned int y, unsigned int colorIndex, unsigned int dimNumerator,
                 unsigned int dimDenominator)
{
	SDL_Rect rect;
	rect.w = BLOCK_SIZE;
	rect.h = BLOCK_SIZE;
	rect.x = (int) (x * BLOCK_SIZE);
	rect.y = (int) (y * BLOCK_SIZE);

	SDL_Color innerColor = dim(colors[colorIndex], dimNumerator, dimDenominator);
	SDL_Color frameColor = dim(innerColor, 1, 2);

	SDL_SetRenderDrawColor(graphics.renderer, frameColor.r, frameColor.g, frameColor.b, 255);
	SDL_RenderDrawRect(graphics.renderer, &rect);

	rect.x++;
	rect.y++;
	rect.h -= 2;
	rect.w -= 2;

	SDL_SetRenderDrawColor(graphics.renderer, innerColor.r, innerColor.g, innerColor.b, 255);
	SDL_RenderFillRect(graphics.renderer, &rect);
}