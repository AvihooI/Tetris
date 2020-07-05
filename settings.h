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

#define DEFAULT_VOLUME 4

#define MAX_VOLUME 8
#define MIN_VOLUME 0

#define SETTINGS_FILE_NAME "settings.cfg"

void defaultSettings();

void initSettings();

void saveSettings();

typedef struct settings
{
	unsigned int version;

	/*Display*/
	unsigned int blockSize;

	/*Input*/
	int movementKeyboardCooldown;
	int rotationKeyboardCooldown;
	int dropKeyboardCooldown;

	/*Sound*/
	int soundVolume;
} settings;

settings currentSettings;

#endif //TETRIS_SETTINGS_H
