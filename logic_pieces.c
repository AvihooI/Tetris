//
// Created by Avihoo on 16/06/2020.
//

#include "logic.h"

void CreateIWallKicks(wallKick wallKicks[4][4][5]);

void CreateJLSTZWallKicks(wallKick wallKicks[4][4][5]);

void createPieces()
{
	pieces[0] = createO();
	pieces[1] = createI();
	pieces[2] = createT();
	pieces[3] = createJ();
	pieces[4] = createL();
	pieces[5] = createS();
	pieces[6] = createZ();
}

piece createZ()
{
	piece result;

	result.configurations = 4;

	/*Configuration 1*/
	result.blocks[0][0][0] = 3;
	result.blocks[0][0][1] = 3;
	result.blocks[0][0][2] = 0;
	result.blocks[0][0][3] = 0;
	result.blocks[0][1][0] = 0;
	result.blocks[0][1][1] = 3;
	result.blocks[0][1][2] = 3;
	result.blocks[0][1][3] = 0;
	result.blocks[0][2][0] = 0;
	result.blocks[0][2][1] = 0;
	result.blocks[0][2][2] = 0;
	result.blocks[0][2][3] = 0;
	result.blocks[0][3][0] = 0;
	result.blocks[0][3][1] = 0;
	result.blocks[0][3][2] = 0;
	result.blocks[0][3][3] = 0;

	/*Configuration 2*/
	result.blocks[1][0][0] = 0;
	result.blocks[1][0][1] = 0;
	result.blocks[1][0][2] = 3;
	result.blocks[1][0][3] = 0;
	result.blocks[1][1][0] = 0;
	result.blocks[1][1][1] = 3;
	result.blocks[1][1][2] = 3;
	result.blocks[1][1][3] = 0;
	result.blocks[1][2][0] = 0;
	result.blocks[1][2][1] = 3;
	result.blocks[1][2][2] = 0;
	result.blocks[1][2][3] = 0;
	result.blocks[1][3][0] = 0;
	result.blocks[1][3][1] = 0;
	result.blocks[1][3][2] = 0;
	result.blocks[1][3][3] = 0;

	/*Configuration 3*/
	result.blocks[2][0][0] = 0;
	result.blocks[2][0][1] = 0;
	result.blocks[2][0][2] = 0;
	result.blocks[2][0][3] = 0;
	result.blocks[2][1][0] = 3;
	result.blocks[2][1][1] = 3;
	result.blocks[2][1][2] = 0;
	result.blocks[2][1][3] = 0;
	result.blocks[2][2][0] = 0;
	result.blocks[2][2][1] = 3;
	result.blocks[2][2][2] = 3;
	result.blocks[2][2][3] = 0;
	result.blocks[2][3][0] = 0;
	result.blocks[2][3][1] = 0;
	result.blocks[2][3][2] = 0;
	result.blocks[2][3][3] = 0;

	/*Configuration 4*/
	result.blocks[3][0][0] = 0;
	result.blocks[3][0][1] = 3;
	result.blocks[3][0][2] = 0;
	result.blocks[3][0][3] = 0;
	result.blocks[3][1][0] = 3;
	result.blocks[3][1][1] = 3;
	result.blocks[3][1][2] = 0;
	result.blocks[3][1][3] = 0;
	result.blocks[3][2][0] = 3;
	result.blocks[3][2][1] = 0;
	result.blocks[3][2][2] = 0;
	result.blocks[3][2][3] = 0;
	result.blocks[3][3][0] = 0;
	result.blocks[3][3][1] = 0;
	result.blocks[3][3][2] = 0;
	result.blocks[3][3][3] = 0;

	CreateJLSTZWallKicks(result.wallKicks);

	result.correctLeft = 0;
	result.correctTop = 1;

	return result;
}

piece createS()
{
	piece result;

	result.configurations = 4;

	/*Configuration 1*/
	result.blocks[0][0][0] = 0;
	result.blocks[0][0][1] = 4;
	result.blocks[0][0][2] = 4;
	result.blocks[0][0][3] = 0;
	result.blocks[0][1][0] = 4;
	result.blocks[0][1][1] = 4;
	result.blocks[0][1][2] = 0;
	result.blocks[0][1][3] = 0;
	result.blocks[0][2][0] = 0;
	result.blocks[0][2][1] = 0;
	result.blocks[0][2][2] = 0;
	result.blocks[0][2][3] = 0;
	result.blocks[0][3][0] = 0;
	result.blocks[0][3][1] = 0;
	result.blocks[0][3][2] = 0;
	result.blocks[0][3][3] = 0;

	/*Configuration 2*/
	result.blocks[1][0][0] = 0;
	result.blocks[1][0][1] = 4;
	result.blocks[1][0][2] = 0;
	result.blocks[1][0][3] = 0;
	result.blocks[1][1][0] = 0;
	result.blocks[1][1][1] = 4;
	result.blocks[1][1][2] = 4;
	result.blocks[1][1][3] = 0;
	result.blocks[1][2][0] = 0;
	result.blocks[1][2][1] = 0;
	result.blocks[1][2][2] = 4;
	result.blocks[1][2][3] = 0;
	result.blocks[1][3][0] = 0;
	result.blocks[1][3][1] = 0;
	result.blocks[1][3][2] = 0;
	result.blocks[1][3][3] = 0;

	/*Configuration 3*/
	result.blocks[2][0][0] = 0;
	result.blocks[2][0][1] = 0;
	result.blocks[2][0][2] = 0;
	result.blocks[2][0][3] = 0;
	result.blocks[2][1][0] = 0;
	result.blocks[2][1][1] = 4;
	result.blocks[2][1][2] = 4;
	result.blocks[2][1][3] = 0;
	result.blocks[2][2][0] = 4;
	result.blocks[2][2][1] = 4;
	result.blocks[2][2][2] = 0;
	result.blocks[2][2][3] = 0;
	result.blocks[2][3][0] = 0;
	result.blocks[2][3][1] = 0;
	result.blocks[2][3][2] = 0;
	result.blocks[2][3][3] = 0;

	/*Configuration 4*/
	result.blocks[3][0][0] = 4;
	result.blocks[3][0][1] = 0;
	result.blocks[3][0][2] = 0;
	result.blocks[3][0][3] = 0;
	result.blocks[3][1][0] = 4;
	result.blocks[3][1][1] = 4;
	result.blocks[3][1][2] = 0;
	result.blocks[3][1][3] = 0;
	result.blocks[3][2][0] = 0;
	result.blocks[3][2][1] = 4;
	result.blocks[3][2][2] = 0;
	result.blocks[3][2][3] = 0;
	result.blocks[3][3][0] = 0;
	result.blocks[3][3][1] = 0;
	result.blocks[3][3][2] = 0;
	result.blocks[3][3][3] = 0;

	CreateJLSTZWallKicks(result.wallKicks);

	result.correctLeft = 0;
	result.correctTop = 1;

	return result;
}

piece createL()
{
	piece result;

	result.configurations = 4;

	/*Configuration 1*/
	result.blocks[0][0][0] = 0;
	result.blocks[0][0][1] = 0;
	result.blocks[0][0][2] = 5;
	result.blocks[0][0][3] = 0;
	result.blocks[0][1][0] = 5;
	result.blocks[0][1][1] = 5;
	result.blocks[0][1][2] = 5;
	result.blocks[0][1][3] = 0;
	result.blocks[0][2][0] = 0;
	result.blocks[0][2][1] = 0;
	result.blocks[0][2][2] = 0;
	result.blocks[0][2][3] = 0;
	result.blocks[0][3][0] = 0;
	result.blocks[0][3][1] = 0;
	result.blocks[0][3][2] = 0;
	result.blocks[0][3][3] = 0;

	/*Configuration 2*/
	result.blocks[1][0][0] = 0;
	result.blocks[1][0][1] = 5;
	result.blocks[1][0][2] = 0;
	result.blocks[1][0][3] = 0;
	result.blocks[1][1][0] = 0;
	result.blocks[1][1][1] = 5;
	result.blocks[1][1][2] = 0;
	result.blocks[1][1][3] = 0;
	result.blocks[1][2][0] = 0;
	result.blocks[1][2][1] = 5;
	result.blocks[1][2][2] = 5;
	result.blocks[1][2][3] = 0;
	result.blocks[1][3][0] = 0;
	result.blocks[1][3][1] = 0;
	result.blocks[1][3][2] = 0;
	result.blocks[1][3][3] = 0;

	/*Configuration 3*/
	result.blocks[2][0][0] = 0;
	result.blocks[2][0][1] = 0;
	result.blocks[2][0][2] = 0;
	result.blocks[2][0][3] = 0;
	result.blocks[2][1][0] = 5;
	result.blocks[2][1][1] = 5;
	result.blocks[2][1][2] = 5;
	result.blocks[2][1][3] = 0;
	result.blocks[2][2][0] = 5;
	result.blocks[2][2][1] = 0;
	result.blocks[2][2][2] = 0;
	result.blocks[2][2][3] = 0;
	result.blocks[2][3][0] = 0;
	result.blocks[2][3][1] = 0;
	result.blocks[2][3][2] = 0;
	result.blocks[2][3][3] = 0;

	/*Configuration 4*/
	result.blocks[3][0][0] = 5;
	result.blocks[3][0][1] = 5;
	result.blocks[3][0][2] = 0;
	result.blocks[3][0][3] = 0;
	result.blocks[3][1][0] = 0;
	result.blocks[3][1][1] = 5;
	result.blocks[3][1][2] = 0;
	result.blocks[3][1][3] = 0;
	result.blocks[3][2][0] = 0;
	result.blocks[3][2][1] = 5;
	result.blocks[3][2][2] = 0;
	result.blocks[3][2][3] = 0;
	result.blocks[3][3][0] = 0;
	result.blocks[3][3][1] = 0;
	result.blocks[3][3][2] = 0;
	result.blocks[3][3][3] = 0;

	CreateJLSTZWallKicks(result.wallKicks);

	result.correctLeft = 0;
	result.correctTop = 1;

	return result;
}

piece createJ()
{
	piece result;

	result.configurations = 4;

	/*Configuration 1*/
	result.blocks[0][0][0] = 6;
	result.blocks[0][0][1] = 0;
	result.blocks[0][0][2] = 0;
	result.blocks[0][0][3] = 0;
	result.blocks[0][1][0] = 6;
	result.blocks[0][1][1] = 6;
	result.blocks[0][1][2] = 6;
	result.blocks[0][1][3] = 0;
	result.blocks[0][2][0] = 0;
	result.blocks[0][2][1] = 0;
	result.blocks[0][2][2] = 0;
	result.blocks[0][2][3] = 0;
	result.blocks[0][3][0] = 0;
	result.blocks[0][3][1] = 0;
	result.blocks[0][3][2] = 0;
	result.blocks[0][3][3] = 0;

	/*Configuration 2*/
	result.blocks[1][0][0] = 0;
	result.blocks[1][0][1] = 6;
	result.blocks[1][0][2] = 6;
	result.blocks[1][0][3] = 0;
	result.blocks[1][1][0] = 0;
	result.blocks[1][1][1] = 6;
	result.blocks[1][1][2] = 0;
	result.blocks[1][1][3] = 0;
	result.blocks[1][2][0] = 0;
	result.blocks[1][2][1] = 6;
	result.blocks[1][2][2] = 0;
	result.blocks[1][2][3] = 0;
	result.blocks[1][3][0] = 0;
	result.blocks[1][3][1] = 0;
	result.blocks[1][3][2] = 0;
	result.blocks[1][3][3] = 0;

	/*Configuration 3*/
	result.blocks[2][0][0] = 0;
	result.blocks[2][0][1] = 0;
	result.blocks[2][0][2] = 0;
	result.blocks[2][0][3] = 0;
	result.blocks[2][1][0] = 6;
	result.blocks[2][1][1] = 6;
	result.blocks[2][1][2] = 6;
	result.blocks[2][1][3] = 0;
	result.blocks[2][2][0] = 0;
	result.blocks[2][2][1] = 0;
	result.blocks[2][2][2] = 6;
	result.blocks[2][2][3] = 0;
	result.blocks[2][3][0] = 0;
	result.blocks[2][3][1] = 0;
	result.blocks[2][3][2] = 0;
	result.blocks[2][3][3] = 0;

	/*Configuration 4*/
	result.blocks[3][0][0] = 0;
	result.blocks[3][0][1] = 6;
	result.blocks[3][0][2] = 0;
	result.blocks[3][0][3] = 0;
	result.blocks[3][1][0] = 0;
	result.blocks[3][1][1] = 6;
	result.blocks[3][1][2] = 0;
	result.blocks[3][1][3] = 0;
	result.blocks[3][2][0] = 6;
	result.blocks[3][2][1] = 6;
	result.blocks[3][2][2] = 0;
	result.blocks[3][2][3] = 0;
	result.blocks[3][3][0] = 0;
	result.blocks[3][3][1] = 0;
	result.blocks[3][3][2] = 0;
	result.blocks[3][3][3] = 0;

	CreateJLSTZWallKicks(result.wallKicks);

	result.correctLeft = 0;
	result.correctTop = 1;

	return result;
}

piece createT()
{
	piece result;

	result.configurations = 4;

	/*Configuration 1*/
	result.blocks[0][0][0] = 0;
	result.blocks[0][0][1] = 7;
	result.blocks[0][0][2] = 0;
	result.blocks[0][0][3] = 0;
	result.blocks[0][1][0] = 7;
	result.blocks[0][1][1] = 7;
	result.blocks[0][1][2] = 7;
	result.blocks[0][1][3] = 0;
	result.blocks[0][2][0] = 0;
	result.blocks[0][2][1] = 0;
	result.blocks[0][2][2] = 0;
	result.blocks[0][2][3] = 0;
	result.blocks[0][3][0] = 0;
	result.blocks[0][3][1] = 0;
	result.blocks[0][3][2] = 0;
	result.blocks[0][3][3] = 0;

	/*Configuration 2*/
	result.blocks[1][0][0] = 0;
	result.blocks[1][0][1] = 7;
	result.blocks[1][0][2] = 0;
	result.blocks[1][0][3] = 0;
	result.blocks[1][1][0] = 0;
	result.blocks[1][1][1] = 7;
	result.blocks[1][1][2] = 7;
	result.blocks[1][1][3] = 0;
	result.blocks[1][2][0] = 0;
	result.blocks[1][2][1] = 7;
	result.blocks[1][2][2] = 0;
	result.blocks[1][2][3] = 0;
	result.blocks[1][3][0] = 0;
	result.blocks[1][3][1] = 0;
	result.blocks[1][3][2] = 0;
	result.blocks[1][3][3] = 0;

	/*Configuration 3*/
	result.blocks[2][0][0] = 0;
	result.blocks[2][0][1] = 0;
	result.blocks[2][0][2] = 0;
	result.blocks[2][0][3] = 0;
	result.blocks[2][1][0] = 7;
	result.blocks[2][1][1] = 7;
	result.blocks[2][1][2] = 7;
	result.blocks[2][1][3] = 0;
	result.blocks[2][2][0] = 0;
	result.blocks[2][2][1] = 7;
	result.blocks[2][2][2] = 0;
	result.blocks[2][2][3] = 0;
	result.blocks[2][3][0] = 0;
	result.blocks[2][3][1] = 0;
	result.blocks[2][3][2] = 0;
	result.blocks[2][3][3] = 0;

	/*Configuration 4*/
	result.blocks[3][0][0] = 0;
	result.blocks[3][0][1] = 7;
	result.blocks[3][0][2] = 0;
	result.blocks[3][0][3] = 0;
	result.blocks[3][1][0] = 7;
	result.blocks[3][1][1] = 7;
	result.blocks[3][1][2] = 0;
	result.blocks[3][1][3] = 0;
	result.blocks[3][2][0] = 0;
	result.blocks[3][2][1] = 7;
	result.blocks[3][2][2] = 0;
	result.blocks[3][2][3] = 0;
	result.blocks[3][3][0] = 0;
	result.blocks[3][3][1] = 0;
	result.blocks[3][3][2] = 0;
	result.blocks[3][3][3] = 0;

	CreateJLSTZWallKicks(result.wallKicks);

	result.correctLeft = 0;
	result.correctTop = 1;

	return result;
}

piece createI()
{
	piece result;

	result.configurations = 4;

	/*Configuration 1*/
	result.blocks[0][0][0] = 0;
	result.blocks[0][0][1] = 0;
	result.blocks[0][0][2] = 0;
	result.blocks[0][0][3] = 0;
	result.blocks[0][1][0] = 8;
	result.blocks[0][1][1] = 8;
	result.blocks[0][1][2] = 8;
	result.blocks[0][1][3] = 8;
	result.blocks[0][2][0] = 0;
	result.blocks[0][2][1] = 0;
	result.blocks[0][2][2] = 0;
	result.blocks[0][2][3] = 0;
	result.blocks[0][3][0] = 0;
	result.blocks[0][3][1] = 0;
	result.blocks[0][3][2] = 0;
	result.blocks[0][3][3] = 0;

	/*Configuration 2*/
	result.blocks[1][0][0] = 0;
	result.blocks[1][0][1] = 0;
	result.blocks[1][0][2] = 8;
	result.blocks[1][0][3] = 0;
	result.blocks[1][1][0] = 0;
	result.blocks[1][1][1] = 0;
	result.blocks[1][1][2] = 8;
	result.blocks[1][1][3] = 0;
	result.blocks[1][2][0] = 0;
	result.blocks[1][2][1] = 0;
	result.blocks[1][2][2] = 8;
	result.blocks[1][2][3] = 0;
	result.blocks[1][3][0] = 0;
	result.blocks[1][3][1] = 0;
	result.blocks[1][3][2] = 8;
	result.blocks[1][3][3] = 0;

	/*Configuration 3*/
	result.blocks[2][0][0] = 0;
	result.blocks[2][0][1] = 0;
	result.blocks[2][0][2] = 0;
	result.blocks[2][0][3] = 0;
	result.blocks[2][1][0] = 0;
	result.blocks[2][1][1] = 0;
	result.blocks[2][1][2] = 0;
	result.blocks[2][1][3] = 0;
	result.blocks[2][2][0] = 8;
	result.blocks[2][2][1] = 8;
	result.blocks[2][2][2] = 8;
	result.blocks[2][2][3] = 8;
	result.blocks[2][3][0] = 0;
	result.blocks[2][3][1] = 0;
	result.blocks[2][3][2] = 0;
	result.blocks[2][3][3] = 0;

	/*Configuration 4*/
	result.blocks[3][0][0] = 0;
	result.blocks[3][0][1] = 8;
	result.blocks[3][0][2] = 0;
	result.blocks[3][0][3] = 0;
	result.blocks[3][1][0] = 0;
	result.blocks[3][1][1] = 8;
	result.blocks[3][1][2] = 0;
	result.blocks[3][1][3] = 0;
	result.blocks[3][2][0] = 0;
	result.blocks[3][2][1] = 8;
	result.blocks[3][2][2] = 0;
	result.blocks[3][2][3] = 0;
	result.blocks[3][3][0] = 0;
	result.blocks[3][3][1] = 8;
	result.blocks[3][3][2] = 0;
	result.blocks[3][3][3] = 0;

	CreateIWallKicks(result.wallKicks);

	result.correctLeft = 0;
	result.correctTop = 0;

	return result;
}

piece createO()
{
	piece result;

	result.configurations = 1;

	/*Configuration 1*/
	result.blocks[0][0][0] = 0;
	result.blocks[0][0][1] = 9;
	result.blocks[0][0][2] = 9;
	result.blocks[0][0][3] = 0;
	result.blocks[0][1][0] = 0;
	result.blocks[0][1][1] = 9;
	result.blocks[0][1][2] = 9;
	result.blocks[0][1][3] = 0;
	result.blocks[0][2][0] = 0;
	result.blocks[0][2][1] = 0;
	result.blocks[0][2][2] = 0;
	result.blocks[0][2][3] = 0;
	result.blocks[0][3][0] = 0;
	result.blocks[0][3][1] = 0;
	result.blocks[0][3][2] = 0;
	result.blocks[0][3][3] = 0;

	result.correctLeft = 0;
	result.correctTop = 1;

	return result;
}

void CreateIWallKicks(wallKick wallKicks[4][4][5])
{
	/*0>>1*/
	wallKicks[0][1][0].correctLeft = 0;
	wallKicks[0][1][0].correctTop = 0;

	wallKicks[0][1][1].correctLeft = -2;
	wallKicks[0][1][1].correctTop = 0;

	wallKicks[0][1][2].correctLeft = 1;
	wallKicks[0][1][2].correctTop = 0;

	wallKicks[0][1][3].correctLeft = -2;
	wallKicks[0][1][3].correctTop = -1;

	wallKicks[0][1][4].correctLeft = 1;
	wallKicks[0][1][4].correctTop = 2;

	/*1>>0*/
	wallKicks[1][0][0].correctLeft = 0;
	wallKicks[1][0][0].correctTop = 0;

	wallKicks[1][0][1].correctLeft = 2;
	wallKicks[1][0][1].correctTop = 0;

	wallKicks[1][0][2].correctLeft = -1;
	wallKicks[1][0][2].correctTop = 0;

	wallKicks[1][0][3].correctLeft = 2;
	wallKicks[1][0][3].correctTop = 1;

	wallKicks[1][0][4].correctLeft = -1;
	wallKicks[1][0][4].correctTop = -2;

	/*1>>2*/
	wallKicks[1][2][0].correctLeft = 0;
	wallKicks[1][2][0].correctTop = 0;

	wallKicks[1][2][1].correctLeft = -1;
	wallKicks[1][2][1].correctTop = 0;

	wallKicks[1][2][2].correctLeft = 2;
	wallKicks[1][2][2].correctTop = 0;

	wallKicks[1][2][3].correctLeft = -1;
	wallKicks[1][2][3].correctTop = 2;

	wallKicks[1][2][4].correctLeft = 2;
	wallKicks[1][2][4].correctTop = -1;

	/*2>>1*/
	wallKicks[2][1][0].correctLeft = 0;
	wallKicks[2][1][0].correctTop = 0;

	wallKicks[2][1][1].correctLeft = 1;
	wallKicks[2][1][1].correctTop = 0;

	wallKicks[2][1][2].correctLeft = -2;
	wallKicks[2][1][2].correctTop = 0;

	wallKicks[2][1][3].correctLeft = 1;
	wallKicks[2][1][3].correctTop = -2;

	wallKicks[2][1][4].correctLeft = -2;
	wallKicks[2][1][4].correctTop = 1;

	/*2>>3*/
	wallKicks[2][3][0].correctLeft = 0;
	wallKicks[2][3][0].correctTop = 0;

	wallKicks[2][3][1].correctLeft = 2;
	wallKicks[2][3][1].correctTop = 0;

	wallKicks[2][3][2].correctLeft = -1;
	wallKicks[2][3][2].correctTop = 0;

	wallKicks[2][3][3].correctLeft = 2;
	wallKicks[2][3][3].correctTop = 1;

	wallKicks[2][3][4].correctLeft = -1;
	wallKicks[2][3][4].correctTop = -2;

	/*3>>2*/
	wallKicks[3][2][0].correctLeft = 0;
	wallKicks[3][2][0].correctTop = 0;

	wallKicks[3][2][1].correctLeft = -2;
	wallKicks[3][2][1].correctTop = 0;

	wallKicks[3][2][2].correctLeft = 1;
	wallKicks[3][2][2].correctTop = 0;

	wallKicks[3][2][3].correctLeft = -2;
	wallKicks[3][2][3].correctTop = -1;

	wallKicks[3][2][4].correctLeft = 1;
	wallKicks[3][2][4].correctTop = 2;

	/*3>>0*/
	wallKicks[3][0][0].correctLeft = 0;
	wallKicks[3][0][0].correctTop = 0;

	wallKicks[3][0][1].correctLeft = 1;
	wallKicks[3][0][1].correctTop = 0;

	wallKicks[3][0][2].correctLeft = -2;
	wallKicks[3][0][2].correctTop = 0;

	wallKicks[3][0][3].correctLeft = 1;
	wallKicks[3][0][3].correctTop = -2;

	wallKicks[3][0][4].correctLeft = -2;
	wallKicks[3][0][4].correctTop = 1;

	/*0>>3*/
	wallKicks[0][3][0].correctLeft = 0;
	wallKicks[0][3][0].correctTop = 0;

	wallKicks[0][3][1].correctLeft = -1;
	wallKicks[0][3][1].correctTop = 0;

	wallKicks[0][3][2].correctLeft = 2;
	wallKicks[0][3][2].correctTop = 0;

	wallKicks[0][3][3].correctLeft = -1;
	wallKicks[0][3][3].correctTop = 2;

	wallKicks[0][3][4].correctLeft = 2;
	wallKicks[0][3][4].correctTop = -1;
}

void CreateJLSTZWallKicks(wallKick wallKicks[4][4][5])
{
	/*0>>1*/
	wallKicks[0][1][0].correctLeft = 0;
	wallKicks[0][1][0].correctTop = 0;

	wallKicks[0][1][1].correctLeft = -1;
	wallKicks[0][1][1].correctTop = 0;

	wallKicks[0][1][2].correctLeft = -1;
	wallKicks[0][1][2].correctTop = 1;

	wallKicks[0][1][3].correctLeft = 0;
	wallKicks[0][1][3].correctTop = -2;

	wallKicks[0][1][4].correctLeft = -1;
	wallKicks[0][1][4].correctTop = -2;

	/*1>>0*/
	wallKicks[1][0][0].correctLeft = 0;
	wallKicks[1][0][0].correctTop = 0;

	wallKicks[1][0][1].correctLeft = 1;
	wallKicks[1][0][1].correctTop = 0;

	wallKicks[1][0][2].correctLeft = 1;
	wallKicks[1][0][2].correctTop = -1;

	wallKicks[1][0][3].correctLeft = 0;
	wallKicks[1][0][3].correctTop = 2;

	wallKicks[1][0][4].correctLeft = 1;
	wallKicks[1][0][4].correctTop = 2;

	/*1>>2*/
	wallKicks[1][2][0].correctLeft = 0;
	wallKicks[1][2][0].correctTop = 0;

	wallKicks[1][2][1].correctLeft = 1;
	wallKicks[1][2][1].correctTop = 0;

	wallKicks[1][2][2].correctLeft = 1;
	wallKicks[1][2][2].correctTop = -1;

	wallKicks[1][2][3].correctLeft = 0;
	wallKicks[1][2][3].correctTop = 2;

	wallKicks[1][2][4].correctLeft = 1;
	wallKicks[1][2][4].correctTop = 2;

	/*2>>1*/
	wallKicks[2][1][0].correctLeft = 0;
	wallKicks[2][1][0].correctTop = 0;

	wallKicks[2][1][1].correctLeft = -1;
	wallKicks[2][1][1].correctTop = 0;

	wallKicks[2][1][2].correctLeft = -1;
	wallKicks[2][1][2].correctTop = 1;

	wallKicks[2][1][3].correctLeft = 0;
	wallKicks[2][1][3].correctTop = -2;

	wallKicks[2][1][4].correctLeft = -1;
	wallKicks[2][1][4].correctTop = -2;

	/*2>>3*/
	wallKicks[2][3][0].correctLeft = 0;
	wallKicks[2][3][0].correctTop = 0;

	wallKicks[2][3][1].correctLeft = 1;
	wallKicks[2][3][1].correctTop = 0;

	wallKicks[2][3][2].correctLeft = 1;
	wallKicks[2][3][2].correctTop = 1;

	wallKicks[2][3][3].correctLeft = 0;
	wallKicks[2][3][3].correctTop = -2;

	wallKicks[2][3][4].correctLeft = 1;
	wallKicks[2][3][4].correctTop = -2;

	/*3>>2*/
	wallKicks[3][2][0].correctLeft = 0;
	wallKicks[3][2][0].correctTop = 0;

	wallKicks[3][2][1].correctLeft = -1;
	wallKicks[3][2][1].correctTop = 0;

	wallKicks[3][2][2].correctLeft = -1;
	wallKicks[3][2][2].correctTop = -1;

	wallKicks[3][2][3].correctLeft = 0;
	wallKicks[3][2][3].correctTop = 2;

	wallKicks[3][2][4].correctLeft = -1;
	wallKicks[3][2][4].correctTop = 2;

	/*3>>0*/
	wallKicks[3][0][0].correctLeft = 0;
	wallKicks[3][0][0].correctTop = 0;

	wallKicks[3][0][1].correctLeft = -1;
	wallKicks[3][0][1].correctTop = 0;

	wallKicks[3][0][2].correctLeft = -1;
	wallKicks[3][0][2].correctTop = -1;

	wallKicks[3][0][3].correctLeft = 0;
	wallKicks[3][0][3].correctTop = 2;

	wallKicks[3][0][4].correctLeft = -1;
	wallKicks[3][0][4].correctTop = 2;

	/*0>>3*/
	wallKicks[0][3][0].correctLeft = 0;
	wallKicks[0][3][0].correctTop = 0;

	wallKicks[0][3][1].correctLeft = 1;
	wallKicks[0][3][1].correctTop = 0;

	wallKicks[0][3][2].correctLeft = 1;
	wallKicks[0][3][2].correctTop = 1;

	wallKicks[0][3][3].correctLeft = 0;
	wallKicks[0][3][3].correctTop = -2;

	wallKicks[0][3][4].correctLeft = 1;
	wallKicks[0][3][4].correctTop = -2;
}

