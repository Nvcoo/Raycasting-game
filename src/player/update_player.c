/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** update_player
*/

#include "struct.h"
#include "utils.h"

void update_player(Player_t *player)
{
    float step = 0.8f;
    float x_update;
    float y_update;

    if (player->show_map)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            step *= 1.5;
        x_update = player->x - cos(player->angle) * step;
        y_update = player->y - sin(player->angle) * step;
        if (!is_wall(x_update, player->y))
            player->x = x_update;
        if (!is_wall(player->x, y_update))
            player->y = y_update;
    }
    forwards(x_update, y_update, player, step);
    left_right(x_update, y_update, player, step);
    rotation(player);
}
