//
// Created by Avihoo on 16/06/2020.
//

#include "logic.h"

piece createZ()
{
	piece result;

	result.configurations = 2;

	/*Configuration 1*/
	result.blocks[0][0][0] = 0;
	result.blocks[0][0][1] = 3;
	result.blocks[0][0][2] = 0;
	result.blocks[0][0][3] = 0;
	result.blocks[0][1][0] = 0;
	result.blocks[0][1][1] = 3;
	result.blocks[0][1][2] = 3;
	result.blocks[0][1][3] = 0;
	result.blocks[0][2][0] = 0;
	result.blocks[0][2][1] = 0;
	result.blocks[0][2][2] = 3;
	result.blocks[0][2][3] = 0;
	result.blocks[0][3][0] = 0;
	result.blocks[0][3][1] = 0;
	result.blocks[0][3][2] = 0;
	result.blocks[0][3][3] = 0;

	/*Configuration 2*/
	result.blocks[1][0][0] = 0;
	result.blocks[1][0][1] = 0;
	result.blocks[1][0][2] = 0;
	result.blocks[1][0][3] = 0;
	result.blocks[1][1][0] = 0;
	result.blocks[1][1][1] = 0;
	result.blocks[1][1][2] = 3;
	result.blocks[1][1][3] = 3;
	result.blocks[1][2][0] = 0;
	result.blocks[1][2][1] = 3;
	result.blocks[1][2][2] = 3;
	result.blocks[1][2][3] = 0;
	result.blocks[1][3][0] = 0;
	result.blocks[1][3][1] = 0;
	result.blocks[1][3][2] = 0;
	result.blocks[1][3][3] = 0;

	return result;
}

piece createS()
{
	piece result;

	result.configurations = 2;

	/*Configuration 1*/
	result.blocks[0][0][0] = 0;
	result.blocks[0][0][1] = 0;
	result.blocks[0][0][2] = 4;
	result.blocks[0][0][3] = 0;
	result.blocks[0][1][0] = 0;
	result.blocks[0][1][1] = 4;
	result.blocks[0][1][2] = 4;
	result.blocks[0][1][3] = 0;
	result.blocks[0][2][0] = 0;
	result.blocks[0][2][1] = 4;
	result.blocks[0][2][2] = 0;
	result.blocks[0][2][3] = 0;
	result.blocks[0][3][0] = 0;
	result.blocks[0][3][1] = 0;
	result.blocks[0][3][2] = 0;
	result.blocks[0][3][3] = 0;

	/*Configuration 2*/
	result.blocks[1][0][0] = 0;
	result.blocks[1][0][1] = 0;
	result.blocks[1][0][2] = 0;
	result.blocks[1][0][3] = 0;
	result.blocks[1][1][0] = 4;
	result.blocks[1][1][1] = 4;
	result.blocks[1][1][2] = 0;
	result.blocks[1][1][3] = 0;
	result.blocks[1][2][0] = 0;
	result.blocks[1][2][1] = 4;
	result.blocks[1][2][2] = 4;
	result.blocks[1][2][3] = 0;
	result.blocks[1][3][0] = 0;
	result.blocks[1][3][1] = 0;
	result.blocks[1][3][2] = 0;
	result.blocks[1][3][3] = 0;

	return result;
}

piece createL()
{
	piece result;

	result.configurations = 4;

	/*Configuration 1*/
	result.blocks[0][0][0] = 0;
	result.blocks[0][0][1] = 0;
	result.blocks[0][0][2] = 0;
	result.blocks[0][0][3] = 0;
	result.blocks[0][1][0] = 5;
	result.blocks[0][1][1] = 5;
	result.blocks[0][1][2] = 5;
	result.blocks[0][1][3] = 0;
	result.blocks[0][2][0] = 0;
	result.blocks[0][2][1] = 0;
	result.blocks[0][2][2] = 5;
	result.blocks[0][2][3] = 0;
	result.blocks[0][3][0] = 0;
	result.blocks[0][3][1] = 0;
	result.blocks[0][3][2] = 0;
	result.blocks[0][3][3] = 0;

	/*Configuration 2*/
	result.blocks[1][0][0] = 0;
	result.blocks[1][0][1] = 0;
	result.blocks[1][0][2] = 5;
	result.blocks[1][0][3] = 0;
	result.blocks[1][1][0] = 0;
	result.blocks[1][1][1] = 0;
	result.blocks[1][1][2] = 5;
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
	result.blocks[2][1][0] = 0;
	result.blocks[2][1][1] = 5;
	result.blocks[2][1][2] = 0;
	result.blocks[2][1][3] = 0;
	result.blocks[2][2][0] = 0;
	result.blocks[2][2][1] = 5;
	result.blocks[2][2][2] = 5;
	result.blocks[2][2][3] = 5;
	result.blocks[2][3][0] = 0;
	result.blocks[2][3][1] = 0;
	result.blocks[2][3][2] = 0;
	result.blocks[2][3][3] = 0;

	/*Configuration 4*/
	result.blocks[3][0][0] = 0;
	result.blocks[3][0][1] = 0;
	result.blocks[3][0][2] = 0;
	result.blocks[3][0][3] = 0;
	result.blocks[3][1][0] = 0;
	result.blocks[3][1][1] = 5;
	result.blocks[3][1][2] = 5;
	result.blocks[3][1][3] = 0;
	result.blocks[3][2][0] = 0;
	result.blocks[3][2][1] = 5;
	result.blocks[3][2][2] = 0;
	result.blocks[3][2][3] = 0;
	result.blocks[3][3][0] = 0;
	result.blocks[3][3][1] = 5;
	result.blocks[3][3][2] = 0;
	result.blocks[3][3][3] = 0;

	return result;
}

piece createJ()
{
	piece result;

	result.configurations = 4;

	/*Configuration 1*/
	result.blocks[0][0][0] = 0;
	result.blocks[0][0][1] = 0;
	result.blocks[0][0][2] = 0;
	result.blocks[0][0][3] = 0;
	result.blocks[0][1][0] = 0;
	result.blocks[0][1][1] = 0;
	result.blocks[0][1][2] = 6;
	result.blocks[0][1][3] = 0;
	result.blocks[0][2][0] = 6;
	result.blocks[0][2][1] = 6;
	result.blocks[0][2][2] = 6;
	result.blocks[0][2][3] = 0;
	result.blocks[0][3][0] = 0;
	result.blocks[0][3][1] = 0;
	result.blocks[0][3][2] = 0;
	result.blocks[0][3][3] = 0;

	/*Configuration 2*/
	result.blocks[1][0][0] = 0;
	result.blocks[1][0][1] = 6;
	result.blocks[1][0][2] = 0;
	result.blocks[1][0][3] = 0;
	result.blocks[1][1][0] = 0;
	result.blocks[1][1][1] = 6;
	result.blocks[1][1][2] = 0;
	result.blocks[1][1][3] = 0;
	result.blocks[1][2][0] = 0;
	result.blocks[1][2][1] = 6;
	result.blocks[1][2][2] = 6;
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
	result.blocks[2][1][1] = 6;
	result.blocks[2][1][2] = 6;
	result.blocks[2][1][3] = 6;
	result.blocks[2][2][0] = 0;
	result.blocks[2][2][1] = 6;
	result.blocks[2][2][2] = 0;
	result.blocks[2][2][3] = 0;
	result.blocks[2][3][0] = 0;
	result.blocks[2][3][1] = 0;
	result.blocks[2][3][2] = 0;
	result.blocks[2][3][3] = 0;

	/*Configuration 4*/
	result.blocks[3][0][0] = 0;
	result.blocks[3][0][1] = 0;
	result.blocks[3][0][2] = 0;
	result.blocks[3][0][3] = 0;
	result.blocks[3][1][0] = 0;
	result.blocks[3][1][1] = 6;
	result.blocks[3][1][2] = 6;
	result.blocks[3][1][3] = 0;
	result.blocks[3][2][0] = 0;
	result.blocks[3][2][1] = 0;
	result.blocks[3][2][2] = 6;
	result.blocks[3][2][3] = 0;
	result.blocks[3][3][0] = 0;
	result.blocks[3][3][1] = 0;
	result.blocks[3][3][2] = 6;
	result.blocks[3][3][3] = 0;

	return result;
}

piece createT()
{
	piece result;

	result.configurations = 4;

	/*Configuration 1*/
	result.blocks[0][0][0] = 0;
	result.blocks[0][0][1] = 0;
	result.blocks[0][0][2] = 7;
	result.blocks[0][0][3] = 0;
	result.blocks[0][1][0] = 0;
	result.blocks[0][1][1] = 0;
	result.blocks[0][1][2] = 7;
	result.blocks[0][1][3] = 7;
	result.blocks[0][2][0] = 0;
	result.blocks[0][2][1] = 0;
	result.blocks[0][2][2] = 7;
	result.blocks[0][2][3] = 0;
	result.blocks[0][3][0] = 0;
	result.blocks[0][3][1] = 0;
	result.blocks[0][3][2] = 0;
	result.blocks[0][3][3] = 0;

	/*Configuration 2*/
	result.blocks[1][0][0] = 0;
	result.blocks[1][0][1] = 0;
	result.blocks[1][0][2] = 7;
	result.blocks[1][0][3] = 0;
	result.blocks[1][1][0] = 0;
	result.blocks[1][1][1] = 7;
	result.blocks[1][1][2] = 7;
	result.blocks[1][1][3] = 7;
	result.blocks[1][2][0] = 0;
	result.blocks[1][2][1] = 0;
	result.blocks[1][2][2] = 0;
	result.blocks[1][2][3] = 0;
	result.blocks[1][3][0] = 0;
	result.blocks[1][3][1] = 0;
	result.blocks[1][3][2] = 0;
	result.blocks[1][3][3] = 0;

	/*Configuration 3*/
	result.blocks[2][0][0] = 0;
	result.blocks[2][0][1] = 0;
	result.blocks[2][0][2] = 7;
	result.blocks[2][0][3] = 0;
	result.blocks[2][1][0] = 0;
	result.blocks[2][1][1] = 7;
	result.blocks[2][1][2] = 7;
	result.blocks[2][1][3] = 0;
	result.blocks[2][2][0] = 0;
	result.blocks[2][2][1] = 0;
	result.blocks[2][2][2] = 7;
	result.blocks[2][2][3] = 0;
	result.blocks[2][3][0] = 0;
	result.blocks[2][3][1] = 0;
	result.blocks[2][3][2] = 0;
	result.blocks[2][3][3] = 0;

	/*Configuration 4*/
	result.blocks[3][0][0] = 0;
	result.blocks[3][0][1] = 0;
	result.blocks[3][0][2] = 0;
	result.blocks[3][0][3] = 0;
	result.blocks[3][1][0] = 0;
	result.blocks[3][1][1] = 7;
	result.blocks[3][1][2] = 7;
	result.blocks[3][1][3] = 7;
	result.blocks[3][2][0] = 0;
	result.blocks[3][2][1] = 0;
	result.blocks[3][2][2] = 7;
	result.blocks[3][2][3] = 0;
	result.blocks[3][3][0] = 0;
	result.blocks[3][3][1] = 0;
	result.blocks[3][3][2] = 0;
	result.blocks[3][3][3] = 0;

	return result;
}

piece createI()
{
	piece result;

	result.configurations = 2;

	/*Configuration 1*/
	result.blocks[0][0][0] = 0;
	result.blocks[0][0][1] = 0;
	result.blocks[0][0][2] = 0;
	result.blocks[0][0][3] = 0;
	result.blocks[0][1][0] = 0;
	result.blocks[0][1][1] = 0;
	result.blocks[0][1][2] = 0;
	result.blocks[0][1][3] = 0;
	result.blocks[0][2][0] = 8;
	result.blocks[0][2][1] = 8;
	result.blocks[0][2][2] = 8;
	result.blocks[0][2][3] = 8;
	result.blocks[0][3][0] = 0;
	result.blocks[0][3][1] = 0;
	result.blocks[0][3][2] = 0;
	result.blocks[0][3][3] = 0;

	/*Configuration 2*/
	result.blocks[1][0][0] = 0;
	result.blocks[1][0][1] = 8;
	result.blocks[1][0][2] = 0;
	result.blocks[1][0][3] = 0;
	result.blocks[1][1][0] = 0;
	result.blocks[1][1][1] = 8;
	result.blocks[1][1][2] = 0;
	result.blocks[1][1][3] = 0;
	result.blocks[1][2][0] = 0;
	result.blocks[1][2][1] = 8;
	result.blocks[1][2][2] = 0;
	result.blocks[1][2][3] = 0;
	result.blocks[1][3][0] = 0;
	result.blocks[1][3][1] = 8;
	result.blocks[1][3][2] = 0;
	result.blocks[1][3][3] = 0;

	return result;
}

piece createO()
{
	piece result;

	result.configurations = 1;

	/*Configuration 1*/
	result.blocks[0][0][0] = 0;
	result.blocks[0][0][1] = 0;
	result.blocks[0][0][2] = 0;
	result.blocks[0][0][3] = 0;
	result.blocks[0][1][0] = 0;
	result.blocks[0][1][1] = 9;
	result.blocks[0][1][2] = 9;
	result.blocks[0][1][3] = 0;
	result.blocks[0][2][0] = 0;
	result.blocks[0][2][1] = 9;
	result.blocks[0][2][2] = 9;
	result.blocks[0][2][3] = 0;
	result.blocks[0][3][0] = 0;
	result.blocks[0][3][1] = 0;
	result.blocks[0][3][2] = 0;
	result.blocks[0][3][3] = 0;

	return result;
}