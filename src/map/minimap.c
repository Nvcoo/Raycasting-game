/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** minimap
*/

#include "utils.h"

void draw_minimap(sfRenderWindow *window, Player_t *player)
{
    minimap_layer(window);
    draw_map(window);
    draw_player(window, player);
}
