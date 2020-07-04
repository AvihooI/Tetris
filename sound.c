//
// Created by Avihoo on 30/06/2020.
//

#include "sound.h"
#include "settings.h"
#include <SDL_mixer.h>

void loadSamples();

void freeSamples();

void initSound()
{
	Mix_Init(MIX_INIT_MP3);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	refreshSound();

	loadSamples();
}

void loadSamples()
{
	sounds.landSample = Mix_LoadWAV(LAND_SOUND_FILE);
	sounds.rotateSample = Mix_LoadWAV(ROTATE_SOUND_FILE);
	sounds.lineClearSample = Mix_LoadWAV(LINE_CLEAR_SOUND_FILE);
	sounds.tetrisSample = Mix_LoadWAV(TETRIS_SOUND_FILE);
	sounds.levelUpSample = Mix_LoadWAV(LEVEL_UP_SOUND_FILE);
}

void destroySound()
{
	freeSamples();
	Mix_CloseAudio();
	Mix_Quit();
}

void freeSamples()
{
	Mix_FreeChunk(sounds.landSample);
	Mix_FreeChunk(sounds.rotateSample);
	Mix_FreeChunk(sounds.lineClearSample);
	Mix_FreeChunk(sounds.tetrisSample);
	Mix_FreeChunk(sounds.levelUpSample);
}

void playSound(Mix_Chunk *sample)
{
	Mix_PlayChannel(-1, sample, 0);
}

void playSoundLand()
{
	playSound(sounds.landSample);
}

void playSoundLineClear()
{
	playSound(sounds.lineClearSample);
}

void playSoundRotate()
{
	playSound(sounds.rotateSample);
}

void playSoundTetris()
{
	playSound(sounds.tetrisSample);
}

void playSoundLevelUp()
{
	playSound(sounds.levelUpSample);
}

void refreshSound()
{
	int effectiveVolume;

	effectiveVolume = (MIX_MAX_VOLUME / (MAX_VOLUME-MIN_VOLUME)) * currentSettings.soundVolume;

	Mix_Volume(-1, effectiveVolume);
}




