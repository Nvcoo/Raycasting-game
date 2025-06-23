/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** weapon
*/

#include "utils.h"
#include "struct.h"

void update_gun(sfRenderWindow *window, assets_t *gun, sfClock *clock)
{
    float elapsed = sfTime_asSeconds(sfClock_restart(clock));
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f next_pos;
    float offset;

    toggle_condition(gun, &elapsed);
    gun->gun.g_origin.x = window_size.x - gun->gun.g_width - 1550;
    gun->gun.g_origin.y = window_size.y - gun->gun.g_height - 140;
    gun->gun.g_wobble_pos += elapsed * 8.0f;
    if (gun->gun.g_wobble_pos >= 2 * M_PI)
        gun->gun.g_wobble_pos -= 2 * M_PI;
    offset = sinf(gun->gun.g_wobble_pos) * gun->gun.g_movement;
    next_pos = gun->gun.g_origin;
    next_pos.y += offset;
    sfSprite_setPosition(gun->gun.g_sprite, next_pos);
}
