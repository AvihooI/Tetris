//
// Created by Avihoo on 05/07/2020.
//

#include "text.h"
#include <stdio.h>

void initFonts()
{
	closeFonts();

	fonts.mainFont = TTF_OpenFont(FONT_FILENAME, BLOCK_SIZE);
	fonts.smallFont = TTF_OpenFont(FONT_FILENAME, (int) (BLOCK_SIZE * 3) / 4);
}

void closeFonts()
{
	if (fonts.mainFont)
	{
		TTF_CloseFont(fonts.mainFont);
	}

	if (fonts.smallFont)
	{
		TTF_CloseFont(fonts.smallFont);
	}
}

void printText(int left, int top, unsigned int leftCentered, unsigned int topCentered, SDL_Color color, TTF_Font *font,
               const char *fmt, ...)
{
	char str[64];

	va_list args;
			va_start(args, fmt);
	vsnprintf(str, sizeof(str), fmt, args);
			va_end(args);

	SDL_Surface *surface = TTF_RenderText_Solid(font, str, color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(graphics.renderer, surface);

	SDL_Rect dRect = {left, top, 0, 0};

	SDL_QueryTexture(texture, 0, 0, &dRect.w, &dRect.h);
	if (leftCentered)
	{
		dRect.x -= dRect.w / 2;
	}

	if (topCentered)
	{
		dRect.y -= dRect.h / 2;
	}

	SDL_RenderCopy(graphics.renderer, texture, 0, &dRect);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}