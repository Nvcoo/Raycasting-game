/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** gun_math
*/

#include "utils.h"
#include "struct.h"

void g_animation_math(assets_t *gun, int *column, int *row)
{
    gun->gun.g_current_frame = (gun->gun.g_current_frame + 1)
        % gun->gun.g_frame_count;
    *column = gun->gun.g_current_frame % gun->gun.g_columns;
    *row = gun->gun.g_current_frame / gun->gun.g_columns;
    gun->gun.g_frame_rect.left = *column * gun->gun.g_width;
    gun->gun.g_frame_rect.top = *row * gun->gun.g_height;
    sfSprite_setTextureRect(gun->gun.g_sprite, gun->gun.g_frame_rect);
    gun->gun.g_time_since = 0.0f;
}
