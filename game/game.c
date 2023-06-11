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
	state->current_turn = 0;
	progress_print(win, state);
}

void progress_print(WINDOW *win, GameState *state) {
	int turn = state->current_turn;
	mvwprintw(win, 2, 2, "Current turn: %d", turn);
	mvwprintw(win, 3, 2, "Current player's development cards: %d", state->players[turn].development_cards);
	mvwprintw(win, 4, 2, "Current player's settlements: %d", state->players[turn].settlements);
	mvwprintw(win, 5, 2, "Current player's cities: %d", state->players[turn].cities);
	mvwprintw(win, 6, 2, "Current player's roads: %d", state->players[turn].roads);
	wrefresh(win);
}

void roll_dice(WINDOW *win, GameState *state) {
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	int dice = dice1 + dice2;
	mvwprintw(win, 7, 2, "Dice 1: %d", dice1);
	mvwprintw(win, 8, 2, "Dice 2: %d", dice2);
	mvwprintw(win, 9, 2, "Total: %2d", dice);
	wrefresh(win);
}
void game_loop(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state) {
	game_init(board, player, progress, state);
	menu(progress, state);
}

void startTurn(WINDOW *win, GameState *state){
	roll_dice(win, state);
	progress_print(win, state);
}

void endTurn(WINDOW *win, GameState *state){
	state->current_turn = (state->current_turn + 1) % 4;
	progress_print(win, state);
}

void menu(WINDOW *win, GameState *state){

	int ch;
	while((ch = getch()) != 'q') {
		switch(ch) {
			case 'r':
				startTurn(win, state);
				break;
			case 'e':
				endTurn(win, state);
				break;
			default:
				break;
		}
	}
}

void print_dice(WINDOW *win, int dice){
	mvwprintw(win, 2, 2, "Dice 1: %d", dice);
	wrefresh(win);
}

void buildSettlement(WINDOW *win, GameState *state){
	int turn = state->current_turn;
	if(state->players[turn].settlements > 0){
		state->players[turn].settlements--;
		progress_print(win, state);
	}
}
void buildRoad(WINDOW *win, GameState *state){
	int turn = state->current_turn;
	if(state->players[turn].roads > 0){
		state->players[turn].roads--;
		progress_print(win, state);
	}
}