/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** rotate_player
*/

#include "utils.h"
#include "struct.h"

void rotation(Player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        player->angle -= 0.017;
    if (sfKeyboard_isKeyPressed(sfKeyE))
        player->angle += 0.017;
}
