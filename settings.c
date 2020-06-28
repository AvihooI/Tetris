//
// Created by Avihoo on 28/06/2020.
//

#include "settings.h"
#include <SDL.h>

void defaultSettings();

void initSettings()
{
	SDL_RWops *file = SDL_RWFromFile(SETTINGS_FILE_NAME, "r");

	if (!file)
	{
		defaultSettings();
		return;
	}

	settings readSettings;

	SDL_RWread(file, &readSettings, sizeof(settings), 1);

	if (readSettings.version == SETTINGS_VERSION)
	{
		currentSettings = readSettings;
	}
	else
	{
		defaultSettings();
	}

	SDL_RWclose(file);
}

void saveSettings()
{
	SDL_RWops *file = SDL_RWFromFile(SETTINGS_FILE_NAME, "w");

	SDL_RWwrite(file, &currentSettings, sizeof(currentSettings), 1);

	SDL_RWclose(file);
}

void defaultSettings()
{
	currentSettings.version = SETTINGS_VERSION;
	currentSettings.blockSize = DEFAULT_BLOCK_SIZE;
	currentSettings.movementKeyboardCooldown = DEFAULT_MOVEMENT_KEYBOARD_COOLDOWN;
	currentSettings.rotationKeyboardCooldown = DEFAULT_ROTATION_KEYBOARD_COOLDOWN;
	currentSettings.dropKeyboardCooldown = DEFAULT_DROP_KEYBOARD_COOLDOWN;
}
