/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** floor_and_ceiling
*/

#include "utils.h"

void draw_floor_and_ceiling(sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    int height = window_size.y;
    int horizon = height / 2;
    float range = height / 1.2f;

    draw_ceiling(window, horizon, range);
    draw_floor(window, horizon, range);
}
