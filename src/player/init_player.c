/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_player
*/

#include "struct.h"
#include "utils.h"

void init_player(Player_t *player)
{
    player->show_map = false;
    player->x = 5.4f * TILE_SIZE;
    player->y = 5.4f * TILE_SIZE;
    player->angle = 6.15f;
}
