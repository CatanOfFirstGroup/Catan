#include "option.h"

void options_init(WINDOW *win, int row, int col, GameState *state) {
    box(win, 0, 0);
    mvwprintw(win, 0, 2, "OPTIONS");
    set_options(win, row, col, state);
    wrefresh(win);
}

void set_options(WINDOW *win, int row, int col, GameState *state) {
    keypad(win, true);

    char *NPC_num[4] = {
        "Number of NPC      2",
        "Number of NPC      3",
        "Number of NPC      4",
        "Number of NPC      5"
    };

    char *options[2] = {NPC_num[state->number_of_players - 3], "Level of NPC    Easy"};

    for (int choice, highlight = 0; choice != 'q';) {
        for(int i = 0; i < 2; i++) {
            if(i == highlight) {
                wattron(win, A_REVERSE);
            }
            mvwprintw(win, (row / 2) + i, (col / 2) - 10, options[i]);
            wattroff(win, A_REVERSE);
        }
        choice = wgetch(win);
        switch(choice) {
            case KEY_UP:
                if(highlight == 0) {
                    highlight = 1;
                }
                else {
                    highlight--;
                }
                break;
            case KEY_DOWN:
                if(highlight == 1) {
                    highlight = 0;
                }
                else {
                    highlight++;
                }
                break;
            case '\n': {
                switch (highlight) {
                    case 0: {
                        int index_of_NPC_num = state->number_of_players - 3;
                        for (int input = 0; input != '\n';) {
                            mvwprintw(win, (row / 2) + 2, (col / 2) - 16, "                               ");
                            for(int i = 0; i < 4; i++) {
                                if(i == index_of_NPC_num) {
                                    wattron(win, A_REVERSE);
                                }
                                mvwprintw(win, (row / 2) + i, (col / 2) - 10, NPC_num[i]);
                                wattroff(win, A_REVERSE);
                            }
                            input = wgetch(win);
                            switch (input) {
                                case KEY_UP:
                                    if (index_of_NPC_num <= 0)
                                        index_of_NPC_num = 3;
                                    else
                                        index_of_NPC_num--;
                                    break;
                                case KEY_DOWN:
                                    if (index_of_NPC_num >= 3)
                                        index_of_NPC_num = 0;
                                    else
                                        index_of_NPC_num++;
                                    break;
                                default:    
                                    break;
                            }
                        }
                        mvwprintw(win, (row / 2) + 2, (col / 2) - 10, "                    ");
                        mvwprintw(win, (row / 2) + 3, (col / 2) - 10, "                    ");
                        state->number_of_players = index_of_NPC_num + 3;
                        options[0] = NPC_num[index_of_NPC_num];
                    }
                        break;
                    case 1:
                        mvwprintw(win, (row / 2) + 2, (col / 2) - 16, "Haha, I didn't do other levels.");
                        break;
                }
            }
                break;
            default:
                break;
        }
    }
}