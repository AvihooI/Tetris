//
// Created by Avihoo on 05/07/2020.
//

#include <stdio.h>
#include "colors.h"

void initColors()
{
	colors[0].r = 0;
	colors[0].g = 0;
	colors[0].b = 0;

	colors[1].r = 128;
	colors[1].g = 128;
	colors[1].b = 128;

	colors[2].r = 88;
	colors[2].g = 98;
	colors[2].b = 104;

	colors[3].r = 255;
	colors[3].g = 0;
	colors[3].b = 0;

	colors[4].r = 0;
	colors[4].g = 255;
	colors[4].b = 0;

	colors[5].r = 0;
	colors[5].g = 0;
	colors[5].b = 255;

	colors[6].r = 255;
	colors[6].g = 255;
	colors[6].b = 00;

	colors[7].r = 255;
	colors[7].g = 0;
	colors[7].b = 255;

	colors[8].r = 0;
	colors[8].g = 255;
	colors[8].b = 255;

	colors[9].r = 125;
	colors[9].g = 120;
	colors[9].b = 95;

	colors[10].r = 204;
	colors[10].g = 102;
	colors[10].b = 255;

	colors[11].r = 51;
	colors[11].g = 204;
	colors[11].b = 255;

	colors[12].r = 255;
	colors[12].g = 255;
	colors[12].b = 255;
}

SDL_Color dim(SDL_Color originalColor, unsigned int dimNumerator, unsigned int dimDenominator)
{
	return interpolate(originalColor, colors[0], dimNumerator, dimDenominator);
}

SDL_Color interpolate(SDL_Color color1, SDL_Color color2, unsigned int factorNumerator, unsigned int factorDenominator)
{
	unsigned int r = color1.r * factorNumerator + color2.r * (factorDenominator - factorNumerator);
	unsigned int g = color1.g * factorNumerator + color2.g * (factorDenominator - factorNumerator);
	unsigned int b = color1.b * factorNumerator + color2.b * (factorDenominator - factorNumerator);

	r /= factorDenominator;
	g /= factorDenominator;
	b /= factorDenominator;

	SDL_Color result = {(Uint8) r, (Uint8) g, (Uint8) b};

	return result;
}