#include "hexagonal.h"

Hexagon *init_hexagons(int value, Tile *tile) {
	Hexagon *hexagon = (Hexagon *) malloc(sizeof(Hexagon));
	if(hexagon == NULL) {
		printf("Failed to allocate memory for hexagon.\n");
		return NULL;
	}

	hexagon->value = value;
	hexagon->tile = tile;
	for(int i = 0; i < 6; i++) {
		hexagon->edges[i] = NULL;
		hexagon->vertices[i] = NULL;
	}

	return hexagon;
}


void connect_hexagons(Hexagon *hex1, Hexagon *hex2) {
	// Create the edge and vertices
	Edge *edge = (Edge *) malloc(sizeof(Edge));
	Vertex *vertex1 = (Vertex *) malloc(sizeof(Vertex));
	Vertex *vertex2 = (Vertex *) malloc(sizeof(Vertex));

	edge->value = 0;   // Or any value you need
	vertex1->value = 0;// Or any value you need
	vertex2->value = 0;// Or any value you need

	edge->vertex1 = vertex1;
	edge->vertex2 = vertex2;

	// Find the first NULL slot in the edges and vertices arrays and connect the hexagons
	for(int i = 0; i < 6; i++) {
		if(hex1->edges[i] == NULL && hex1->vertices[i] == NULL) {
			hex1->edges[i] = edge;
			hex1->vertices[i] = vertex1;
			break;
		}
	}

	for(int i = 0; i < 6; i++) {
		if(hex2->edges[i] == NULL && hex2->vertices[i] == NULL) {
			hex2->edges[i] = edge;
			hex2->vertices[i] = vertex2;
			break;
		}
	}
}
void connect_hexagon_vertices(Hexagon *hexagons[]) {
	/*
       0 1 2
       3 4 5 6
     7 8 9 10 11
     12 13 14 15
       16 17 18

    */
	// row 1
	connect_hexagons(hexagons[0], hexagons[1]);
	connect_hexagons(hexagons[1], hexagons[2]);

	// row 2
	connect_hexagons(hexagons[3], hexagons[4]);
	connect_hexagons(hexagons[4], hexagons[5]);
	connect_hexagons(hexagons[5], hexagons[6]);
	connect_hexagons(hexagons[0], hexagons[3]);
	connect_hexagons(hexagons[0], hexagons[4]);
	connect_hexagons(hexagons[1], hexagons[4]);
	connect_hexagons(hexagons[1], hexagons[5]);
	connect_hexagons(hexagons[2], hexagons[5]);
	connect_hexagons(hexagons[2], hexagons[6]);

	// row 3
	connect_hexagons(hexagons[7], hexagons[8]);
	connect_hexagons(hexagons[8], hexagons[9]);
	connect_hexagons(hexagons[9], hexagons[10]);
	connect_hexagons(hexagons[10], hexagons[11]);
	connect_hexagons(hexagons[3], hexagons[7]);
	connect_hexagons(hexagons[3], hexagons[8]);
	connect_hexagons(hexagons[4], hexagons[8]);
	connect_hexagons(hexagons[4], hexagons[9]);
	connect_hexagons(hexagons[5], hexagons[9]);
	connect_hexagons(hexagons[5], hexagons[10]);
	connect_hexagons(hexagons[6], hexagons[10]);
	connect_hexagons(hexagons[6], hexagons[11]);

	// row 4
	connect_hexagons(hexagons[12], hexagons[13]);
	connect_hexagons(hexagons[13], hexagons[14]);
	connect_hexagons(hexagons[14], hexagons[15]);
	connect_hexagons(hexagons[7], hexagons[12]);
	connect_hexagons(hexagons[8], hexagons[12]);
	connect_hexagons(hexagons[8], hexagons[13]);
	connect_hexagons(hexagons[9], hexagons[14]);
	connect_hexagons(hexagons[9], hexagons[13]);
	connect_hexagons(hexagons[10], hexagons[15]);
	connect_hexagons(hexagons[10], hexagons[14]);
	connect_hexagons(hexagons[11], hexagons[15]);

	// row 5
	connect_hexagons(hexagons[16], hexagons[17]);
	connect_hexagons(hexagons[17], hexagons[18]);
	connect_hexagons(hexagons[12], hexagons[16]);
	connect_hexagons(hexagons[13], hexagons[17]);
	connect_hexagons(hexagons[13], hexagons[16]);
	connect_hexagons(hexagons[14], hexagons[17]);
	connect_hexagons(hexagons[14], hexagons[18]);
	connect_hexagons(hexagons[15], hexagons[18]);
}



// int longest_edge_with_same_value(Hexagon *hex, int value, int edge) {
// 	if(hex == NULL || hex->value != value)
// 		return 0;

// 	Edge *neighbor = hex->edges[edge];
// 	if(neighbor == NULL)
// 		return 1;

// 	return 1 + longest_edge_with_same_value(neighbor, value, edge);
// }


