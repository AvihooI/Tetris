//
// Created by Avihoo on 14/06/2020.
//

#include "logic.h"


unsigned int checkLines(unsigned int lines[GAME_GRID_HEIGHT]);

void collapseLines(const unsigned int lines[GAME_GRID_HEIGHT]);

void collapseLine(unsigned int k);

void copyGrid();

unsigned int levelTicks[MAX_LEVEL];

void initLevelTicks()
{
	levelTicks[0] = BASE_MILLISECONDS_PER_STEP / MILLISECONDS_PER_LOGIC_TICK;

	for (int i = 1; i < MAX_LEVEL; i++)
	{
		levelTicks[i] = (levelTicks[i - 1] * SPEED_GROWTH_RATE_DENOMINATOR) / SPEED_GROWTH_RATE_NUMERATOR;
	}
}

void initLogic()
{
	createPieces();

	initLevelTicks();

	gameState.startingLevel = 0;

	newGame();
}

void newGame()
{
	gameState.gamePaused = 1;
	gameState.gameOver = 0;

	gameState.currentTick = 0;
	gameState.pieceType = 7;

	gameState.lineCount = 0;
	gameState.pieceConfiguration = 0;
	gameState.linesToLevel = BASE_LINES_TO_LEVEL_UP;
	gameState.level = gameState.startingLevel;
	gameState.score = 0;

	gameState.reducedLinesCount = 0;

	initRandomizer();

	update(0);

	clearGrid();

	gameState.nextPieceType = getNewPiece();
}

void update(unsigned int reducedLines)
{

	if (reducedLines)
	{
		gameState.lineCount += reducedLines;
		updateScore(reducedLines);

		if (gameState.lineCount >= gameState.linesToLevel)
		{
			levelUp();
		}
	}

	gameState.ticksPerStep = levelTicks[gameState.level];

}

void updateScore(unsigned int lines)
{
	if (lines == 4)
	{
		gameState.score += gameState.level * 8;
		return;
	}

	gameState.score += (gameState.level + 1) * lines;
}

void levelUp()
{
	gameState.lineCount = 0;
	gameState.linesToLevel =
			(gameState.linesToLevel * LINES_TO_LEVEL_GROWTH_NUMERATOR) / LINES_TO_LEVEL_GROWTH_DENOMINATOR;

	if (gameState.level >= MAX_LEVEL - 1)
	{
		return;
	}

	gameState.level++;

	if (gameEvents.levelUp)
	{
		gameEvents.levelUp();
	}
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
	unsigned int (*currentPiece)[4][4] = &pieces[pieceType].blocks[pieceConfiguration];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((*currentPiece)[j][i])
			{
				int blockLeft = pieceLeft + i;
				int blockTop = pieceTop + j;

				/*Check out of bounds*/
				if (blockLeft < 0 || blockLeft >= GAME_GRID_WIDTH)
				{
					return 0;
				}

				if (blockTop < 0 || blockTop >= GAME_GRID_HEIGHT)
				{
					return 0;
				}

				/*Check grid collision*/
				if (gameState.grid[blockTop][blockLeft])
				{
					return 0;
				}
			}
		}
	}

	return 1;
}

void rotate(unsigned int clockwise)
{
	unsigned int previousConfiguration = gameState.pieceConfiguration;

	unsigned int nextConfiguration =
			(gameState.pieceConfiguration + ((int) clockwise * 2 - 1)) % pieces[gameState.pieceType].configurations;

	for (int i = 0; i < 5; i++)
	{
		int correctLeft = pieces[gameState.pieceType].wallKicks[gameState.pieceConfiguration][nextConfiguration][i].correctLeft;
		int correctTop = -pieces[gameState.pieceType].wallKicks[gameState.pieceConfiguration][nextConfiguration][i].correctTop;

		if (tryPiecePlacement(gameState.pieceLeft + correctLeft, gameState.pieceTop + correctTop, gameState.pieceType,
		                      nextConfiguration))
		{
			break;
		}
	}

	if (previousConfiguration != gameState.pieceConfiguration)
	{
		if (gameEvents.rotate)
		{
			gameEvents.rotate();
		}
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
	{
		step();
	}
}

void step()
{
	if (gameEvents.movement)
	{
		gameEvents.movement();
	}

	gameState.currentTick = 0;

	if (gameState.pieceType >= 7)
	{
		newPiece();
	}

	if (!tryPiecePlacement(gameState.pieceLeft, gameState.pieceTop + 1, gameState.pieceType,
	                       gameState.pieceConfiguration))
	{
		landPiece();
	}
}

unsigned int newPiece()
{
	unsigned int pieceType = gameState.nextPieceType;
	gameState.nextPieceType = getNewPiece();

	int tryTop;

	for (tryTop = -3; tryTop <= 0; tryTop++)
	{
		if (verifyPiecePlacement(PIECE_START_LEFT + pieces[pieceType].correctLeft, tryTop, pieceType, 0))
		{
			break;
		}
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

		return 1;
	}

}

void landPiece()
{
	unsigned int (*currentPiece)[4][4] = &pieces[gameState.pieceType].blocks[gameState.pieceConfiguration];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			unsigned int blockValue = (*currentPiece)[j][i];

			if (blockValue)
			{
				int blockLeft = gameState.pieceLeft + i;
				int blockTop = gameState.pieceTop + j;

				gameState.grid[blockTop][blockLeft] = blockValue;
			}
		}
	}

	gameState.reducedLinesCount = checkLines(gameState.reducedLines);

	if (gameEvents.pieceLanded)
	{
		gameEvents.pieceLanded();
	}

	if (gameState.reducedLinesCount)
	{
		copyGrid();
		collapseLines(gameState.reducedLines);
	}

	if (!newPiece())
	{
		gameOver();
	}
	else
	{
		update(gameState.reducedLinesCount);
	}

}

void copyGrid()
{
	for (unsigned int j = 0; j < GAME_GRID_HEIGHT; j++)
	{
		for (unsigned int i = 0; i < GAME_GRID_WIDTH; i++)
		{
			gameState.lastGrid[j][i] = gameState.grid[j][i];
		}
	}
}

unsigned int checkLine(unsigned int line)
{
	for (int i = 0; i < GAME_GRID_WIDTH; i++)
	{
		if (!gameState.grid[line][i])
		{
			return 0;
		}
	}

	return 1;
}

unsigned int checkLines(unsigned int lines[GAME_GRID_HEIGHT])
{
	unsigned int result = 0;

	for (unsigned int j = 0; j < GAME_GRID_HEIGHT; j++)
	{
		lines[j] = checkLine(j);

		result = result + lines[j];
	}

	return result;
}

void collapseLines(const unsigned int lines[GAME_GRID_HEIGHT])
{
	unsigned int lineCount = 0;

	for (unsigned int j = 0; j < GAME_GRID_HEIGHT; j++)
	{
		if (lines[j])
		{
			lineCount++;
			collapseLine(j);
		}
	}

	if (lineCount == 4)
	{
		if (gameEvents.tetris)
		{
			gameEvents.tetris();
		}
	}
	else if (lineCount > 0)
	{
		if (gameEvents.lineCleared)
		{
			gameEvents.lineCleared();
		}
	}
}

void collapseLine(unsigned int k)
{
	for (unsigned int j = k; j > 0; j--)
	{
		for (int i = 0; i < GAME_GRID_WIDTH; i++)
		{
			gameState.grid[j][i] = gameState.grid[j - 1][i];
		}
	}

	for (int i = 0; i < GAME_GRID_WIDTH; i++)
	{
		gameState.grid[0][i] = 0;
	}
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

void gameOver()
{
	gameState.gameOver = 1;
	gameState.gamePaused = 1;

	if (gameEvents.gameOver)
	{
		gameOver();
	}
}

void pauseUnpause()
{
	if (gameState.gameOver)
	{
		newGame();
		gameState.gamePaused = 0;
	}
	else
	{
		gameState.gamePaused = (unsigned int) !gameState.gamePaused;
	}
}

void drop()
{
	gameState.ticksPerStep = 1;
}

void doAction(tetrisAction action)
{
	if (gameState.gamePaused)
	{
		return;
	}

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
		default:
			break;
	}
}

