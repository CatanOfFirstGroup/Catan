#pragma once

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "properties.h"

void board_init(WINDOW *win, GameState *state);
void board_print(WINDOW *win, GameState *state);
void board_randomize(ResourceType arr[19]);

