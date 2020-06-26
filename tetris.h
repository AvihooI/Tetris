//
// Created by Avihoo on 13/06/2020.
//

#ifndef TETRIS_TETRIS_H
#define TETRIS_TETRIS_H

#define MAX_LEVEL 30
#define BASE_MILLISECONDS_PER_STEP 750
#define SPEED_GROWTH_RATE_NUMERATOR 27
#define SPEED_GROWTH_RATE_DENOMINATOR 24

#define BASE_LINES_TO_LEVEL_UP 40
#define LINES_TO_LEVEL_GROWTH_NUMERATOR 4
#define LINES_TO_LEVEL_GROWTH_DENOMINATOR 3

#define GAME_GRID_WIDTH 10
#define GAME_GRID_HEIGHT 26
#define GAME_GRID_INVISIBLE_LINES 2

#define MILLISECONDS_PER_LOGIC_TICK 5

#define MAIN_FRAME_LEFT 2
#define MAIN_FRAME_TOP 2
#define MAIN_FRAME_WIDTH (GAME_GRID_WIDTH + 2)
#define MAIN_FRAME_HEIGHT (GAME_GRID_HEIGHT + 2 - GAME_GRID_INVISIBLE_LINES)

#define SCORE_TEXT_LEFT (MAIN_FRAME_LEFT + MAIN_FRAME_WIDTH + 1)
#define SCORE_TEXT_TOP (((MAIN_FRAME_TOP + MAIN_FRAME_HEIGHT) * 2) / 16)

#define LINES_REMAINING_TEXT_LEFT SCORE_TEXT_LEFT
#define LINES_REMAINING_TEXT_TOP (SCORE_TEXT_TOP + 2)

#define ENQUEUED_FRAME_LEFT (LINES_REMAINING_TEXT_LEFT)
#define ENQUEUED_FRAME_TOP (LINES_REMAINING_TEXT_TOP + 3)
#define ENQUEUED_FRAME_WIDTH 6
#define ENQUEUED_FRAME_HEIGHT 6

/*
 * Resume
 * Level
 * New
 * Quit
 * */

#define MENU_ITEM_COUNT 4
#define MENU_LEFT ENQUEUED_FRAME_LEFT
#define MENU_TOP (ENQUEUED_FRAME_TOP + ENQUEUED_FRAME_HEIGHT + 2)
#define MENU_WIDTH (ENQUEUED_FRAME_WIDTH + 5)
#define MENU_ITEM_SPACING 2
#define MENU_HEIGHT (MENU_ITEM_COUNT*MENU_ITEM_SPACING+1)

#define LEVEL_TEXT_LEFT ((MAIN_FRAME_LEFT + MAIN_FRAME_WIDTH) / 2)
#define LEVEL_TEXT_TOP MAIN_FRAME_TOP

#define WINDOW_WIDTH (MAIN_FRAME_WIDTH + 16)
#define WINDOW_HEIGHT (MAIN_FRAME_HEIGHT + 4)

#endif //TETRIS_TETRIS_H
