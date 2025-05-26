/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw_player
*/

#include "utils.h"

void set_player(sfRectangleShape *square, float scaled_tile,
    sfVector2f position, sfTexture *texture)
{
    sfRectangleShape_setSize(square, (sfVector2f){scaled_tile * 1.2,
        scaled_tile * 1.2});
    sfRectangleShape_setPosition(square, position);
    sfRectangleShape_setTexture(square, texture, sfTrue);
}

void draw_player(sfRenderWindow *window, Player_t *player)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfRectangleShape *square = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile("assets/player.png", NULL);
    float map_ratio = 0.8f;
    float scaled_width = (window_size.x * map_ratio) / MAP_WIDTH;
    float scaled_height = (window_size.y * map_ratio) / MAP_HEIGHT;
    float scaled_tile = fminf(scaled_width, scaled_height);
    sfVector2f offset = {
        (window_size.x - (MAP_WIDTH * scaled_tile)) / 2.0f,
        (window_size.y - (MAP_HEIGHT * scaled_tile)) / 2.0f
    };
    sfVector2f position = {
        player->x * scaled_tile / TILE_SIZE + offset.x - scaled_tile / 2.0f,
        player->y * scaled_tile / TILE_SIZE + offset.y - scaled_tile / 2.0f
    };

    set_player(square, scaled_tile, position, texture);
    sfRenderWindow_drawRectangleShape(window, square, NULL);
    sfRectangleShape_destroy(square);
    sfTexture_destroy(texture);
}
