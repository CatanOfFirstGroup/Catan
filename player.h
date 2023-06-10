// a header for player structure and functions
#pragma once

#include "map.h"

// disable auto alignment of struct
#pragma pack(1)

// struct for nodes player own
typedef
struct
{
    COORDINATES node;
    void *next;
}
PLAYER_NODE;

// struct for roads player own
typedef
struct
{
    COORDINATES start;
    COORDINATES end;
    void *next;
}
PLAYER_ROAD;

typedef
struct
{
    char *name;
    PLAYER_NODE *nodes;
    PLAYER_ROAD *roads;
    int brick;
    int lumber;
    int ore;
    int grain;
    int wool;
    int length_of_road;
    int score;
}
PLAYER;

// add a road into player
void add_road(PLAYER *player, COORDINATES start, COORDINATES end);

// count the length of the road
int count_length_of_road(PLAYER *player);