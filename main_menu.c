//
// Created by Avihoo on 28/06/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "main_menu.h"


const char *settingsGetText()
{
	static char text[] = "Settings";

	return text;
}

void settingsAction(menuAction action)
{
	if (action == MENU_PRESS_RETURN)
	{
		menuState.selectedMenu = SETTINGS_MENU;
	}
}

const char *levelGetText()
{
	static char levelStr[64];

	snprintf(levelStr, sizeof(levelStr), "<Level %d>", gameState.startingLevel + 1);

	return levelStr;
}

void levelAction(menuAction action)
{
	switch (action)
	{

		case MENU_PRESS_LEFT:
			gameState.startingLevel = (gameState.startingLevel + MAX_LEVEL - 1) % MAX_LEVEL;
			break;
		case MENU_PRESS_RIGHT:
			gameState.startingLevel = (gameState.startingLevel + 1) % MAX_LEVEL;
			break;
		default:
			break;
	}
}

const char *newGameGetText()
{
	static char text[] = "New Game";

	return text;
}

void newGameAction(menuAction action)
{
	if (action == MENU_PRESS_RETURN)
	{
		menuState.isActive = 0;
		newGame();
	}
}

const char *quitGetText()
{
	static char text[] = "Quit";

	return text;
}

void quitAction(menuAction action)
{
	if (action == MENU_PRESS_RETURN)
	{
		menuState.wantsToQuit = 1;
	}
}

void resumeAction(menuAction action)
{
	if (action == MENU_PRESS_RETURN)
	{
		menuState.isActive = 0;
	}

}

const char *resumeGetText()
{
	static char text[] = "Resume";

	return text;
}

menu createMainMenu()
{
	menu result;

	result.menuItemCount = MAIN_MENU_ITEM_COUNT;
	result.menuItems = malloc(sizeof(menuItem) * MAIN_MENU_ITEM_COUNT);
	result.menuItems[0] = createMenuItem(resumeGetText, resumeAction);
	result.menuItems[1] = createMenuItem(newGameGetText, newGameAction);
	result.menuItems[2] = createMenuItem(levelGetText, levelAction);
	result.menuItems[3] = createMenuItem(settingsGetText, settingsAction);
	result.menuItems[4] = createMenuItem(quitGetText, quitAction);

	return result;
}