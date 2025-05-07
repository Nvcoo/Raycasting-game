/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw_player
*/

#include "utils.h"

void draw_player(sfRenderWindow *window, Player_t *player)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfRectangleShape *square = sfRectangleShape_create();
    sfTexture *player_texture = sfTexture_createFromFile("assets/player.png",
        NULL);
    sfVector2f offset = {
        ((float)window_size.x / 2) - (MAP_WIDTH * TILE_SIZE) / 2.0f,
        ((float)window_size.y / 2) - (MAP_HEIGHT * TILE_SIZE) / 2.0f
    };
    sfVector2f position = {
        player->x + offset.x - 25,
        player->y + offset.y - 25
    };

    sfRectangleShape_setSize(square, (sfVector2f){50, 50});
    sfRectangleShape_setPosition(square, position);
    sfRectangleShape_setTexture(square, player_texture, sfTrue);
    sfRenderWindow_drawRectangleShape(window, square, NULL);
    sfRectangleShape_destroy(square);
    sfTexture_destroy(player_texture);
}
