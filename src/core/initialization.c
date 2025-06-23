/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** initialization
*/

#include "utils.h"
#include "struct.h"

void init_game(Player_t *player, assets_t *assets, sfRenderWindow *window)
{
    init_player(player);
    init_gun(window, assets);
    init_torch(window, assets);
    init_crosshair(window, assets);
    init_ammo_text(assets);
    init_health_text(assets);
    init_stamina_text(assets);
    init_bottom_layer(assets);
}
