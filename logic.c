//
// Created by Avihoo on 14/06/2020.
//

#include "logic.h"
#include <stdlib.h>
#include <time.h>

unsigned int levelTicks[MAX_LEVEL] = {
		1000 / MILLISECONDS_PER_TICK,
		800 / MILLISECONDS_PER_TICK,
		640 / MILLISECONDS_PER_TICK,
		512 / MILLISECONDS_PER_TICK,
		409 / MILLISECONDS_PER_TICK,
		327 / MILLISECONDS_PER_TICK,
		262 / MILLISECONDS_PER_TICK,
		209 / MILLISECONDS_PER_TICK,
		167 / MILLISECONDS_PER_TICK,
		134 / MILLISECONDS_PER_TICK,
		107 / MILLISECONDS_PER_TICK,
		85 / MILLISECONDS_PER_TICK,
		68 / MILLISECONDS_PER_TICK,
		54 / MILLISECONDS_PER_TICK,
		43 / MILLISECONDS_PER_TICK,
		35 / MILLISECONDS_PER_TICK,
		28 / MILLISECONDS_PER_TICK,
		22 / MILLISECONDS_PER_TICK,
		14 / MILLISECONDS_PER_TICK,
		11 / MILLISECONDS_PER_TICK
};

void update();

void levelUp();

void updateScore(unsigned int lines);

void newGame();

void createPieces();

void initLogic()
{
	createPieces();

	newGame();
}

void newGame()
{
	gameState.gamePaused = 1;
	gameState.gameOver = 0;

	gameState.currentTick = 0;
	gameState.pieceType = 7;

	gameState.reducedLines = 0;
	gameState.lineCount = 0;
	gameState.pieceConfiguration = 0;
	gameState.linesToLevel = 1;
	gameState.level = 1;
	gameState.score = 0;

	update();

	clearGrid();

	srand(time(0));

	gameState.nextPieceType = rand() % 7;
}

void update()
{

	if (gameState.reducedLines)
	{
		gameState.lineCount += gameState.reducedLines;
		updateScore(gameState.reducedLines);
		gameState.reducedLines = 0;
		if (gameState.lineCount >= gameState.linesToLevel)
			levelUp();
	}

	gameState.ticksPerStep = levelTicks[gameState.level - 1];

}

void updateScore(unsigned int lines)
{
	if (lines == 4)
	{
		gameState.score += gameState.level * 8;
		return;
	}

	gameState.score += gameState.level * lines;
}

void levelUp()
{
	gameState.lineCount = 0;

	if (gameState.level == MAX_LEVEL)
		return;


	gameState.linesToLevel *= 2;
	gameState.level++;
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
	if (verifyPiecePlacement(pieceLeft, pieceTop, pieceType, pieceConfiguration))
	{
		gameState.pieceLeft = pieceLeft;
		gameState.pieceTop = pieceTop;
		gameState.pieceType = pieceType;
		gameState.pieceConfiguration = pieceConfiguration;
		return 1;
	}

	return 0;
}

void rotate(unsigned int clockwise)
{

	unsigned int nextConfiguration =
			(gameState.pieceConfiguration + ((int) clockwise * 2 - 1)) % pieces[gameState.pieceType].configurations;

	for (int i = 0; i < 5; i++)
	{
		int correctLeft = pieces[gameState.pieceType].wallKicks[gameState.pieceConfiguration][nextConfiguration][i].correctLeft;
		int correctTop = -pieces[gameState.pieceType].wallKicks[gameState.pieceConfiguration][nextConfiguration][i].correctTop;

		if (tryPiecePlacement(gameState.pieceLeft + correctLeft, gameState.pieceTop + correctTop, gameState.pieceType,
		                      nextConfiguration))
			break;
	}

}

void left()
{
	tryPiecePlacement(gameState.pieceLeft - 1, gameState.pieceTop, gameState.pieceType, gameState.pieceConfiguration);
}

void right()
{
	tryPiecePlacement(gameState.pieceLeft + 1, gameState.pieceTop, gameState.pieceType, gameState.pieceConfiguration);
}

void tick()
{
	gameState.currentTick++;

	if (gameState.currentTick >= gameState.ticksPerStep)
		step();
}

void step()
{

	gameState.currentTick = 0;

	if (gameState.pieceType >= 7)
	{
		newPiece();
	}

	if (!tryPiecePlacement(gameState.pieceLeft, gameState.pieceTop + 1, gameState.pieceType,
	                       gameState.pieceConfiguration))
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
		if (verifyPiecePlacement(PIECE_START_LEFT + pieces[pieceType].correctLeft, tryTop, pieceType, 0))
			break;
	}

	if (tryTop == 1)
	{
		return 0;
	} else
	{
		gameState.pieceType = pieceType;
		gameState.pieceConfiguration = 0;
		gameState.pieceTop = tryTop;
		gameState.pieceLeft = PIECE_START_LEFT;

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

	if (!newPiece())
		gameOver();
	else
	{
		reduce();
		update();
	}

}

void reduce()
{
	for (int j = GAME_GRID_HEIGHT - 1; j >= 0; j--)
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

		gameState.reducedLines++;
		reduceLine(j);
		reduce();
		break;
	}

	handleFalling();
}

void handleFalling()
{

	for (int j = GAME_GRID_HEIGHT - 1; j >= 0; j--)
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
			gameState.grid[j + 1][i] = gameState.grid[j][i];
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
		newGame();
		gameState.gamePaused = 0;
	} else
	{
		gameState.gamePaused = !gameState.gamePaused;
	}
}

void drop()
{
	gameState.ticksPerStep = 1;
}

void doAction(tetrisAction action)
{
	if (gameState.gamePaused)
		return;

	switch (action)
	{

		case MOVE_LEFT:
			left();
			break;
		case MOVE_RIGHT:
			right();
			break;
		case MOVE_DOWN:
			step();
			break;
		case ROTATE_CLOCKWISE:
			rotate(1);
			break;
		case ROTATE_COUNTER_CLOCKWISE:
			rotate(0);
			break;
		case TICK:
			tick();
			break;
		case DROP:
			drop();
			break;
	}
}

