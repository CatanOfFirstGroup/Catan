#include "player.h"

void player_init(WINDOW *win, GameState *state) {
	state->players = (Player *) malloc(state->players_count * sizeof(Player));

	if(state->players == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}

	for(int i = 0; i < state->players_count; i++) {
		state->players[i].id = i;
		for(int j = 0; j < 6; j++) {
			state->players[i].resource_cards[j] = 0;// Start with no resources
		}
		state->players[i].development_cards = 0;
		state->players[i].settlements = 5;// Start with 5 settlements
		state->players[i].cities = 4;     // Start with 4 cities
		state->players[i].roads = 15;     // Start with 15 roads
	}
	for(int i = 0; i < state->players_count; i++) {
		player_print(win, &state->players[i]);
	}
}

void player_print(WINDOW *win, Player *player) {
	wattron(win, A_BOLD);
	mvwprintw(win, 0, 2, "PLAYER STATS");
	mvwprintw(win, 0, 15, "[%d]", player->id);
	wattroff(win, A_BOLD);
	mvwprintw(win, 1, 2, "Brick: %d", player->resource_cards[0]);
	mvwprintw(win, 2, 2, "Lumber: %d", player->resource_cards[1]);
	mvwprintw(win, 3, 2, "Wool: %d", player->resource_cards[2]);
	mvwprintw(win, 4, 2, "Grain: %d", player->resource_cards[3]);
	mvwprintw(win, 5, 2, "Ore: %d", player->resource_cards[4]);
	mvwprintw(win, 6, 2, "Any: %d", player->resource_cards[5]);
	mvwprintw(win, 7, 2, "Development Cards: %d", player->development_cards);
	mvwprintw(win, 8, 2, "Settlements: %d", player->settlements);
	mvwprintw(win, 9, 2, "Cities: %d", player->cities);
	mvwprintw(win, 10, 2, "Roads: %d", player->roads);
	wrefresh(win);
}
