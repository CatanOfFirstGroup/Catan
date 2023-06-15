// header for init window of options
#pragma once
#include <ncurses.h>
#include "../game/properties.h"

void options_init(WINDOW *win, int row, int col, GameState *state);
void set_options(WINDOW *win, int row, int col, GameState *state);