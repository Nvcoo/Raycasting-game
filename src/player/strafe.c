/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** strafe
*/

#include "utils.h"
#include "struct.h"

void left_right(float x_update, float y_update, Player_t *player, float step)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        x_update = player->x + cos(player->angle - M_PI_2) * step;
        y_update = player->y + sin(player->angle - M_PI_2) * step;
        if (!is_wall(x_update, player->y))
            player->x = x_update;
        if (!is_wall(player->x, y_update))
            player->y = y_update;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        x_update = player->x - cos(player->angle - M_PI_2) * step;
        y_update = player->y - sin(player->angle - M_PI_2) * step;
        if (!is_wall(x_update, player->y))
            player->x = x_update;
        if (!is_wall(player->x, y_update))
            player->y = y_update;
    }
}
