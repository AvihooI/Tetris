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

menu createSettingsMenu()
{
	menu result;

	result.menuItemCount = SETTINGS_MENU_ITEM_COUNT;
	result.menuItems = malloc(sizeof(menuItem) * SETTINGS_MENU_ITEM_COUNT);
	result.selectedItem = 0;

	result.menuItems[0] = createBlockSizeMenuItem();
	result.menuItems[1] = createBackMenuItem();


	return result;
}

void blockSizeAction(menuAction action)
{
	switch (action)
	{

		case MENU_PRESS_LEFT:
			settings.blockSize = max(settings.blockSize - 1, MIN_BLOCK_SIZE);
			refreshWindowSize();
			break;
		case MENU_PRESS_RIGHT:
			settings.blockSize = min(settings.blockSize + 1, MAX_BLOCK_SIZE);
			refreshWindowSize();
			break;
		case MENU_PRESS_RETURN:
			break;
	}


}

const char *blockSizeGetText()
{
	static char levelStr[64];

	snprintf(levelStr, sizeof(levelStr), "<Block Size: %d>", settings.blockSize);

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

	result.getText  = backGetText;
	result.doAction = backAction;

	return result;
}