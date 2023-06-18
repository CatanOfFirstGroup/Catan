#pragma once
#include "properties.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

typedef struct vertex {
	int value;
} Vertex;

typedef struct edge {
	int value;
	Vertex *vertex1;
	Vertex *vertex2;
} Edge;

typedef struct hexagon {
	int value;
	Tile *tile;
	Edge *edges[6];
	Vertex *vertices[6];
} Hexagon;

Hexagon *init_hexagons(int value, Tile *tile);
void connect_hexagons(Hexagon *hex1, Hexagon *hex2);
int longest_edge_with_same_value(Hexagon *hex, int value, int edge);
void connect_hexagon_vertices(Hexagon *hexagons[]);
