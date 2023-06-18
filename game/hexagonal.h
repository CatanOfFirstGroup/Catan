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
<<<<<<< HEAD
// int longest_edge_with_same_value(Hexagon *hex, int value, int edge);
void print_hexagon(Hexagon *hex);
void print_hexagons(Hexagon **hexagons, int rows, int cols);
=======
int longest_edge_with_same_value(Hexagon *hex, int value, int edge);
>>>>>>> ae3fea182c335712c5d4dc69bf358c5f13580d68
void connect_hexagon_vertices(Hexagon *hexagons[]);
