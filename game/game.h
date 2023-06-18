#pragma once
#include "board.h"
#include "player.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // for NPC to slow down
#include <string.h>


void game_init(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state);
void progress_init(WINDOW *win, GameState *state);
void progress_print(WINDOW *win, GameState *state);
void roll_dice(WINDOW *win, GameState *state);

void start_turn(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state);
void end_turn(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state);
void game_loop(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state);
void build_settlement(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state);
int build_city(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state);
void build_road(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state);
void buy_development_card(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state);
void get_resource(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state);



void player_hint(WINDOW *win);
void clear_hint(WINDOW *win);
void get_resource(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state);
void end_game(int player);
void show_state(WINDOW *win, const char *string);
void clear_state(WINDOW *win);

// if you are already implement this, just cover it
void calculate_points(GameState *state);
void check_longest_road(GameState *state);

// NPC
void npc_act(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state);
