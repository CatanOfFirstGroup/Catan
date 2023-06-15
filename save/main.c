#include "catan.h"
// Main function
int main() {
    // Initialize the game state
    GameState state;
    setupGame(&state);

    // game loop
    while (1) {
        // Print the board
        printBoard(&state);
        // Print the player
        printPlayer(&state.players[state.currentTurn]);
        startTurn(&state);
        // Print the current turn
        printf("Current turn: %d\n", state.currentTurn);
        // Print the current player's resources
        printf("Current player's resources: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", state.players[state.currentTurn].resourceCards[i]);
        }
        printf("\n");
        // Print the current player's development cards
        printf("Current player's development cards: %d\n", state.players[state.currentTurn].developmentCards);
        // Print the current player's settlements
        printf("Current player's settlements: %d\n", state.players[state.currentTurn].settlements);
        // Print the current player's cities
        printf("Current player's cities: %d\n", state.players[state.currentTurn].cities);
        // Print the current player's roads
        printf("Current player's roads: %d\n", state.players[state.currentTurn].roads);
        
        break;
    }

    return 0;
}