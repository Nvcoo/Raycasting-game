/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** ammo_text
*/

#include "utils.h"
#include "struct.h"

void ammo_text(assets_t *assets)
{
    assets->ammo_font = sfFont_createFromFile("assets/font.ttf");
    if (!assets->ammo_font)
        return;
    assets->ammo_text = sfText_create();
    sfText_setFont(assets->ammo_text, assets->ammo_font);
    sfText_setString(assets->ammo_text, "AMMO: ∞");
    sfText_setCharacterSize(assets->ammo_text, 40);
    sfText_setFillColor(assets->ammo_text, sfWhite);
    sfText_setPosition(assets->ammo_text, (sfVector2f){10, 10});
}
