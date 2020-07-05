//
// Created by Avihoo on 05/07/2020.
//

#ifndef TETRIS_RENDERING_UTILITIES_H
#define TETRIS_RENDERING_UTILITIES_H

#include "graphics.h"

/*Rendering utility functions*/

void renderFrame(unsigned int top, unsigned int left, unsigned int height, unsigned int width, unsigned int colorIndex);

void renderPiece(unsigned int pieceType, unsigned int pieceConfiguration, int top, int left, unsigned int visibleTop);

void renderGrid(unsigned int animation);

void renderBlock(unsigned int x, unsigned int y, unsigned int colorIndex, unsigned int dimNumerator,
                 unsigned int dimDenominator);


#endif //TETRIS_RENDERING_UTILITIES_H
