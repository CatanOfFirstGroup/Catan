#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct vertex {
    int value;
} Vertex;

typedef struct edge {
    int value;
    Vertex* vertex1;
    Vertex* vertex2;
} Edge;

typedef struct hexagon {
    int value;
    Edge* edges[6];
    Vertex* vertices[6];
} Hexagon;

Hexagon* init_hexagon(int value);
void connect_hexagons(Hexagon* hex1, Hexagon* hex2, int edgeValue, int vertexValue) ;
int longest_edge_with_same_value(Hexagon* hex, int value, int edge);
void print_hexagon(Hexagon* hex);
void print_hexagons(Hexagon** hexagons, int rows, int cols);