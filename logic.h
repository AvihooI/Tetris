//
// Created by Avihoo on 14/06/2020.
//

#ifndef TETRIS_LOGIC_H
#define TETRIS_LOGIC_H

#include "tetris.h"

#define PIECE_START_LEFT GAME_GRID_WIDTH/2 - 2
#define MAXIMAL_ROTATE_ATTEMPTS 3

struct game_state
{
	unsigned int grid[GAME_GRID_HEIGHT][GAME_GRID_WIDTH];

	int pieceLeft;
	int pieceTop;
	unsigned int pieceType;
	unsigned int pieceConfiguration;

	unsigned int gamePaused;
	unsigned int gameOver;
	unsigned int ticksPerStep;
	unsigned int current_tick;

} gameState;

typedef struct
{
	unsigned int blocks[4][4][4];
	unsigned int configurations;
} piece;

void pause_unpause();
void step();
void rotate(int attempts);
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

#endif //TETRIS_LOGIC_H
