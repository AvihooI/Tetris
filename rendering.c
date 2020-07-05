//
// Created by Avihoo on 13/06/2020.
//

#include "rendering.h"

#include <stdio.h>

SDL_Color dim(SDL_Color originalColor, unsigned int dimNumerator, unsigned int dimDenominator)
{
	return interpolate(originalColor, colors[0], dimNumerator, dimDenominator);
}

void refreshWindowSize()
{
	SDL_SetWindowSize(graphics.window, BLOCK_SIZE * WINDOW_WIDTH, BLOCK_SIZE * WINDOW_HEIGHT);

	initFonts();
}

void initFonts()
{
	closeFonts();

	graphics.mainFont = TTF_OpenFont(FONT_FILENAME, BLOCK_SIZE);
	graphics.smallFont = TTF_OpenFont(FONT_FILENAME, (int)(BLOCK_SIZE * 3) / 4);
}

void closeFonts()
{
	if (graphics.mainFont)
	{
		TTF_CloseFont(graphics.mainFont);
	}

	if (graphics.smallFont)
	{
		TTF_CloseFont(graphics.smallFont);
	}
}

int initRendering()
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

	baseRenderingSDLTick = SDL_GetTicks();

	initColors();

	return 0;
}

void destroyRendering()
{
	SDL_DestroyRenderer(graphics.renderer);
	SDL_DestroyWindow(graphics.window);

	closeFonts();

	TTF_Quit();
}

void doRendering()
{
	unsigned int currentSDLTick = SDL_GetTicks();

	if (currentSDLTick - baseRenderingSDLTick < MILLISECONDS_PER_FRAME)
	{
		return;
	}

	baseRenderingSDLTick = currentSDLTick;

	SDL_SetRenderDrawColor(graphics.renderer, colors[0].r, colors[0].g, colors[0].b, 255);
	SDL_RenderClear(graphics.renderer);

	if (menuState.isActive)
	{
		renderMenu();
	}

	renderBoundaries();
	if (!animationState.ongoing)
	{
		renderGridAndPiece();
	}
	else
	{
		renderGrid(1);
	}

	renderEnqueuedPiece();
	renderText();

	SDL_RenderPresent(graphics.renderer);

}

void renderMenu()
{
	unsigned int menuItemCount = menuState.menus[menuState.selectedMenu].menuItemCount;

	renderFrame(MENU_TOP, MENU_LEFT, menuItemCount * MENU_ITEM_SPACING + 1, MENU_WIDTH, 1);

	unsigned char colorCorrect = (unsigned char) ((SDL_GetTicks() / 100) % 100);

	if (colorCorrect > 50)
	{
		colorCorrect = (unsigned char) (100 - colorCorrect);
	}

	SDL_Color varyingColor = interpolate(colors[10], colors[11], colorCorrect, 50);


	for (int i = 0; i < menuItemCount; i++)
	{
		SDL_Color selectedColor = (menuState.menus[menuState.selectedMenu].selectedItem == i ? varyingColor
		                                                                                     : colors[1]);

		printText((int)((MENU_LEFT + MENU_WIDTH / 2) * BLOCK_SIZE), (int)((MENU_TOP + 1 + MENU_ITEM_SPACING * i) * BLOCK_SIZE), 1, 0,
		          selectedColor, graphics.smallFont, menuState.menus[menuState.selectedMenu].menuItems[i].getText());
	}
}

void printText(int left, int top, unsigned int leftCentered, unsigned int topCentered, SDL_Color color, TTF_Font *font,
               const char *fmt, ...)
{
	char str[64];

	va_list args;
			va_start(args, fmt);
	vsnprintf(str, sizeof(str), fmt, args);
			va_end(args);

	SDL_Surface *surface = TTF_RenderText_Solid(font, str, color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(graphics.renderer, surface);

	SDL_Rect dRect = {left, top, 0, 0};

	SDL_QueryTexture(texture, 0, 0, &dRect.w, &dRect.h);
	if (leftCentered)
	{
		dRect.x -= dRect.w / 2;
	}

	if (topCentered)
	{
		dRect.y -= dRect.h / 2;
	}

	SDL_RenderCopy(graphics.renderer, texture, 0, &dRect);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void renderText()
{

	printText(SCORE_TEXT_LEFT * BLOCK_SIZE, (int)((SCORE_TEXT_TOP) * BLOCK_SIZE), 0, 0, colors[12], graphics.mainFont,
	          "Score: %d",
	          gameState.score);
	printText(LINES_REMAINING_TEXT_LEFT * BLOCK_SIZE, LINES_REMAINING_TEXT_TOP * BLOCK_SIZE, 0, 0, colors[12],
	          graphics.mainFont, "Lines remaining: %d", gameState.linesToLevel - gameState.lineCount);

	printText(LEVEL_TEXT_LEFT * BLOCK_SIZE + BLOCK_SIZE / 2, LEVEL_TEXT_TOP * BLOCK_SIZE + BLOCK_SIZE / 2, 1, 1,
	          colors[12],
	          graphics.mainFont, "Level: %d", gameState.level + 1);

	if (gameState.gameOver || gameState.gamePaused)
	{
		printText((int)((MAIN_FRAME_LEFT + MAIN_FRAME_WIDTH / 2) * BLOCK_SIZE),
		          (int)((MAIN_FRAME_TOP + MAIN_FRAME_HEIGHT / 2) * BLOCK_SIZE), 1, 1, colors[12], graphics.smallFont,
		          "Press Enter to Continue");
	}
}

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

void renderBoundaries()
{
	/*Main Boundaries*/

	renderFrame(0, 0, WINDOW_HEIGHT, WINDOW_WIDTH, 1);

	/*Game Frame*/

	renderFrame(MAIN_FRAME_TOP, MAIN_FRAME_LEFT, MAIN_FRAME_HEIGHT, MAIN_FRAME_WIDTH, 2);

	/*Enqueued Piece Frame*/
	renderFrame(ENQUEUED_FRAME_TOP, ENQUEUED_FRAME_LEFT, ENQUEUED_FRAME_HEIGHT, ENQUEUED_FRAME_WIDTH, 1);
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

void renderEnqueuedPiece()
{
	renderPiece(gameState.nextPieceType, 0, ENQUEUED_FRAME_TOP + 1 + pieces[gameState.nextPieceType].correctTop,
	            ENQUEUED_FRAME_LEFT + 1 + pieces[gameState.nextPieceType].correctLeft, 0);
}

void renderGridAndPiece()
{
	/*Grid*/

	renderGrid(0);

	/*Piece*/

	renderPiece(gameState.pieceType, gameState.pieceConfiguration,
	            MAIN_FRAME_TOP + 1 + gameState.pieceTop - GAME_GRID_INVISIBLE_LINES,
	            MAIN_FRAME_LEFT + 1 + gameState.pieceLeft, MAIN_FRAME_TOP + 1);

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

SDL_Color interpolate(SDL_Color color1, SDL_Color color2, unsigned int factorNumerator, unsigned int factorDenominator)
{
	unsigned int r = color1.r * factorNumerator + color2.r * (factorDenominator - factorNumerator);
	unsigned int g = color1.g * factorNumerator + color2.g * (factorDenominator - factorNumerator);
	unsigned int b = color1.b * factorNumerator + color2.b * (factorDenominator - factorNumerator);

	r /= factorDenominator;
	g /= factorDenominator;
	b /= factorDenominator;

	SDL_Color result = {(Uint8) r, (Uint8) g, (Uint8) b};

	return result;
}
