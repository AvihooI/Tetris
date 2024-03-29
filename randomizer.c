//
// Created by Avihoo on 25/06/2020.
//

#include "randomizer.h"
#include <stdlib.h>
#include <time.h>

void initRandomizer()
{
	currentRecentIndex = 0;

	for (int i = 0; i < RECENT_PIECES_SIZE; i++)
	{
		recentPieces[i] = 7;
	}

	srand((unsigned int) time(0));
}

unsigned int incrementRecentIndex()
{
	unsigned int returnedIndex = currentRecentIndex;

	currentRecentIndex = (currentRecentIndex + 1) % RECENT_PIECES_SIZE;

	return returnedIndex;
}

void addRecentPiece(unsigned int pieceType)
{
	recentPieces[incrementRecentIndex()] = pieceType;
}

unsigned char inRecentPieces(unsigned int pieceType)
{
	for (int i = 0; i < RECENT_PIECES_SIZE; i++)
	{
		if (pieceType == recentPieces[i])
		{
			return 1;
		}
	}

	return 0;
}

unsigned int getNewPiece()
{
	unsigned int attemptedPiece = 7;

	for (int i = 0; i < RANDOMIZER_MAX_ATTEMPTS; i++)
	{
		attemptedPiece = (unsigned int) (rand() % 7);
		if (!inRecentPieces(attemptedPiece))
		{
			break;
		}
	}

	addRecentPiece(attemptedPiece);

	return attemptedPiece;
}