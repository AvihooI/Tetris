//
// Created by Avihoo on 28/06/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "sound.h"
#include "menu.h"
#include "rendering.h"
#include "settings_menu.h"

void soundVolumeAction(menuAction action)
{
	switch (action)
	{

		case MENU_PRESS_LEFT:
			currentSettings.soundVolume =
					(currentSettings.soundVolume + MAX_VOLUME - MIN_VOLUME) % (MAX_VOLUME - MIN_VOLUME + 1);
			break;
		case MENU_PRESS_RIGHT:
			currentSettings.soundVolume = (currentSettings.soundVolume + 1) % (MAX_VOLUME - MIN_VOLUME + 1);
			break;
		default:
			break;
	}

	refreshSound();
	playSoundLineClear();

}

const char *soundVolumeGetText()
{
	static char levelStr[64];

	snprintf(levelStr, sizeof(levelStr), "<Sound Volume: %d>", currentSettings.soundVolume);

	return levelStr;
}

void movementRepeatRateAction(menuAction action)
{
	switch (action)
	{

		case MENU_PRESS_LEFT:
			currentSettings.movementKeyboardCooldown--;
			if (currentSettings.movementKeyboardCooldown < MIN_COOLDOWN)
			{
				currentSettings.movementKeyboardCooldown = -1;
			}
			break;
		case MENU_PRESS_RIGHT:
			currentSettings.movementKeyboardCooldown = min(
					max(currentSettings.movementKeyboardCooldown + 1, MIN_COOLDOWN), MAX_COOLDOWN);
			break;
		default:
			break;
	}

}

const char *movementRepeatRateGetText()
{
	static char levelStr[64];

	if (currentSettings.movementKeyboardCooldown > 0)
	{
		snprintf(levelStr, sizeof(levelStr), "<Move Repeat Rate: %d>", currentSettings.movementKeyboardCooldown);
	}
	else
	{
		snprintf(levelStr, sizeof(levelStr), "<Move Repeat Rate: OFF>");
	}

	return levelStr;
}

void blockSizeAction(menuAction action)
{
	switch (action)
	{

		case MENU_PRESS_LEFT:
			currentSettings.blockSize = max(currentSettings.blockSize - 1, MIN_BLOCK_SIZE);
			refreshWindowSize();
			break;
		case MENU_PRESS_RIGHT:
			currentSettings.blockSize = min(currentSettings.blockSize + 1, MAX_BLOCK_SIZE);
			refreshWindowSize();
			break;
		default:
			break;
	}

}

const char *blockSizeGetText()
{
	static char levelStr[64];

	snprintf(levelStr, sizeof(levelStr), "<Block Size: %d>", currentSettings.blockSize);

	return levelStr;
}

menu createSettingsMenu()
{
	menu result;

	result.menuItemCount = SETTINGS_MENU_ITEM_COUNT;
	result.menuItems = malloc(sizeof(menuItem) * SETTINGS_MENU_ITEM_COUNT);
	result.selectedItem = 0;

	result.menuItems[0] = createMenuItem(blockSizeGetText, blockSizeAction);
	result.menuItems[1] = createMenuItem(movementRepeatRateGetText, movementRepeatRateAction);
	result.menuItems[2] = createMenuItem(soundVolumeGetText, soundVolumeAction);
	result.menuItems[3] = createBackMenuItem();

	return result;
}