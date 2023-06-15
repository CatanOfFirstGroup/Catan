#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "properties.h"




Hexagon* init_hexagon(Tile tile);
void connect_hexagons(Hexagon* hex1, Hexagon* hex2, int edgeValue, int vertexValue) ;
int longest_edge_with_same_value(Hexagon* hex, int value, int edge);
void print_hexagon(Hexagon* hex);
void print_hexagons(Hexagon** hexagons, int rows, int cols);
