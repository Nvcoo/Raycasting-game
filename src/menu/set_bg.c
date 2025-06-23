/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** set_menu
*/

#include "utils.h"
#include "struct.h"

void set_bg(assets_t *assets, sfVector2f scale, sfRenderWindow *window)
{
    sfSprite_setScale(assets->menu.menu_bg_sprite, scale);
    sfSprite_setPosition(assets->menu.menu_bg_sprite, (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(window, assets->menu.menu_bg_sprite, NULL);
}
