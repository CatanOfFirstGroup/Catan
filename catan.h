#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 5
#define TOTAL_TILES 19

typedef enum { BRICK,
               LUMBER,
               WOOL,
               GRAIN,
               ORE,
               DESERT
} ResourceType;

typedef struct {
    ResourceType type;
    int numberToken;
} Tile;

typedef struct {
    int resourceCards[6]; // Use ResourceType as index
    int developmentCards; // To keep it simple, let's just have one type of development card
    int settlements;
    int cities;
    int roads;
} Player;

typedef struct {
    Tile board[5][5];
    Player players[4];
    int currentTurn;
    // ... any other game state variables you need ...
} GameState;

typedef struct {
    Tile tiles[BOARD_SIZE * 2 - 1][BOARD_SIZE * 2 - 1];
} Board;

void setupGame(GameState *state);
void startTurn(GameState *state);
void endTurn(GameState *state);
void buildSettlement(GameState *state, int player);
void buildCity(GameState *state, int player);
void buildRoad(GameState *state, int player);
void buyDevelopmentCard(GameState *state, int player);
void playDevelopmentCard(GameState *state, int player);
void trade(GameState *state, int player);
void rollDice(GameState *state, int player);
void moveRobber(GameState *state, int player);
void stealResource(GameState *state, int player);
void endGame(GameState *state);
void printBoard(GameState *state);
void printPlayer(Player *player);
