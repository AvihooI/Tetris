//
// Created by Avihoo on 25/06/2020.
//

#ifndef TETRIS_RANDOMIZER_H
#define TETRIS_RANDOMIZER_H

#define RECENT_PIECES_SIZE 4
#define RANDOMIZER_MAX_ATTEMPTS 4

void initRandomizer();

unsigned int getNewPiece();

unsigned int recentPieces[RECENT_PIECES_SIZE];
unsigned int currentRecentIndex;

#endif //TETRIS_RANDOMIZER_H
