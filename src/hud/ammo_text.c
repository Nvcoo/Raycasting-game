/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** ammo_text
*/

#include "utils.h"
#include "struct.h"

void init_ammo_text(assets_t *assets)
{
    char ammo_str[10];

    assets->gun.ammo_font = sfFont_createFromFile("assets/font.ttf");
    if (!assets->gun.ammo_font)
        return;
    assets->gun.ammo_text = sfText_create();
    sfText_setFont(assets->gun.ammo_text, assets->gun.ammo_font);
    assets->gun.ammo_count = 120;
    sprintf(ammo_str, "AMMO: %d", assets->gun.ammo_count);
    sfText_setString(assets->gun.ammo_text, ammo_str);
    sfText_setFillColor(assets->gun.ammo_text, sfWhite);
    sfText_setPosition(assets->gun.ammo_text, (sfVector2f){10, 0});
}

void ammo_text(assets_t *assets, sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    int base_width = 800;
    int scale = window_size.x / base_width;
    int size = 40 * scale;

    sfText_setCharacterSize(assets->gun.ammo_text, size);
    sfRenderWindow_drawText(window, assets->gun.ammo_text, NULL);
}
