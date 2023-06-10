// implementation of player.h
#include "player.h"

int compare_coordinates(COORDINATES a, COORDINATES b) {
    return a.x == b.x && a.y == b.y;
}

void add_road(PLAYER *player, COORDINATES start, COORDINATES end) {
    // search the roads to check if the road can be connected
    // if not, add the road to the first
    int added = 0;
    for (PLAYER_ROAD *road = player->roads; road != NULL; road = road->next) {
        if (compare_coordinates(road->start, start) && compare_coordinates(road->end, end)) {
    }
}