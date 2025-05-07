/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** floor_and_ceiling
*/

#include "struct.h"
#include "utils.h"

sfRectangleShape *sky(sfRenderWindow *window, sfTexture *sky_texture,
    Player_t *player)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2u texture_size = sfTexture_getSize(sky_texture);
    sfRectangleShape *ceiling = sfRectangleShape_create();
    float angle = fmodf(player->angle, 2 * M_PI);
    int x_offset;
    sfIntRect rectangle_texture;

    if (angle < 0)
        angle = angle + 2 * M_PI;
    x_offset = (int)((angle / (2 * M_PI)) * texture_size.x) % texture_size.x;
    rectangle_texture.left = x_offset / 1.2;
    rectangle_texture.top = 0;
    rectangle_texture.width = window_size.x / 4;
    rectangle_texture.height = window_size.y / 2;
    sfRectangleShape_setSize(ceiling,
        (sfVector2f){window_size.x * 1.1, (float)window_size.y / 2});
    sfRectangleShape_setPosition(ceiling, (sfVector2f){0, 0});
    sfRectangleShape_setTexture(ceiling, sky_texture, sfTrue);
    sfRectangleShape_setTextureRect(ceiling, rectangle_texture);
    return ceiling;
}

sfRectangleShape *grass(sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfRectangleShape *floor = sfRectangleShape_create();

    sfRectangleShape_setSize(floor,
        (sfVector2f){window_size.x, (float)window_size.y / 2});
    sfRectangleShape_setPosition(floor,
        (sfVector2f){0, (float)window_size.y / 2});
    sfRectangleShape_setFillColor(floor, sfColor_fromRGB(36, 112, 45));
    return floor;
}

void draw_floor_and_ceiling(sfRenderWindow *window,
    sfRectangleShape *ceiling, sfRectangleShape *floor)
{
    sfRenderWindow_drawRectangleShape(window, ceiling, NULL);
    sfRenderWindow_drawRectangleShape(window, floor, NULL);
}
