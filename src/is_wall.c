/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** is_wall
*/

#include "utils.h"

int is_wall(int x, int y)
{
    int x_coor = x / TILE_SIZE;
    int y_coor = y / TILE_SIZE;

    if (x_coor < MAP_WIDTH && y_coor < MAP_HEIGHT
        && x_coor >= 0 && y_coor >= 0) {
        if (map[y_coor][x_coor] == 1)
            return 1;
        else
            return 0;
    }
    return 0;
}
