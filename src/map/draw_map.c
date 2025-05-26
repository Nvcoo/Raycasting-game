/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw_map
*/

#include "utils.h"
#include "struct.h"

void adjust_map(MapParameters_t *params)
{
    sfVector2f tile_pos;

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            tile_pos.x = x * params->scaled_tile + params->offset.x;
            tile_pos.y = y * params->scaled_tile + params->offset.y;
            sfRectangleShape_setPosition(params->tile, tile_pos);
            draw_tiles(y, x, params->tile);
            sfRenderWindow_drawRectangleShape(params->window, params->tile,
                NULL);
        }
    }
}

void draw_map(sfRenderWindow *window)
{
    MapParameters_t params;
    sfRectangleShape *tile = sfRectangleShape_create();
    sfVector2u window_size = sfRenderWindow_getSize(window);
    float map_ratio = 0.8f;
    float scaled_width = (window_size.x * map_ratio) / MAP_WIDTH;
    float scaled_height = (window_size.y * map_ratio) / MAP_HEIGHT;
    float scaled_tile = fminf(scaled_width, scaled_height);
    sfVector2f offset = {
        (window_size.x - (MAP_WIDTH * scaled_tile)) / 2.0f,
        (window_size.y - (MAP_HEIGHT * scaled_tile)) / 2.0f
    };

    sfRectangleShape_setSize(tile, (sfVector2f){scaled_tile, scaled_tile});
    params.window = window;
    params.tile = tile;
    params.offset = offset;
    params.scaled_tile = scaled_tile;
    adjust_map(&params);
    sfRectangleShape_destroy(tile);
}
