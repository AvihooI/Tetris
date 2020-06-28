//
// Created by Avihoo on 28/06/2020.
//

#ifndef TETRIS_SETTINGS_H
#define TETRIS_SETTINGS_H

/*Version Info*/

#define SETTINGS_VERSION sizeof(settings)

/*Rendering Settings*/

#define DEFAULT_BLOCK_SIZE 30
#define MAX_BLOCK_SIZE 35
#define MIN_BLOCK_SIZE 15

/*Keyboard Input Settings*/
#define DEFAULT_MOVEMENT_KEYBOARD_COOLDOWN 85
#define DEFAULT_ROTATION_KEYBOARD_COOLDOWN -1
#define DEFAULT_DROP_KEYBOARD_COOLDOWN -1
#define MAX_COOLDOWN 200
#define MIN_COOLDOWN 20

void initSettings();

#define SETTINGS_FILE_NAME "settings.cfg"

void saveSettings();

typedef struct settings
{
	unsigned int version;
	unsigned int blockSize;
	int movementKeyboardCooldown;
	int rotationKeyboardCooldown;
	int dropKeyboardCooldown;
} settings;

settings currentSettings;

#endif //TETRIS_SETTINGS_H
