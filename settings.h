//
// Created by Avihoo on 28/06/2020.
//

#ifndef TETRIS_SETTINGS_H
#define TETRIS_SETTINGS_H

/*Rendering Settings*/

#define DEFAULT_BLOCK_SIZE 30
#define MAX_BLOCK_SIZE 35
#define MIN_BLOCK_SIZE 15

void initSettings();

struct
{
	unsigned int blockSize;
} settings;

#endif //TETRIS_SETTINGS_H
