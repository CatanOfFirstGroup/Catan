#include "catan.h"

void setupGame(GameState *state) {
    // Set up the board
    int layout[5] = {3, 4, 5, 4, 3};
    int spaces[5] = {2, 1, 0, 1, 2};
    ResourceType resources[5][5] = {
        {DESERT, BRICK, LUMBER},
        {WOOL, GRAIN, ORE, BRICK},
        {LUMBER, WOOL, GRAIN, ORE, BRICK},
        {GRAIN, ORE, LUMBER, WOOL},
        {BRICK, GRAIN, ORE}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < layout[i]; j++) {
            state->board[i][j + spaces[i]].type = resources[i][j];
            state->board[i][j + spaces[i]].numberToken = (rand() % 6) + 1; // Random number between 1 and 6
        }
    }

    // Set up the players
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            state->players[i].resourceCards[j] = 0; // Start with no resources
        }
        state->players[i].developmentCards = 0;
        state->players[i].settlements = 5; // Start with 5 settlements
        state->players[i].cities = 4; // Start with 4 cities
        state->players[i].roads = 15; // Start with 15 roads
    }

    // Set the current turn to the first player
    state->currentTurn = 0;
}

void printBoard(GameState *state) {
    int layout[5] = {3, 4, 5, 4, 3};
    int spaces[5] = {2, 1, 0, 1, 2};

    for (int i = 0; i < 5; i++) {
        for (int s = 0; s < spaces[i]; s++) {
            printf("    ");
        }
        for (int j = 0; j < layout[i]; j++) {
            char resource;
            switch (state->board[i][j + spaces[i]].type) {
                case BRICK:   resource = 'B'; break;
                case LUMBER:  resource = 'L'; break;
                case WOOL:    resource = 'W'; break;
                case GRAIN:   resource = 'G'; break;
                case ORE:     resource = 'O'; break;
                case DESERT:  resource = 'D'; break;
                default:      resource = ' '; break; 
            }
            printf(" %c%d ", resource, state->board[i][j + spaces[i]].numberToken);
        }
        printf("\n");
    }
}

void printPlayer(Player *player) {
    printf("Player:\n");
    printf("    Brick: %d\n", player->resourceCards[0]);
    printf("    Lumber: %d\n", player->resourceCards[1]);
    printf("    Wool: %d\n", player->resourceCards[2]);
    printf("    Grain: %d\n", player->resourceCards[3]);
    printf("    Ore: %d\n", player->resourceCards[4]);
    printf("    Any: %d\n", player->resourceCards[5]);
    printf("    Development Cards: %d\n", player->developmentCards);
    printf("    Settlements: %d\n", player->settlements);
    printf("    Cities: %d\n", player->cities);
    printf("    Roads: %d\n", player->roads);
}
