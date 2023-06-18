#pragma once
#define BOARD_SIZE 5
#define TOTAL_TILES 19
#include <stdio.h>
#include <stdlib.h>

typedef enum {
	BRICK,
	LUMBER,
	WOOL,
	GRAIN,
	ORE,
	DESERT
} ResourceType;

// disable the auto alignment of structs
#pragma pack(1)

typedef struct {
	ResourceType type;
	int number_token;
} Tile;

typedef struct {
	int id;               // Player ID
	int resource_cards[6];// Use ResourceType as index
	int development_cards;// To keep it simple, let's just have one type of development card
	int settlements;
	int cities;
	int roads;
	int longest_road;	  // 1 if the player have longest road
	int points;			  // Points of player
} Player;

typedef struct {
	Tile board[19];
	Player *players;
	int players_count;
	int current_player;
	int current_turn;
	int dice;
	// ... any other game state variables you need ...
} GameState;

typedef struct {
	Tile tiles[BOARD_SIZE * 2 - 1][BOARD_SIZE * 2 - 1];
} Board;