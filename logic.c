//
// Created by Avihoo on 14/06/2020.
//

#include "logic.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void initLogic()
{
	pieces[0] = createO();
	pieces[1] = createI();
	pieces[2] = createT();
	pieces[3] = createJ();
	pieces[4] = createL();
	pieces[5] = createS();
	pieces[6] = createZ();

	gameState.gamePaused = 1;
	gameState.gameOver = 0;
	gameState.ticksPerStep = BASE_TICKS_PER_STEP;
	gameState.current_tick = 0;
	gameState.pieceType = 7;

	gameState.pieceConfiguration = 0;

	clearGrid();

	srand(time(0));

	gameState.nextPieceType = rand() % 7;
}

void clearGrid()
{
	for (int i = 0; i < GAME_GRID_WIDTH; i++)
	{
		for (int j = 0; j < GAME_GRID_HEIGHT; j++)
		{
			gameState.grid[j][i] = 0;
		}
	}
}

unsigned int verifyPiecePlacement(int pieceLeft, int pieceTop, unsigned int pieceType, unsigned int pieceConfiguration)
{
	unsigned const int (*currentPiece)[4][4] = &pieces[pieceType].blocks[pieceConfiguration];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((*currentPiece)[j][i])
			{
				unsigned int blockLeft = pieceLeft + i;
				unsigned int blockTop = pieceTop + j;

				/*Check out of bounds*/
				if (blockLeft < 0 || blockLeft >= GAME_GRID_WIDTH)
					return 0;

				if (blockTop < 0 || blockTop >= GAME_GRID_HEIGHT)
					return 0;

				/*Check grid collision*/
				if (gameState.grid[blockTop][blockLeft])
					return 0;
			}
		}
	}

	return 1;
}

unsigned int tryPiecePlacement(int pieceLeft, int pieceTop, unsigned int pieceType, unsigned int pieceConfiguration)
{
	if (verifyPiecePlacement(pieceLeft,pieceTop,pieceType,pieceConfiguration))
	{
		gameState.pieceLeft = pieceLeft;
		gameState.pieceTop = pieceTop;
		gameState.pieceType = pieceType;
		gameState.pieceConfiguration = pieceConfiguration;
		return 1;
	}

	return 0;
}

void rotate(int attempts)
{
	if (gameState.gamePaused)
		return;

	if(!tryPiecePlacement(gameState.pieceLeft,gameState.pieceTop, gameState.pieceType, (gameState.pieceConfiguration + 1) % pieces[gameState.pieceType].configurations) && (attempts < MAXIMAL_ROTATE_ATTEMPTS))
	{
		/*Try a step*/
		if (verifyPiecePlacement(gameState.pieceLeft, gameState.pieceTop+1, gameState.pieceType, (gameState.pieceConfiguration + 1) % pieces[gameState.pieceType].configurations))
		{
			step();
			rotate(1);
			return;
		}

		/*Try two steps*/
		if (verifyPiecePlacement(gameState.pieceLeft, gameState.pieceTop+2, gameState.pieceType, (gameState.pieceConfiguration + 1) % pieces[gameState.pieceType].configurations))
		{
			step();
			step();
			rotate(1);
			return;
		}

		/*Try side movement*/
		if (gameState.pieceLeft < PIECE_START_LEFT)
		{
			right();
			rotate(attempts+1);
		}
		else
		{
			left();
			rotate(attempts+1);
		}
	}
}

void left()
{
	if (gameState.gamePaused)
		return;

	tryPiecePlacement(gameState.pieceLeft-1,gameState.pieceTop, gameState.pieceType, gameState.pieceConfiguration);
}

void right()
{
	if (gameState.gamePaused)
		return;

	tryPiecePlacement(gameState.pieceLeft+1,gameState.pieceTop, gameState.pieceType, gameState.pieceConfiguration);
}

void tick()
{
	if (gameState.gamePaused)
		return;

	gameState.current_tick++;

	if (gameState.current_tick >= gameState.ticksPerStep)
		step();
}

void step()
{

	gameState.current_tick = 0;

	if (gameState.gamePaused)
		return;

	if (gameState.pieceType >= 7)
	{
		newPiece();
	}

	if (!tryPiecePlacement(gameState.pieceLeft,gameState.pieceTop+1, gameState.pieceType, gameState.pieceConfiguration))
		landPiece();
}

unsigned int newPiece()
{
	/*TODO: improve randomizer*/

	unsigned int pieceType = gameState.nextPieceType;
	gameState.nextPieceType = rand() % 7;

	int tryTop;

	for (tryTop = -3; tryTop <= 0; tryTop++)
	{
		 if (verifyPiecePlacement(PIECE_START_LEFT, tryTop, pieceType, 0))
		 	break;
	}

	if (tryTop == 1)
	{
		return 0;
	}
	else
	{
		gameState.pieceType = pieceType;
		gameState.pieceConfiguration = 0;
		gameState.pieceTop = tryTop;
		gameState.pieceLeft = PIECE_START_LEFT;
		gameState.ticksPerStep = BASE_TICKS_PER_STEP;
		return 1;
	}

}

void landPiece()
{
	unsigned const int (*currentPiece)[4][4] = &pieces[gameState.pieceType].blocks[gameState.pieceConfiguration];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			unsigned int blockValue = (*currentPiece)[j][i];

			if (blockValue)
			{
				unsigned int blockLeft = gameState.pieceLeft + i;
				unsigned int blockTop = gameState.pieceTop + j;

				gameState.grid[blockTop][blockLeft] = blockValue;
			}
		}
	}

	if(!newPiece())
		gameOver();

	reduce();

}

void reduce()
{
	for (int j = GAME_GRID_HEIGHT-1; j >= 0; j--)
	{
		unsigned int lineIsFull = 1;

		for (int i = 0; i < GAME_GRID_WIDTH; i++)
		{
			if (gameState.grid[j][i])
				continue;

			lineIsFull = 0;
			break;
		}

		if (!lineIsFull)
			continue;

		reduceLine(j);
		reduce();
		break;
	}

	handleFalling();
}

void handleFalling()
{
	unsigned int linesFell = 0;

	for (int j = GAME_GRID_HEIGHT-1; j >= 0; j--)
	{
		unsigned int lineIsClear = 1;

		for (int i = 0; i < GAME_GRID_WIDTH; i++)
		{
			if (!gameState.grid[j][i])
				continue;

			lineIsClear = 0;
			break;
		}

		if (!lineIsClear)
			continue;

		fallLine(j);
	}
}

void fallLine(int lineTop)
{
	for (int i = 0; i < GAME_GRID_WIDTH; i++)
	{
		for (int j = lineTop - 1; j >= 0; j--)
		{
			gameState.grid[j+1][i] = gameState.grid[j][i];
			gameState.grid[j][i] = 0;
		}
	}
}

void reduceLine(int j)
{
	for (int i = 0; i < GAME_GRID_WIDTH; i++)
	{
		gameState.grid[j][i] = 0;
	}
}

void gameOver()
{
	gameState.gameOver = 1;
	gameState.gamePaused = 1;
}

void pause_unpause()
{
	if (gameState.gameOver)
	{
		initLogic();
		gameState.gamePaused = 0;
	}
	else
	{
		gameState.gamePaused = !gameState.gamePaused;
	}
}

void drop()
{
	gameState.ticksPerStep = 1;
}

void collapseLines(unsigned int lines[GAME_GRID_HEIGHT])
{
	int lineCount = 0;

	for (int j = 0; j <= GAME_GRID_HEIGHT; j++)
	{
		if (lines[j])
		{
			for (int i = 0; i < GAME_GRID_WIDTH; i++)
			{
				gameState.grid[j][i] = gameState.grid[j-1][i];
			}
		}
	}
}
