#pragma once
#include "catan_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void setupGame(GameState *state);                       // Initialize the game state
void endGame(GameState *state);
void startTurn(GameState *state);                       // Start a player's turn
void endTurn(GameState *state);                         // End a player's turn

void buildSettlement(GameState *state, int player);     // Build a settlement
void buildCity(GameState *state, int player);           // Build a city
void buildRoad(GameState *state, int player);           // Build a road

void buyDevelopmentCard(GameState *state, int player);  // Buy a development card
void playDevelopmentCard(GameState *state, int player); // Play a development card

void trade(GameState *state, int player);               // Trade with the bank
void rollDice(GameState *state, int player);            // Roll the dice
void moveRobber(GameState *state, int player);          // Move the robber
void stealResource(GameState *state, int player);


void printBoard(GameState *state);
void printPlayer(Player *player);
void printGameState(GameState *state);