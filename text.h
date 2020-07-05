//
// Created by Avihoo on 05/07/2020.
//

#ifndef TETRIS_TEXT_H
#define TETRIS_TEXT_H

#include "SDL_ttf.h"

#define FONT_FILENAME "hemi_head.ttf"

/*Fonts*/

struct
{
	TTF_Font *mainFont;
	TTF_Font *smallFont;
} fonts;

/*Font initialization, destruction and text functions utility functions*/

void initFonts();

void closeFonts();

void printText(int left, int top, unsigned int leftCentered, unsigned int topCentered, SDL_Color color, TTF_Font *font,
               const char *fmt, ...);

#include "rendering.h"

#endif //TETRIS_TEXT_H
