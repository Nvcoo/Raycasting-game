/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_menu
*/

#include "utils.h"
#include "struct.h"

void set_buttons(sfSprite **sprite, sfTexture **texture, const char *file)
{
    *sprite = sfSprite_create();
    *texture = sfTexture_createFromFile(file, NULL);
    sfSprite_setTexture(*sprite, *texture, sfTrue);
}

void init_buttons(assets_t *assets)
{
    set_buttons(&assets->menu.up_sprite, &assets->menu.up_texture,
        "assets/up.png");
    set_buttons(&assets->menu.down_sprite, &assets->menu.down_texture,
        "assets/down.png");
    set_buttons(&assets->menu.audio_sprite, &assets->menu.audio_texture,
        "assets/music.png");
    set_buttons(&assets->menu.menu_bg_sprite, &assets->menu.menu_bg_texture,
        "assets/bg.png");
    set_buttons(&assets->menu.start_bg_sprite, &assets->menu.start_bg_texture,
        "assets/quit.png");
    set_buttons(&assets->menu.leave_bg_sprite, &assets->menu.leave_bg_texture,
        "assets/start.png");
    set_buttons(&assets->menu.res_sprite, &assets->menu.res_texture,
        "assets/max.png");
    set_buttons(&assets->menu.help_sprite, &assets->menu.help_texture,
        "assets/help.png");
    set_buttons(&assets->menu.key_sprite, &assets->menu.key_texture,
        "assets/key.png");
}

void init_menu(assets_t *assets)
{
    assets->menu.show_help = false;
    init_buttons(assets);
    assets->is_fullscreen = false;
}
