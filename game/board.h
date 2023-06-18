#pragma once
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "properties.h"

// For game board
void board_init(WINDOW *win, GameState *state);
void board_print(WINDOW *win, GameState *state);
void board_randomize(GameState *state);
void hexagon_print(WINDOW *win, int row, int col);
