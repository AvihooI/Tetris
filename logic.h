//
// Created by Avihoo on 14/06/2020.
//

#ifndef TETRIS_LOGIC_H
#define TETRIS_LOGIC_H

#include "tetris.h"
#include "pieces.h"
#include "randomizer.h"

#define PIECE_START_LEFT GAME_GRID_WIDTH/2 - 2

struct game_state
{
	unsigned int grid[GAME_GRID_HEIGHT][GAME_GRID_WIDTH];

	int pieceLeft;
	int pieceTop;
	unsigned int pieceType;
	unsigned int pieceConfiguration;

	unsigned int nextPieceType;

	unsigned int gamePaused;
	unsigned int gameOver;

	unsigned int ticksPerStep;
	unsigned int currentTick;

	unsigned int score;
	unsigned int level;
	unsigned int startingLevel;

	unsigned int linesToLevel;
	unsigned int lineCount;

	unsigned int lastGrid[GAME_GRID_HEIGHT][GAME_GRID_WIDTH];
	unsigned int reducedLines[GAME_GRID_HEIGHT];
	unsigned int reducedLinesCount;

} gameState;

typedef enum
{
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_DOWN,
	ROTATE_CLOCKWISE,
	ROTATE_COUNTER_CLOCKWISE,
	TICK,
	DROP
} tetrisAction;

void update(unsigned int reducedLines);

void levelUp();

void updateScore(unsigned int lines);

void createPieces();

void pause_unpause();

void step();

void rotate(unsigned int clockwise);

void left();

void right();

void drop();

void tick();

void clearGrid();

unsigned int newPiece();

void landPiece();

void initLogic();

void gameOver();

void doAction(tetrisAction action);

void newGame();

/*Game Events*/
typedef void (*gameEvent)(void);

struct
{
	gameEvent rotate;
	gameEvent movement;
	gameEvent pieceLanded;
	gameEvent lineCleared;
	gameEvent tetris;
	gameEvent levelUp;
	gameEvent gameOver;
} gameEvents;

#endif //TETRIS_LOGIC_H
