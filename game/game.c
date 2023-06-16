#include "game.h"

void game_init(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state) {
	box(board, 0, 0);
	box(player, 0, 0);
	box(progress, 0, 0);
	mvwprintw(board, 0, 2, "GAME BOARD");

	mvwprintw(progress, 0, 2, "GAME STATS");
	wrefresh(board);
	wrefresh(player);
	wrefresh(progress);

	board_init(board, state);
	player_init(player, state);
	progress_init(progress, state);
}

void progress_init(WINDOW *win, GameState *state) {
	state->current_player = 0;
	state->current_turn = 0;
	progress_print(win, state);
}

void progress_print(WINDOW *win, GameState *state) {
	int player = state->current_player;
	mvwprintw(win, 1, 2, "Current player: ");
	if (player == 0) {
		mvwprintw(win, 1, 18, "YOU  ");
	}
	else {
		mvwprintw(win, 1, 18, "NPC %d", player);
	}
	mvwprintw(win, 2, 2, "Current turn: %d", state->current_turn);
	mvwprintw(win, 3, 2, "Current player's development cards: %d", state->players[player].development_cards);
	mvwprintw(win, 4, 2, "Current player's settlements available: %d", state->players[player].settlements);
	mvwprintw(win, 5, 2, "Current player's cities available: %d", state->players[player].cities);
	mvwprintw(win, 6, 2, "Current player's roads available: %d", state->players[player].roads);
	if (player == 0){
        player_hint(win);
	}
	wrefresh(win);
}

void roll_dice(WINDOW *win, GameState *state) {
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	int dice = dice1 + dice2;
	mvwprintw(win, 7, 2, "Dice 1: %d", dice1);
	mvwprintw(win, 7, 14, "Dice 2: %d", dice2);
	mvwprintw(win, 8, 2, "Total: %2d", dice);
	wrefresh(win);
}
void game_loop(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state) {
	board_print(board, state);
	player_print(player, &state->players[1]);
	progress_print(progress, state);
	menu(progress, state);
}

void start_turn(WINDOW *win, GameState *state){
	roll_dice(win, state);
	progress_print(win, state);
}

void end_turn(WINDOW *win, GameState *state){
	state->current_turn++;
	state->current_player = state->current_turn % state->players_count;
	calculate_points(state);
	progress_print(win, state);
}

void menu(WINDOW *win, GameState *state){
	int ch;
	int dice_rolled = 0; // to check if dice has been rolled
	while((ch = getch()) != 'q') {
		switch(ch) {
			case 'r':
				if(dice_rolled == 0) {
					start_turn(win, state);
					dice_rolled = 1;
				}
				break;
			case 'e':
				if (dice_rolled) {
					end_turn(win, state);
					clear_hint(win);
					for (int i = 1; i < state->players_count; i++)
						npc_act(win, state);
					dice_rolled = 0;
				}
				break;
			default:
				break;
		}
	}
	free(state->players);
}

void player_hint(WINDOW *win) {
    mvwprintw(win, 9, 2, "It's your turn!");
    mvwprintw(win, 10, 2, "Press 'r' to roll dice");
    mvwprintw(win, 11, 2, "Press 'e' to end turn");
    wrefresh(win);
}

void clear_hint(WINDOW *win) {
    mvwprintw(win, 9, 2, "                        ");
    mvwprintw(win, 10, 2, "                       ");
    mvwprintw(win, 11, 2, "                       ");
    wrefresh(win);
}

void build_settlement(WINDOW *win, GameState *state){
	int player = state->current_player;
	if(state->players[player].settlements > 0){
		state->players[player].settlements--;
		progress_print(win, state);
	}
}
void build_city(WINDOW *win, GameState *state) {
	int player = state->current_player;
	if(state->players[player].cities > 0){
		state->players[player].cities--;
		state->players[player].settlements++;
		progress_print(win, state);
	}
}
void build_road(WINDOW *win, GameState *state){
	int player = state->current_player;
	if(state->players[player].roads > 0){
		state->players[player].roads--;
		progress_print(win, state);
	}
}
void buy_development_card(WINDOW *win, GameState *state) {
	int player = state->current_player;
	state->players[player].development_cards++;
}

// if you are already implement this, just cover it
void calculate_points(GameState *state) {
	for (int i = 0; i < state->players_count; i++) {
		int points = 0;
		points += 5 - state->players[i].settlements;
		points += 2 * (4 - state->players[i].cities);
		if (state->players[i].longest_road)
			points += 2;
		points += state->players[i].development_cards;
		// if (points >= 10)
		// 	end_game(i);
		state->players[i].points = points;
	}
}

// NPC
void npc_act(WINDOW *win, GameState *state) {
	sleep(1);
	start_turn(win, state);
	int player = state->current_player;
	int bricks = state->players[player].resource_cards[BRICK];
	int lumbers = state->players[player].resource_cards[LUMBER];
	int wools = state->players[player].resource_cards[WOOL];
	int grains = state->players[player].resource_cards[GRAIN];
	int ores = state->players[player].resource_cards[ORE];
	int settlements_available = state->players[player].settlements;
	int cities_available = state->players[player].cities;
	int roads_available = state->players[player].roads;
	int points = state->players[player].points;
	if (wools > 0 &&
		grains > 0 &&
		ores > 0 &&
		points == 9) {
		// buy development card
		end_turn(win, state);
	}
	if (bricks >= 3 &&
		grains >= 2 &&
		cities_available > 0 &&
		settlements_available < 5) {
		build_city(win, state);
	}
	if (bricks > 2 &&
		lumbers > 2 &&
		wools > 2 &&
		grains > 2 &&
		settlements_available > 0) {
		build_settlement(win, state);
	}
	if (bricks > 2 &&
		lumbers > 2 &&
		roads_available > 0) {
		build_road(win, state);
	}
	if (wools > 3 &&
	    grains > 3 &&
		ores > 0) {
		// buy development card
	}
	sleep(1);
	end_turn(win, state);
}
