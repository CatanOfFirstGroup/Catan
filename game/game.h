#pragma once
#include "board.h"
#include "player.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // for NPC to slow down


void game_init(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state);
void progress_init(WINDOW *win, GameState *state);
void progress_print(WINDOW *win, GameState *state);
void roll_dice(WINDOW *win, GameState *state);

void game_loop(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state);
void start_turn(WINDOW *win, GameState *state);
void end_turn(WINDOW *win, GameState *state);
void menu(WINDOW *win, GameState *state);
void build_settlement(WINDOW *win, GameState *state);
void build_city(WINDOW *win, GameState *state);
void build_road(WINDOW *win, GameState *state);
void buy_development_card(WINDOW *win, GameState *state);
void player_hint(WINDOW *win);
void clear_hint(WINDOW *win);

// if you are already implement this, just cover it
void calculate_points(GameState *state);


// NPC
void npc_act(WINDOW *win, GameState *state);
