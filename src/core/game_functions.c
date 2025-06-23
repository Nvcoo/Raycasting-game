/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** game_functions
*/

#include "utils.h"
#include "struct.h"

void game_functions(Player_t *player, sfRenderWindow *window, assets_t *assets)
{
    update_player(player);
    mouse_rotation(window, player);
    sfRenderWindow_clear(window, sfBlack);
    draw_floor_and_ceiling(window);
    cast_all_rays(window, player);
    sfRenderWindow_drawSprite(window, assets->torch.t_sprite, NULL);
    sfRenderWindow_drawSprite(window, assets->gun.g_sprite, NULL);
    ammo_text(assets, window);
    health_text(assets, window);
    update_bottom_layer(assets, window);
    stamina_text(assets, window);
    relative_pause(player, window);
    if (!player->show_map)
        draw_crosshair(window, assets);
    sfRenderWindow_display(window);
}
