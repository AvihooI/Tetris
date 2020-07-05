//
// Created by Avihoo on 05/07/2020.
//

#ifndef TETRIS_COLORS_H
#define TETRIS_COLORS_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "tetris.h"
#include "logic.h"
#include "menu.h"
#include "animation.h"

#define COLOR_COUNT 13

SDL_Color colors[COLOR_COUNT];

void initColors();

SDL_Color dim(SDL_Color originalColor, unsigned int dimNumerator, unsigned int dimDenominator);

SDL_Color interpolate(SDL_Color color1, SDL_Color color2, unsigned int factorNumerator, unsigned int factorDenominator);

#endif //TETRIS_COLORS_H