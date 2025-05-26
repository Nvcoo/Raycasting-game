/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** map_layer
*/

#include "utils.h"

void minimap_layer(sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfRectangleShape *layer = sfRectangleShape_create();
    sfTexture *layer_texture = sfTexture_createFromFile("assets/map_layer.png",
        NULL);
    float map_ratio = 0.85f;
    float scaled_width = (window_size.x * map_ratio) / MAP_WIDTH;
    float scaled_height = (window_size.y * map_ratio) / MAP_HEIGHT;
    float scaled_tile = fminf(scaled_width, scaled_height);
    sfVector2f offset = {
        (window_size.x - (MAP_WIDTH * scaled_tile)) / 2.0f,
        (window_size.y - (MAP_HEIGHT * scaled_tile)) / 2.0f
    };

    sfRectangleShape_setSize(layer, (sfVector2f){MAP_WIDTH * scaled_tile,
        MAP_HEIGHT * scaled_tile});
    sfRectangleShape_setTexture(layer, layer_texture, sfTrue);
    sfRectangleShape_setPosition(layer, offset);
    sfRenderWindow_drawRectangleShape(window, layer, NULL);
    sfRectangleShape_destroy(layer);
}
