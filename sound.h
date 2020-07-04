//
// Created by Avihoo on 30/06/2020.
//

#ifndef TETRIS_SOUND_H
#define TETRIS_SOUND_H

#include <SDL_mixer.h>

#define LAND_SOUND_FILE "land.mp3"
#define LINE_CLEAR_SOUND_FILE "line_clear.mp3"
#define ROTATE_SOUND_FILE "rotate.mp3"
#define TETRIS_SOUND_FILE "tetris.mp3"
#define LEVEL_UP_SOUND_FILE "level_up.mp3"


struct
{
	Mix_Chunk *landSample;
	Mix_Chunk *lineClearSample;
	Mix_Chunk *rotateSample;
	Mix_Chunk *tetrisSample;
	Mix_Chunk *levelUpSample;
} sounds;

void initSound();

void destroySound();

void refreshSound();

void playSoundLand();

void playSoundLineClear();

void playSoundRotate();

void playSoundTetris();

void playSoundLevelUp();

#endif //TETRIS_SOUND_H
