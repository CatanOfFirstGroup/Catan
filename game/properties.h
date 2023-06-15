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

typedef struct {
    int x;
    int y;
} Coordinates;

typedef struct {
    ResourceType type;
    int number_token;
} Tile;

typedef struct _vertex {
    int value;
} Vertex;

typedef struct _edge {
    int value;
    Vertex *vertex1;
    Vertex *vertex2;
} Edge;

typedef struct _hexagon {
    int value;
    Tile tile; // Store the tile data here
    Edge *edges[6];
    Vertex *vertices[6];
} Hexagon;

typedef struct {
    int id;                // Player ID
    int resource_cards[6]; // Use ResourceType as index
    int development_cards; // To keep it simple, let's just have one type of development card
    int settlements;
    int cities;
    int roads;
} Player;

typedef struct {
    Tile board[19];
    Player *players;
    int players_count;
    int current_player;
    int current_turn;
    Hexagon *hexagons[BOARD_SIZE][BOARD_SIZE];
    // ... any other game state variables you need ...
} GameState;

typedef struct {
    Tile tiles[BOARD_SIZE * 2 - 1][BOARD_SIZE * 2 - 1];
} Board;
