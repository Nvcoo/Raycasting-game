/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** render_wall_column
*/

#include "utils.h"

void render_wall_column(sfRenderWindow *window, int column,
    float wall_height, sfColor color)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    float top = (window_size.y / 2.0) - (wall_height / 2);
    float bottom = top + wall_height;
    float shaders = fmin(1.0f, wall_height / 500.0f);
    sfRectangleShape *wall = sfRectangleShape_create();

    if (top < 0)
        top = 0;
    if (bottom > window_size.y)
        bottom = window_size.y;
    sfRectangleShape_setPosition(wall, (sfVector2f){column, top});
    sfRectangleShape_setSize(wall, (sfVector2f){1, bottom - top});
    color.r *= shaders;
    color.g *= shaders;
    color.b *= shaders;
    sfRectangleShape_setFillColor(wall, color);
    sfRenderWindow_drawRectangleShape(window, wall, NULL);
    sfRectangleShape_destroy(wall);
}
