/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** ray_utilities
*/

#include "utils.h"
#include "struct.h"

void ray_equivalence(float *ray_x, float *ray_y, int *depth,
    Player_t *player)
{
    *ray_x = player->x;
    *ray_y = player->y;
    *depth = 8;
}

void ray_progress(int *move_x, int *move_y, float *ray_x, float *ray_y)
{
    *move_x = (int)(*ray_x) / TILE_SIZE;
    *move_y = (int)(*ray_y) / TILE_SIZE;
}

void def_ray(float *ray_x, float *ray_y, float *x_offset,
    float *y_offset)
{
    *ray_x = *ray_x + *x_offset;
    *ray_y = *ray_y + *y_offset;
}

void x_offset_progress(float *x_offset, float *y_offset, float *aTan)
{
    *y_offset = TILE_SIZE;
    *x_offset = - *y_offset * *aTan;
}

void y_offset_progress(float *x_offset, float *y_offset, float *nTan)
{
    *x_offset = TILE_SIZE;
    *y_offset = - *x_offset * *nTan;
}
