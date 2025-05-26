/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw_ceiling
*/

#include "utils.h"

void ceiling_coloring(sfColor *color, float shade)
{
        *color = sfColor_fromRGB(195, 230, 255);
        color->r *= shade;
        color->g *= shade;
        color->b *= shade;
}

void draw_ceiling(sfRenderWindow* window, const int horizon, const float range)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    int width = window_size.x;
    float depth = 0.0;
    float shade = 0.0;
    sfColor color;
    sfRectangleShape *row = sfRectangleShape_create();
    float distance;

    for (int y = 0; y < horizon; y++) {
        distance = horizon - y;
        depth = distance / range;
        shade = powf(depth, 2.0f);
        ceiling_coloring(&color, shade);
        sfRectangleShape_setSize(row, (sfVector2f){width, 1});
        sfRectangleShape_setPosition(row, (sfVector2f){0, y});
        sfRectangleShape_setFillColor(row, color);
        sfRenderWindow_drawRectangleShape(window, row, NULL);
    }
    sfRectangleShape_destroy(row);
}
