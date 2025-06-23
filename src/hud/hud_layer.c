/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** hud_layer
*/

#include "utils.h"
#include "struct.h"

void init_bottom_layer(assets_t *assets)
{
    assets->hud.bottom_texture =
        sfTexture_createFromFile("assets/bottom_hud.png", NULL);
    if (!assets->hud.bottom_texture)
        return;
    assets->hud.bottom_sprite = sfSprite_create();
    sfSprite_setTexture(assets->hud.bottom_sprite,
        assets->hud.bottom_texture, sfTrue);
}

void update_bottom_layer(assets_t *assets, sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    int width = window_size.x / 2;
    int height = window_size.y / 4;
    sfVector2f scale = {
        (float)width / sfTexture_getSize(assets->hud.bottom_texture).x,
        (float)height / sfTexture_getSize(assets->hud.bottom_texture).y};

    sfSprite_setScale(assets->hud.bottom_sprite, scale);
    sfSprite_setPosition(assets->hud.bottom_sprite,
        (sfVector2f){((float)window_size.x / 2),
            (float)(window_size.y - height)});
    sfRenderWindow_drawSprite(window, assets->hud.bottom_sprite, NULL);
}

void destroy_bottom_hud(assets_t *assets)
{
    sfSprite_destroy(assets->hud.bottom_sprite);
    sfTexture_destroy(assets->hud.bottom_texture);
}
