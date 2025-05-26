/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw_tiles
*/

#include "utils.h"

void draw_tiles(int height, int width, sfRectangleShape *tile)
{
    if (map[height][width] == 1)
        sfRectangleShape_setFillColor(tile, sfColor_fromRGB(60, 100, 140));
    if (map[height][width] == 0)
        sfRectangleShape_setFillColor(tile, sfColor_fromRGB(155, 165, 180));
}
