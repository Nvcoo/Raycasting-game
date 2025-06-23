/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** adjust_map
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
