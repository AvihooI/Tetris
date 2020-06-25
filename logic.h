//
// Created by Avihoo on 14/06/2020.
//

#ifndef TETRIS_LOGIC_H
#define TETRIS_LOGIC_H

#include "tetris.h"

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
	unsigned int reducedLines;

} gameState;

typedef struct wallKick
{
	int correctLeft;
	int correctTop;
} wallKick;

typedef struct piece
{
	unsigned int blocks[4][4][4];
	unsigned int configurations;

	wallKick wallKicks[4][4][5];

	int correctLeft;
	int correctTop;
} piece;

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

void update();

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

piece pieces[7];

piece createO();

piece createI();

piece createT();

piece createJ();

piece createL();

piece createS();

piece createZ();

void initLogic();

void gameOver();

void reduce();

void reduceLine(int j);

void handleFalling();

void fallLine(int lineTop);

void doAction(tetrisAction action);

void newGame();

#endif //TETRIS_LOGIC_H
