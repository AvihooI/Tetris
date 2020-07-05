//
// Created by Avihoo on 05/07/2020.
//

#ifndef TETRIS_PIECES_H
#define TETRIS_PIECES_H

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

piece pieces[7];

piece createZ();

piece createS();

piece createL();

piece createJ();

piece createT();

piece createI();

piece createO();

#endif //TETRIS_PIECES_H
