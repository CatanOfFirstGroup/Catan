#include "function/tool.h"
#include "game/game.h"
#include <ncurses.h>

int main() {
    // Initialization
    initscr();
    cbreak();
    noecho();

    // Read the terminal screen size
    int row, col;
    getmaxyx(stdscr, row, col);
    curs_set(0);
    refresh();

    // Generate startup screen
    WINDOW *startup = newwin(row, col, 0, 0);

    // Generate game screens
    WINDOW *board = newwin(row, col / 2, 0, 0);
    WINDOW *player = newwin(row / 2, col - (col / 2), 0, col / 2);
    WINDOW *progress = newwin(row - (row / 2), col - (col / 2), row / 2, col / 2);

    // Generate option screens
    WINDOW *options = newwin(row, col, 0, 0);

    GameState state;
    state.number_of_players = 4;
    for (int action;;) {
        action = startup_init(startup, row, col);
        switch(action) {
            case 0: 
                clear_screen();
                game_init(board, player, progress, &state);
                game_loop(board, player, progress, &state);
                break;
            case 1:
                options_init(options, row, col, &state);
                break;
            case 2:
                endwin();
                return 0;
        }
    }

    return 0;
}
