//
// Created by Avihoo on 23/06/2020.
//

#include "menu.h"
#include "logic.h"
#include <stdio.h>

menuItem createResumeMenuItem();

menuItem createQuitMenuItem();

menuItem createNewGameMenuItem();

menuItem createLevelMenuItem();

void initMenu()
{
	menuState.isActive = 0;
	menuState.selectedItem = 0;
	menuState.wantsToQuit = 0;

	menuState.menuItems[0] = createResumeMenuItem();
	menuState.menuItems[1] = createNewGameMenuItem();
	menuState.menuItems[2] = createLevelMenuItem();
	menuState.menuItems[3] = createQuitMenuItem();

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

const char *newGameText()
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

	result.getText = newGameText;
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
		menuState.wantsToQuit = 1;
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
		menuState.isActive = 0;

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

void menuActionUp()
{
	menuState.selectedItem = (menuState.selectedItem - 1) % MENU_ITEM_COUNT;
}

void menuActionDown()
{
	menuState.selectedItem = (menuState.selectedItem + 1) % MENU_ITEM_COUNT;
}

void menuActionReturn()
{
	menuState.menuItems[menuState.selectedItem].doAction(MENU_PRESS_RETURN);
}

void menuActionLeft()
{
	menuState.menuItems[menuState.selectedItem].doAction(MENU_PRESS_LEFT);
}

void menuActionRight()
{
	menuState.menuItems[menuState.selectedItem].doAction(MENU_PRESS_RIGHT);
}
