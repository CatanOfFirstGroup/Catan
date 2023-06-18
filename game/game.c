#include "game.h"
#include "hexagonal.h"
#include "../function/tool.h"

void game_init(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state) {
	box(board, 0, 0);
	box(player, 0, 0);
	box(progress, 0, 0);
	PRINT_BOLD_LINE(board, 0, 2, "GAME BOARD");
	PRINT_BOLD_LINE(progress, 0, 2, "GAME STATS");
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
	if(player == 0) {
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
<<<<<<< HEAD
	mvwprintw(win, 7, 2, "Current player's points: %d", state->players[player].points);
	if (player == 0){
        player_hint(win);
=======
	if(player == 0) {
		player_hint(win);
>>>>>>> ae3fea182c335712c5d4dc69bf358c5f13580d68
	}
	wrefresh(win);
}

void roll_dice(WINDOW *win, GameState *state) {
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	int dice = dice1 + dice2;
	state->dice = dice;
<<<<<<< HEAD
	mvwprintw(win, 8, 2, "Dice 1: %d", dice1);
	mvwprintw(win, 8, 14, "Dice 2: %d", dice2);
	mvwprintw(win, 9, 2, "Total: %2d", dice);
=======

	mvwprintw(win, 7, 2, "Dice 1: %d", dice1);
	mvwprintw(win, 7, 14, "Dice 2: %d", dice2);
	mvwprintw(win, 8, 2, "Total: %2d", dice);
>>>>>>> ae3fea182c335712c5d4dc69bf358c5f13580d68
	wrefresh(win);
}

void start_turn(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state) {
	roll_dice(progress, state);
	get_resource(board, player, progress, state);
<<<<<<< HEAD
=======
	// get_resources();
>>>>>>> ae3fea182c335712c5d4dc69bf358c5f13580d68
	board_print(board, state);
	player_print(player, &state->players[0]);
	progress_print(progress, state);
}

void end_turn(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state) {
	state->current_turn++;
	state->current_player = state->current_turn % state->players_count;
	calculate_points(state);
	board_print(board, state);
	player_print(player, &state->players[0]);
	progress_print(progress, state);
}

void game_loop(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state) {
	int ch;
	int dice_rolled = 0;// to check if dice has been rolled
	while((ch = getch()) != 'q') {
		switch(ch) {
			case 'r':
				if(dice_rolled == 0) {
					start_turn(board, player, progress, state);
					dice_rolled = 1;
					show_state(progress, "Roll dices");
				}
				else
					show_state(progress, "Dice already rolled");
				break;
			case 'e':
				if(dice_rolled) {
					end_turn(board, player, progress, state);
					clear_hint(progress);
					for(int i = 1; i < state->players_count; i++)
						npc_act(board, player, progress, state);
					dice_rolled = 0;
				}
				else
					show_state(progress, "You have not rolled dice");
				break;
			case '2':
<<<<<<< HEAD
				if (build_city(board, player, progress, state) == 0)
=======
				if(/*there is a settlement*/ 0)
					build_city(board, player, progress, state);
				else
>>>>>>> ae3fea182c335712c5d4dc69bf358c5f13580d68
					build_settlement(board, player, progress, state);
				break;
			case '3':
				build_road(board, player, progress, state);
				break;
			case 'f':
				buy_development_card(board, player, progress, state);
				break;
			default:
				break;
		}
	}
	free(state->players);
	wclear(board);
	wclear(player);
	wclear(progress);
}

void player_hint(WINDOW *win) {
<<<<<<< HEAD
    mvwprintw(win, 10, 2, "It's your turn!");
    mvwprintw(win, 11, 2, "Press 'r' to roll dice");
    mvwprintw(win, 12, 2, "Press '2' to build city or settlement");
	mvwprintw(win, 13, 2, "Press '3' to build road");
	mvwprintw(win, 14, 2, "Press 'f' to buy development card");
	mvwprintw(win, 15, 2, "Press 'e' to end turn");
	mvwprintw(win, 16, 2, "Press 'q' to quit game");
    wrefresh(win);
}

void clear_hint(WINDOW *win) {
    mvwprintw(win, 10, 2, "                                       ");
    mvwprintw(win, 11, 2, "                                       ");
    mvwprintw(win, 12, 2, "                                       ");
	mvwprintw(win, 13, 2, "                                       ");
	mvwprintw(win, 14, 2, "                                       ");
	mvwprintw(win, 15, 2, "                                       ");
	mvwprintw(win, 16, 2, "                                       ");
    wrefresh(win);
=======
	mvwprintw(win, 9, 2, "It's your turn!");
	mvwprintw(win, 10, 2, "Press 'r' to roll dice");
	mvwprintw(win, 11, 2, "Press '2' to build city or settlement");
	mvwprintw(win, 12, 2, "Press '3' to build road");
	mvwprintw(win, 13, 2, "Press 'e' to end turn");
	wrefresh(win);
}

void clear_hint(WINDOW *win) {
	mvwprintw(win, 9, 2, "                                       ");
	mvwprintw(win, 10, 2, "                                      ");
	mvwprintw(win, 11, 2, "                                      ");
	mvwprintw(win, 12, 2, "                                      ");
	mvwprintw(win, 13, 2, "                                      ");
	wrefresh(win);
>>>>>>> ae3fea182c335712c5d4dc69bf358c5f13580d68
}

void build_settlement(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state) {
	int current_player = state->current_player;
	int *pBricks = &state->players[current_player].resource_cards[BRICK];
	int *pLumbers = &state->players[current_player].resource_cards[LUMBER];
	int *pWools = &state->players[current_player].resource_cards[WOOL];
	int *pGrains = &state->players[current_player].resource_cards[GRAIN];
	int *pSettlements = &state->players[current_player].settlements;
	if((*pBricks) >= 1 &&
	   (*pLumbers) >= 1 &&
	   (*pWools) >= 1 &&
	   (*pGrains) >= 1 &&
	   (*pSettlements) > 0) {
		(*pBricks)--;
		(*pLumbers)--;
		(*pWools)--;
		(*pGrains)--;
		(*pSettlements)--;
		// set_settlement();
		board_print(board, state);
		player_print(player, &state->players[0]);
		progress_print(progress, state);
		show_state(progress, "Build settlement successfully");
	}
	else
		show_state(progress, "Build settlement failed");
}
int build_city(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state) {
	int current_player = state->current_player;
	int *pGrains = &state->players[current_player].resource_cards[GRAIN];
	int *pOre = &state->players[current_player].resource_cards[ORE];
	int *pCities = &state->players[current_player].cities;
	int *pSettlements = &state->players[current_player].settlements;
	if((*pGrains) >= 2 &&
	   (*pOre) >= 3 &&
	   (*pCities) > 0 &&
	   (*pSettlements) < 5) {
		(*pGrains) -= 2;
		(*pOre) -= 3;
		(*pCities)--;
		(*pSettlements)++;
		// set_city();
		board_print(board, state);
		player_print(player, &state->players[0]);
		progress_print(progress, state);
		show_state(progress, "Build city successfully");
		return 1;
	}
<<<<<<< HEAD
	show_state(progress, "Build city failed");
	return 0;
=======
    // select hex vertex to build city
    
    
>>>>>>> ae3fea182c335712c5d4dc69bf358c5f13580d68
}
void build_road(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state) {
	int current_player = state->current_player;
	int *pBricks = &state->players[current_player].resource_cards[BRICK];
	int *pLumbers = &state->players[current_player].resource_cards[LUMBER];
	int *pRoads = &state->players[current_player].roads;
	if((*pBricks) >= 1 &&
	   (*pLumbers) >= 1 &&
	   (*pRoads) > 0) {
		(*pBricks)--;
		(*pLumbers)--;
		(*pRoads)--;
		// set_road();
		board_print(board, state);
		player_print(player, &state->players[0]);
		progress_print(progress, state);
		show_state(progress, "Build road successfully");
	}
	else
		show_state(progress, "Build road failed");
}
void buy_development_card(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state) {
	int current_player = state->current_player;
	int *pWools = &state->players[current_player].resource_cards[WOOL];
	int *pGrains = &state->players[current_player].resource_cards[GRAIN];
	int *pOre = &state->players[current_player].resource_cards[ORE];
	int *pDevelopment_cards = &state->players[current_player].development_cards;
	if((*pWools) >= 1 &&
	   (*pGrains) >= 1 &&
	   (*pOre) >= 1) {
		(*pWools)--;
		(*pGrains)--;
		(*pOre)--;
		(*pDevelopment_cards)++;
		board_print(board, state);
		player_print(player, &state->players[0]);
		progress_print(progress, state);
		show_state(progress, "Buy development card successfully");
	}
	else
		show_state(progress, "Buy development card failed");
}

// if you are already implement this, just cover it
void calculate_points(GameState *state) {
<<<<<<< HEAD
	check_longest_road(state);
	for (int i = 0; i < state->players_count; i++) {
=======
	// check_longest_road();
	for(int i = 0; i < state->players_count; i++) {
>>>>>>> ae3fea182c335712c5d4dc69bf358c5f13580d68
		int points = 0;
		points += 5 - state->players[i].settlements;
		points += 2 * (4 - state->players[i].cities);
		if(state->players[i].longest_road)
			points += 2;
		points += state->players[i].development_cards;
		if (points >= 10)
			end_game(i);
		state->players[i].points = points;
	}
}

void check_longest_road(GameState *state) {
	int longest = 0, index[6] = {0};
	for (int i = 0; i < state->players_count; i++) {
		int temp = 15 - state->players[i].roads;
		if (temp)
			if (longest < temp) {
				longest = temp;
				for (int k = 0; k < 6; k++) {
					index[k] = 0;
				}
				index[i] = 1;
			}
			else if (longest == temp) {
				index[i] = 1;
			}
	}
	for (int i = 0; i < state->players_count; i++) {
		state->players[i].longest_road = index[i];
	}
}

// NPC
void npc_act(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state) {
	start_turn(board, player, progress, state);
	show_state(progress, "Roll dices");
	usleep(500000);
	show_state(progress, "Thinking");
	usleep(500000);
	int current_player = state->current_player;
	int bricks = state->players[current_player].resource_cards[BRICK];
	int lumbers = state->players[current_player].resource_cards[LUMBER];
	int wools = state->players[current_player].resource_cards[WOOL];
	int grains = state->players[current_player].resource_cards[GRAIN];
	int ores = state->players[current_player].resource_cards[ORE];
	int settlements_available = state->players[current_player].settlements;
	int cities_available = state->players[current_player].cities;
	int roads_available = state->players[current_player].roads;
	int points = state->players[current_player].points;
<<<<<<< HEAD
	if (wools > 0 &&
		grains > 0 &&
		ores > 0 &&
		points == 9) {
		show_state(progress, "Going to win!");
=======
	if(wools > 0 &&
	   grains > 0 &&
	   ores > 0 &&
	   points == 9) {
		npc_show_state(progress, "Going to win!");
>>>>>>> ae3fea182c335712c5d4dc69bf358c5f13580d68
		usleep(500000);
		buy_development_card(board, player, progress, state);
		end_turn(board, player, progress, state);
	}
<<<<<<< HEAD
	if (bricks >= 3 &&
		grains >= 2 &&
		cities_available > 0 &&
		settlements_available < 5) {
		show_state(progress, "Building city");
		usleep(500000);
		build_city(board, player, progress, state);
	}
	if (bricks > 2 &&
		lumbers > 2 &&
		wools > 2 &&
		grains > 2 &&
		settlements_available > 0) {
		show_state(progress, "Building settlement");
		usleep(500000);
		build_settlement(board, player, progress, state);
	}
	if (bricks > 2 &&
		lumbers > 2 &&
		roads_available > 0) {
		show_state(progress, "Building road");
		usleep(500000);
		build_road(board, player, progress, state);
	}
	if (wools > 3 &&
	    grains > 3 &&
		ores > 0) {
		show_state(progress, "Buying Development card");
=======
	if(bricks >= 3 &&
	   grains >= 2 &&
	   cities_available > 0 &&
	   settlements_available < 5) {
		npc_show_state(progress, "Building city");
		usleep(500000);
		build_city(board, player, progress, state);
	}
	if(bricks > 2 &&
	   lumbers > 2 &&
	   wools > 2 &&
	   grains > 2 &&
	   settlements_available > 0) {
		npc_show_state(progress, "Building settlement");
		usleep(500000);
		build_settlement(board, player, progress, state);
	}
	if(bricks > 2 &&
	   lumbers > 2 &&
	   roads_available > 0) {
		npc_show_state(progress, "Building road");
		usleep(500000);
		build_road(board, player, progress, state);
	}
	if(wools > 3 &&
	   grains > 3 &&
	   ores > 0) {
		npc_show_state(progress, "Buying Development card");
>>>>>>> ae3fea182c335712c5d4dc69bf358c5f13580d68
		usleep(500000);
		buy_development_card(board, player, progress, state);
	}
	clear_state(progress);
	end_turn(board, player, progress, state);
}

void show_state(WINDOW *win, const char *str) {
	clear_state(win);
	mvwprintw(win, 17, 2, "%s", str);
	wrefresh(win);
}

void clear_state(WINDOW *win) {
	mvwprintw(win, 17, 2, "                                            ");
	wrefresh(win);
}

<<<<<<< HEAD
void get_resource(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state) {
    int dice = state->dice;
    for (int i = 0; i < state->players_count; i++) {
        int *pBricks = &state->players[i].resource_cards[BRICK];
        int *pLumbers = &state->players[i].resource_cards[LUMBER];
        int *pWools = &state->players[i].resource_cards[WOOL];
        int *pGrains = &state->players[i].resource_cards[GRAIN];
        int *pOre = &state->players[i].resource_cards[ORE];
        for (int j = 0; j < 19; j++) {
            if (state->board[j].number_token == dice) {
                switch (state->board[j].type) {
                    case BRICK:
                        (*pBricks)++;
                        break;
                    case LUMBER:
                        (*pLumbers)++;
                        break;
                    case WOOL:
                        (*pWools)++;
                        break;
                    case GRAIN:
                        (*pGrains)++;
                        break;
                    case ORE:
                        (*pOre)++;
                        break;
                }
=======

void get_resource(WINDOW *board, WINDOW *player, WINDOW *progress, GameState *state) {
    int current_player = state->current_player;
    int dice = state->dice;
    int *pBricks = &state->players[current_player].resource_cards[BRICK];
    int *pLumbers = &state->players[current_player].resource_cards[LUMBER];
    int *pWools = &state->players[current_player].resource_cards[WOOL];
    int *pGrains = &state->players[current_player].resource_cards[GRAIN];
    int *pOre = &state->players[current_player].resource_cards[ORE];
    for (int i = 0; i < 19; i++) {
        if (state->board[i].number_token == dice) {
            if (state->board[i].type == BRICK) {
                (*pBricks)++;
            } else if (state->board[i].type == LUMBER) {
                (*pLumbers)++;
            } else if (state->board[i].type == WOOL) {
                (*pWools)++;
            } else if (state->board[i].type == GRAIN) {
                (*pGrains)++;
            } else if (state->board[i].type == ORE) {
                (*pOre)++;
>>>>>>> ae3fea182c335712c5d4dc69bf358c5f13580d68
            }
        }
    }
    board_print(board, state);
    player_print(player, &state->players[0]);
    progress_print(progress, state);
<<<<<<< HEAD
}

void end_game(int player) {
	clear_screen();
	int row, col;
	getmaxyx(stdscr, row, col);
	WINDOW *ending = newwin(row, col, 0, 0);
	wattron(ending, A_BOLD | A_REVERSE);
	char end_string[20] = {0};
	if (player == 0)
		sprintf(end_string, "YOU WIN!");
	else
		sprintf(end_string, "NPC %d WIN!", player);
	int offset = strlen(end_string) / 2;
	mvwprintw(ending, row / 2, (col / 2) - offset, end_string);
	mvwprintw(ending, (row / 2) + 1, (col / 2) - 11, "Press any key to leave");
	keypad(ending, TRUE);
	wgetch(ending);
	endwin();
	exit(EXIT_SUCCESS);
=======
>>>>>>> ae3fea182c335712c5d4dc69bf358c5f13580d68
}