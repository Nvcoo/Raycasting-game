/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw_map
*/

#include "utils.h"

void draw_map(sfRenderWindow *window)
{
    sfRectangleShape *tile = sfRectangleShape_create();
    sfVector2f tile_pos;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f offset = {
        ((float)window_size.x / 2) - (MAP_WIDTH * TILE_SIZE) / 2.0f,
        ((float)window_size.y / 2) - (MAP_HEIGHT * TILE_SIZE) / 2.0f
    };

    sfRectangleShape_setSize(tile, (sfVector2f){TILE_SIZE, TILE_SIZE});
    for (int height = 0; height < MAP_HEIGHT; height++) {
        for (int width = 0; width < MAP_WIDTH; width++) {
            tile_pos.x = width * TILE_SIZE + offset.x;
            tile_pos.y = height * TILE_SIZE + offset.y;
            sfRectangleShape_setPosition(tile, tile_pos);
            draw_tiles(height, width, tile);
            sfRenderWindow_drawRectangleShape(window, tile, NULL);
        }
    }
    sfRectangleShape_destroy(tile);
}
