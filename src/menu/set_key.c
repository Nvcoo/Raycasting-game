/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** set_sec_buttons
*/

#include "utils.h"
#include "struct.h"

void set_key(assets_t *assets, sfVector2f buttons_scaling,
    float key_x, float key_y)
{
    sfSprite_setScale(assets->menu.key_sprite, buttons_scaling);
    sfSprite_setPosition(assets->menu.key_sprite, (sfVector2f){key_x, key_y});
}
