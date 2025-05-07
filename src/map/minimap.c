/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** minimap
*/

#include "utils.h"

void draw_minimap(sfRenderWindow *window, Player_t *player)
{
    draw_map(window);
    draw_player(window, player);
}
