/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** weapon_presets
*/

#include "utils.h"
#include "struct.h"

void set_gun(assets_t *gun)
{
    gun->g_frame_count = 4;
    gun->g_columns = 2;
    gun->g_width = 237;
    gun->g_height = 155;
    gun->g_current_frame = 0;
    gun->g_frame_duration = 0.05f;
    gun->g_time_since = 0.0f;
}

void g_animation_math(assets_t *gun, int *column, int *row)
{
    gun->g_current_frame = (gun->g_current_frame + 1) % gun->g_frame_count;
    *column = gun->g_current_frame % gun->g_columns;
    *row = gun->g_current_frame / gun->g_columns;
    gun->g_frame_rect.left = *column * gun->g_width;
    gun->g_frame_rect.top = *row * gun->g_height;
    sfSprite_setTextureRect(gun->g_sprite, gun->g_frame_rect);
    gun->g_time_since = 0.0f;
}
