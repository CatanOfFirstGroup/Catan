#include "hexagonal.h"
Hexagon* init_hexagon(Tile tile) {
    Hexagon* new_hex = malloc(sizeof(Hexagon));
    if(new_hex == NULL) {
        printf("Error! Memory was not allocated.");
        exit(1); // or handle the error in a way suitable for your program
    }

    new_hex->value = 0;
    new_hex->tile = tile;

    // Initialize edges and vertices to NULL
    for(int i = 0; i < 6; i++) {
        new_hex->edges[i] = NULL;
        new_hex->vertices[i] = NULL;
    }

    return new_hex;
}

void connect_hexagons(Hexagon* hex1, Hexagon* hex2, int edgeValue, int vertexValue) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    if (edge == NULL) {
        printf("Failed to allocate memory for edge.\n");
        return;
    }

    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    if (vertex == NULL) {
        printf("Failed to allocate memory for vertex.\n");
        return;
    }

    edge->value = edgeValue;
    edge->vertex1 = vertex;
    edge->vertex2 = vertex;
    vertex->value = vertexValue;

    for (int i = 0; i < 6; i++) {
        if (hex1->edges[i] == NULL) {
            hex1->edges[i] = edge;
            hex1->vertices[i] = vertex;
            break;
        }
    }

    for (int i = 0; i < 6; i++) {
        if (hex2->edges[i] == NULL) {
            hex2->edges[i] = edge;
            hex2->vertices[i] = vertex;
            break;
        }
    }
}

void print_hexagon(Hexagon* hex) {
    printf("Hexagon value: %d\n", hex->value);
    for (int i = 0; i < 6; i++) {
        if (hex->edges[i] != NULL) {
            printf("Edge %d value: %d\n", i, hex->edges[i]->value);
            printf("Vertex %d value: %d\n", i, hex->vertices[i]->value);
        }
    }
}

int longest_edge_with_same_value(Hexagon* hex, int value, int edge) {
    if (hex == NULL || hex->value != value)
        return 0;

    Edge* neighbor = hex->edges[edge];
    if (neighbor == NULL)
        return 1;

    return 1 + longest_edge_with_same_value(neighbor, value, edge);
}
void print_hexagons(Hexagon** hexagons, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        // Print leading spaces for offset
        for (int k = 0; k < i; k++) {
            printf("   ");
        }

        // Print hexagons and vertices
        for (int j = 0; j < cols; j++) {
            printf(" / \\ ");
            if (j < cols - 1) {
                printf("--");
            }
        }
        printf("\n");

        // Print leading spaces for offset
        for (int k = 0; k < i; k++) {
            printf("   ");
        }

        // Print edges and hexagons
        for (int j = 0; j < cols; j++) {
            printf("| %d |", hexagons[i][j].value);
            if (j < cols - 1) {
                printf("\\ ");
            }
        }
        printf("\n");

        // Print leading spaces for offset
        for (int k = 0; k < i; k++) {
            printf("   ");
        }

        // Print vertices and edges
        for (int j = 0; j < cols; j++) {
            printf(" \\ / ");
            if (j < cols - 1) {
                printf("--");
            }
        }
        printf("\n");
    }
}
