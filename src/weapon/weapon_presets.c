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
    gun->gun.g_frame_count = 4;
    gun->gun.g_columns = 2;
    gun->gun.g_width = 237;
    gun->gun.g_height = 155;
    gun->gun.g_current_frame = 0;
    gun->gun.g_frame_duration = 0.04f;
    gun->gun.g_time_since = 0.0f;
}
