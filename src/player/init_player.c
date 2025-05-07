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
    player->x = 4.0f * TILE_SIZE;
    player->y = 4.0f * TILE_SIZE;
    player->angle = 5.785f;
}
