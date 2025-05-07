/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** move_forwards
*/

#include "utils.h"
#include "struct.h"

void forwards(float x_update, float y_update, Player_t *player, float step)
{
    if (sfKeyboard_isKeyPressed(sfKeyW)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            step *= 1.7;
        x_update = player->x + cos(player->angle) * step;
        y_update = player->y + sin(player->angle) * step;
        if (!is_wall(x_update, player->y))
            player->x = x_update;
        if (!is_wall(player->x, y_update))
            player->y = y_update;
    }
}
