/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** destroy_assets
*/

#include "utils.h"
#include "struct.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>

void menu_destroy(assets_t *assets)
{
    sfSprite_destroy(assets->menu.start_bg_sprite);
    sfTexture_destroy(assets->menu.start_bg_texture);
    sfSprite_destroy(assets->menu.leave_bg_sprite);
    sfTexture_destroy(assets->menu.leave_bg_texture);
    sfSprite_destroy(assets->menu.up_sprite);
    sfTexture_destroy(assets->menu.up_texture);
    sfSprite_destroy(assets->menu.menu_bg_sprite);
    sfTexture_destroy(assets->menu.menu_bg_texture);
    sfSprite_destroy(assets->menu.down_sprite);
    sfTexture_destroy(assets->menu.down_texture);
    sfSprite_destroy(assets->menu.audio_sprite);
    sfTexture_destroy(assets->menu.audio_texture);
    sfTexture_destroy(assets->menu.help_texture);
    sfSprite_destroy(assets->menu.help_sprite);
    sfTexture_destroy(assets->menu.res_texture);
    sfSprite_destroy(assets->menu.res_sprite);
    sfTexture_destroy(assets->menu.key_texture);
    sfSprite_destroy(assets->menu.key_sprite);
}

void destroy_assets(assets_t *assets, sfClock *torch_clock, sfClock *gun_clock)
{
    destroy_torch(assets);
    destroy_gun(assets);
    sfClock_destroy(torch_clock);
    sfClock_destroy(gun_clock);
    sfSprite_destroy(assets->gun.cross_sprite);
    sfTexture_destroy(assets->gun.cross_texture);
    sfText_destroy(assets->gun.ammo_text);
    sfFont_destroy(assets->gun.ammo_font);
    sfText_destroy(assets->hud.health_text);
    sfFont_destroy(assets->hud.health_font);
    sfText_destroy(assets->hud.stamina_text);
    sfFont_destroy(assets->hud.stamina_font);
    sfSound_destroy(assets->gun.sound);
    destroy_bottom_hud(assets);
    menu_destroy(assets);
}
