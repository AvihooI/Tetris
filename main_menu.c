//
// Created by Avihoo on 28/06/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "main_menu.h"

menuItem createLevelMenuItem();

menuItem createNewGameMenuItem();

menuItem createQuitMenuItem();

menuItem createResumeMenuItem();

menuItem createSettingsMenuItem();

menu createMainMenu()
{
	menu result;

	result.menuItemCount = MAIN_MENU_ITEM_COUNT;
	result.menuItems = malloc(sizeof(menuItem) * MAIN_MENU_ITEM_COUNT);
	result.menuItems[0] = createResumeMenuItem();
	result.menuItems[1] = createNewGameMenuItem();
	result.menuItems[2] = createLevelMenuItem();
	result.menuItems[3] = createSettingsMenuItem();
	result.menuItems[4] = createQuitMenuItem();

	return result;
}

const char *settingsGetText()
{
	static char text[] = "Settings";

	return text;
}

void settingsAction(menuAction action)
{
	switch (action)
	{

		case MENU_PRESS_LEFT:
			break;
		case MENU_PRESS_RIGHT:
			break;
		case MENU_PRESS_RETURN:
			menuState.selectedMenu = SETTINGS_MENU;
			break;
	}
}

menuItem createSettingsMenuItem()
{
	menuItem result;

	result.getText = settingsGetText;
	result.doAction = settingsAction;

	return result;
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
		case MENU_PRESS_RETURN:
			break;
	}
}

menuItem createLevelMenuItem()
{
	menuItem result;

	result.getText = levelGetText;
	result.doAction = levelAction;

	return result;
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

menuItem createNewGameMenuItem()
{
	menuItem result;

	result.getText = newGameGetText;
	result.doAction = newGameAction;

	return result;
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

menuItem createQuitMenuItem()
{
	menuItem result;

	result.getText = quitGetText;
	result.doAction = quitAction;

	return result;
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

menuItem createResumeMenuItem()
{
	menuItem result;

	result.doAction = resumeAction;
	result.getText = resumeGetText;

	return result;
}