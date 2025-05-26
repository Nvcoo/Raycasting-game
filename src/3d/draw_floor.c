/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw_floor
*/

#include "utils.h"

void row_init(sfRectangleShape *row, int *width, int y, sfColor *color)
{
    sfRectangleShape_setSize(row, (sfVector2f){*width, 1});
    sfRectangleShape_setPosition(row, (sfVector2f){0, y});
    sfRectangleShape_setFillColor(row, *color);
}

void floor_coloring(sfColor *color, float shade)
{
    *color = sfColor_fromRGB(155, 165, 180);
    color->r *= shade;
    color->g *= shade;
    color->b *= shade;
}

void draw_floor(sfRenderWindow *window, const int horizon, const float range)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    int width = window_size.x;
    int height = window_size.y;
    float depth = 0.0;
    sfRectangleShape *row = sfRectangleShape_create();
    float shade = 0.0;
    sfColor color;
    float distance;

    if (!row)
        return;
    for (int y = horizon; y < height; y++) {
        distance = y - horizon;
        depth = distance / range;
        shade = powf(depth, 2.0f);
        floor_coloring(&color, shade);
        row_init(row, &width, y, &color);
        sfRenderWindow_drawRectangleShape(window, row, NULL);
    }
    sfRectangleShape_destroy(row);
}
