//
// Created by Avihoo on 23/06/2020.
//

#ifndef TETRIS_MENU_H
#define TETRIS_MENU_H

#include "sound.h"

#include "tetris.h"
#include "logic.h"

#define MENU_COUNT 2

#define MAIN_MENU 0
#define SETTINGS_MENU 1

typedef enum
{
	MENU_PRESS_LEFT,
	MENU_PRESS_RIGHT,
	MENU_PRESS_RETURN
} menuAction;

typedef const char *(*menuItemGetText)();

typedef void (*menuItemDoAction)(menuAction action);

typedef struct menuItem
{
	menuItemGetText getText;
	menuItemDoAction doAction;
} menuItem;

typedef struct menu
{
	unsigned int selectedItem;
	unsigned int menuItemCount;
	menuItem *menuItems;
} menu;

struct
{
	unsigned int isActive;
	unsigned int selectedMenu;
	unsigned int wantsToQuit;

	unsigned int menuCount;
	menu *menus;

} menuState;

menuItem createMenuItem(menuItemGetText getText, menuItemDoAction doAction);

menuItem createBackMenuItem();

void initMenu();

void destroyMenu();

void activateMenu();

void menuActionUp();

void menuActionDown();

void menuActionReturn();

void menuActionLeft();

void menuActionRight();

#endif //TETRIS_MENU_H
