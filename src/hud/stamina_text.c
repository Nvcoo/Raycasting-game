/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** stamina_text
*/

#include "utils.h"
#include "struct.h"

void init_stamina_text(assets_t *assets)
{
    assets->hud.stamina_font = sfFont_createFromFile("assets/font.ttf");
    if (!assets->hud.stamina_font)
        return;
    assets->hud.stamina_text = sfText_create();
    sfText_setFont(assets->hud.stamina_text, assets->hud.stamina_font);
    sfText_setString(assets->hud.stamina_text, "STAMINA: 100%");
    sfText_setFillColor(assets->hud.stamina_text, sfWhite);
}

void stamina_text(assets_t *assets, sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    int base_width = 800;
    int scale = window_size.x / base_width;
    int size = 40 * scale;
    int text_width = 0;
    int x_offset = 0;
    int y_offset = window_size.y - size - 35;

    sfText_setCharacterSize(assets->hud.stamina_text, size);
    text_width = sfText_getGlobalBounds(assets->hud.stamina_text).width;
    x_offset = window_size.x - text_width - 120;
    sfText_setPosition(assets->hud.stamina_text,
        (sfVector2f){x_offset, y_offset});
    sfRenderWindow_drawText(window, assets->hud.stamina_text, NULL);
}
