//
// Created by Avihoo on 23/06/2020.
//

#include "menu.h"
#include "main_menu.h"
#include "settings_menu.h"
#include <stdio.h>
#include <stdlib.h>

void initMenu()
{
	menuState.menus = malloc(MENU_COUNT*sizeof(menu));
	menuState.menuCount = MENU_COUNT;

	menuState.menus[0] = createMainMenu();
	menuState.menus[1] = createSettingsMenu();

	menuState.isActive = 0;
	menuState.wantsToQuit = 0;

}

void destroyMenu()
{

	for (int i = 0; i < menuState.menuCount; i++)
	{
		free(menuState.menus[i].menuItems);
	}

	free(menuState.menus);
}


void menuActionUp()
{
	menuState.menus[menuState.selectedMenu].selectedItem = (menuState.menus[menuState.selectedMenu].selectedItem + (menuState.menus[menuState.selectedMenu].menuItemCount) - 1) % menuState.menus[menuState.selectedMenu].menuItemCount;
}

void menuActionDown()
{
	menuState.menus[menuState.selectedMenu].selectedItem = (menuState.menus[menuState.selectedMenu].selectedItem + 1) % menuState.menus[menuState.selectedMenu].menuItemCount;
}

void menuActionReturn()
{
	menuState.menus[menuState.selectedMenu].menuItems[menuState.menus[menuState.selectedMenu].selectedItem].doAction(MENU_PRESS_RETURN);
}

void menuActionLeft()
{
	menuState.menus[menuState.selectedMenu].menuItems[menuState.menus[menuState.selectedMenu].selectedItem].doAction(MENU_PRESS_LEFT);
}

void menuActionRight()
{
	menuState.menus[menuState.selectedMenu].menuItems[menuState.menus[menuState.selectedMenu].selectedItem].doAction(MENU_PRESS_RIGHT);
}

void activateMenu()
{
	menuState.selectedMenu = MAIN_MENU;
	menuState.menus[0].selectedItem = 0;
	menuState.isActive = 1;
}
