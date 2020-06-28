//
// Created by Avihoo on 28/06/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "menu.h"
#include "rendering.h"

#include "settings_menu.h"

menuItem createBackMenuItem();

menuItem createBlockSizeMenuItem();

menuItem createMovementRepeatRateMenuItem();

menu createSettingsMenu()
{
	menu result;

	result.menuItemCount = SETTINGS_MENU_ITEM_COUNT;
	result.menuItems = malloc(sizeof(menuItem) * SETTINGS_MENU_ITEM_COUNT);
	result.selectedItem = 0;

	result.menuItems[0] = createBlockSizeMenuItem();
	result.menuItems[1] = createMovementRepeatRateMenuItem();
	result.menuItems[2] = createBackMenuItem();


	return result;
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
			refreshWindowSize();
			break;
		case MENU_PRESS_RETURN:
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

menuItem createMovementRepeatRateMenuItem()
{
	menuItem result;

	result.getText = movementRepeatRateGetText;
	result.doAction = movementRepeatRateAction;

	return result;
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
		case MENU_PRESS_RETURN:
			break;
	}

}

const char *blockSizeGetText()
{
	static char levelStr[64];

	snprintf(levelStr, sizeof(levelStr), "<Block Size: %d>", currentSettings.blockSize);

	return levelStr;
}

menuItem createBlockSizeMenuItem()
{
	menuItem result;

	result.getText = blockSizeGetText;
	result.doAction = blockSizeAction;

	return result;
}

const char *backGetText()
{
	static char text[] = "Main Menu";

	return text;
}

void backAction(menuAction action)
{
	switch (action)
	{

		case MENU_PRESS_LEFT:
			break;
		case MENU_PRESS_RIGHT:
			break;
		case MENU_PRESS_RETURN:
			menuState.selectedMenu = MAIN_MENU;
			break;
	}
}

menuItem createBackMenuItem()
{
	menuItem result;

	result.getText = backGetText;
	result.doAction = backAction;

	return result;
}