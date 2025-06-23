/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** health_text
*/

#include "utils.h"
#include "struct.h"

void init_health_text(assets_t *assets)
{
    assets->hud.health_font = sfFont_createFromFile("assets/font.ttf");
    if (!assets->hud.health_font)
        return;
    assets->hud.health_text = sfText_create();
    sfText_setFont(assets->hud.health_text, assets->hud.health_font);
    sfText_setString(assets->hud.health_text, "HEALTH: 100%");
    sfText_setFillColor(assets->hud.health_text, sfWhite);
}

void health_text(assets_t *assets, sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    int base_width = 800;
    int scale = window_size.x / base_width;
    int size = 40 * scale;
    int text_width = 0;
    int offset = 0;

    sfText_setCharacterSize(assets->hud.health_text, size);
    text_width = sfText_getGlobalBounds(assets->hud.health_text).width;
    offset = window_size.x - text_width - 10;
    sfText_setPosition(assets->hud.health_text, (sfVector2f){offset, 0});
    sfRenderWindow_drawText(window, assets->hud.health_text, NULL);
}
