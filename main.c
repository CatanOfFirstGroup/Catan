#include "catan.h"
// Main function
int main(){
    // Initialize the game state
    GameState state;
    setupGame(&state);
    // Print the board
    printBoard(&state);
    // Print the player
    printPlayer(&state.players[0]);
    return 0;
}