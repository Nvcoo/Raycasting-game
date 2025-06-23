/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** destroy_gun
*/

#include "utils.h"
#include "struct.h"

void destroy_gun(assets_t *gun)
{
    if (gun->gun.g_sprite)
        sfSprite_destroy(gun->gun.g_sprite);
    if (gun->gun.g_texture)
        sfTexture_destroy(gun->gun.g_texture);
}
