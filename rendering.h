//
// Created by Avihoo on 13/06/2020.
//

#ifndef TETRIS_RENDERING_H
#define TETRIS_RENDERING_H

#include <SDL.h>
#include "tetris.h"
#include "text.h"
#include "logic.h"
#include "menu.h"
#include "animation.h"
#include "rendering_utilities.h"
#include "colors.h"

/*Principal rendering functions*/

void doRendering();

void renderBoundaries();

void renderGridAndPiece();

void renderEnqueuedPiece();

void renderText();

void renderMenu();

#endif //TETRIS_RENDERING_H
