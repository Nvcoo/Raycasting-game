/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** set_volume_buttons
*/

#include "utils.h"

void set_up_buttons(sfSprite *sprite, sfVector2f scale, sfVector2f pos)
{
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
}
