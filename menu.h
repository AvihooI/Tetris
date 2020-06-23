//
// Created by Avihoo on 23/06/2020.
//

#ifndef TETRIS_MENU_H
#define TETRIS_MENU_H

#include "tetris.h"
#include "logic.h"

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

struct
{
	unsigned int isActive;
	unsigned int selectedItem;
	unsigned int wantsToQuit;

	menuItem menuItems[MENU_ITEM_COUNT];

} menuState;

void initMenu();

void menuActionUp();

void menuActionDown();

void menuActionReturn();

void menuActionLeft();

void menuActionRight();

#endif //TETRIS_MENU_H
