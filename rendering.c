//
// Created by Avihoo on 13/06/2020.
//

#include "rendering.h"

void doRendering()
{
	static unsigned int baseRenderingSDLTick = 0;

	unsigned int currentSDLTick = SDL_GetTicks();

	if (currentSDLTick - baseRenderingSDLTick < MILLISECONDS_PER_FRAME)
	{
		return;
	}
	else
	{
		baseRenderingSDLTick = currentSDLTick;
	}

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

		printText((int) ((MENU_LEFT + MENU_WIDTH / 2) * BLOCK_SIZE),
		          (int) ((MENU_TOP + 1 + MENU_ITEM_SPACING * i) * BLOCK_SIZE), 1, 0,
		          selectedColor, fonts.smallFont, menuState.menus[menuState.selectedMenu].menuItems[i].getText());
	}
}

void renderText()
{

	printText(SCORE_TEXT_LEFT * BLOCK_SIZE, (int) ((SCORE_TEXT_TOP) * BLOCK_SIZE), 0, 0, colors[12], fonts.mainFont,
	          "Score: %d",
	          gameState.score);
	printText(LINES_REMAINING_TEXT_LEFT * BLOCK_SIZE, LINES_REMAINING_TEXT_TOP * BLOCK_SIZE, 0, 0, colors[12],
	          fonts.mainFont, "Lines remaining: %d", gameState.linesToLevel - gameState.lineCount);

	printText(LEVEL_TEXT_LEFT * BLOCK_SIZE + BLOCK_SIZE / 2, LEVEL_TEXT_TOP * BLOCK_SIZE + BLOCK_SIZE / 2, 1, 1,
	          colors[12],
	          fonts.mainFont, "Level: %d", gameState.level + 1);

	if (gameState.gameOver || gameState.gamePaused)
	{
		printText((int) ((MAIN_FRAME_LEFT + MAIN_FRAME_WIDTH / 2) * BLOCK_SIZE),
		          (int) ((MAIN_FRAME_TOP + MAIN_FRAME_HEIGHT / 2) * BLOCK_SIZE), 1, 1, colors[12], fonts.smallFont,
		          "Press Enter to Continue");
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