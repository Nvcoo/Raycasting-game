/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** toggle
*/

#include "utils.h"
#include "struct.h"

void toggle_condition(assets_t *gun, float *elapsed)
{
    int column;
    int row;
    char ammo_str[10];

    if (gun->gun.firing && gun->gun.ammo_count > 0) {
        gun->gun.ammo_count--;
        gun->gun.g_time_since += *elapsed;
        sprintf(ammo_str, "AMMO: %d", gun->gun.ammo_count);
        sfText_setString(gun->gun.ammo_text, ammo_str);
        if (sfSound_getStatus(gun->gun.sound) != sfPlaying)
            sfSound_play(gun->gun.sound);
        if (gun->gun.g_time_since >= gun->gun.g_frame_duration)
            g_animation_math(gun, &column, &row);
    } else {
        if (sfSound_getStatus(gun->gun.sound) == sfPlaying)
            sfSound_stop(gun->gun.sound);
        gun->gun.g_frame_rect.left = 0;
        gun->gun.g_frame_rect.top = 0;
        sfSprite_setTextureRect(gun->gun.g_sprite, gun->gun.g_frame_rect);
    }
}
