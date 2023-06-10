// A header for map
#pragma once

// Macro for the size of the map
#define MAP_WIDTH 25
#define MAP_HEIGHT 27
// Macro for the number of areas
#define AREA_NUM 19

// Libraries
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// enum for the items in the map
typedef
enum
{
    nothing = 0,
    Hills,
    Forest,
    Mountains,
    Fields,
    Pastures,
    Desert,
    Harbor_Any,
    Harbor_Brick,
    Harbor_Lumber,
    Harbor_Ore,
    Harbor_Grain,
    Harbor_Wool,
    Road,
    Village,
    City
}
MAP_ITEM;

// structure for coordinates
typedef
struct
{
    int x;
    int y;
}
COORDINATES;

// Function to fill the area into the map
void fill_area_of_the_map(MAP_ITEM area, int x, int y);

// Function to initialize the map
void init_map();

// Print the map for debugging
// macro
#define print_map { \
    extern MAP_ITEM** map; \
    for (int i = 0; i < MAP_HEIGHT; i++) \
    { \
        for (int j = 0; j < MAP_WIDTH; j++) \
            printf("%d ", map[j][i]); \
        printf("\n"); \
    } \
}
