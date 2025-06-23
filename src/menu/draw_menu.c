/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** menu
*/

#include "utils.h"
#include "struct.h"

void draw_keybinds(assets_t *assets, scale_t scale, sfRenderWindow *window,
    menu_pos_t pos)
{
    sfVector2f key_scale = {
        scale.scaling.x * 0.5,
        scale.scaling.y * 0.5
    };

    if (assets->menu.show_help) {
        set_key(assets, key_scale, pos.key_x, pos.key_y);
        sfRenderWindow_drawSprite(window, assets->menu.key_sprite, NULL);
    }
}

void draw_button(sfRenderWindow *window, sfSprite *sprite,
    sfVector2f scale, sfVector2f pos)
{
    set_up_buttons(sprite, scale, pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void draw_menu(assets_t *assets, sfRenderWindow *window)
{
    scale_t scale = calculate_scales(assets, window);
    menu_pos_t pos = calculate_pos(assets, window, scale);

    set_bg(assets, scale.scale, window);
    draw_button(window, assets->menu.start_bg_sprite,
        scale.scaling, (sfVector2f){pos.start_x, pos.start_y});
    draw_button(window, assets->menu.leave_bg_sprite,
        scale.scaling, (sfVector2f){pos.quit_x, pos.quit_y});
    draw_button(window, assets->menu.up_sprite,
        scale.scaling, (sfVector2f){pos.up_x, pos.up_y});
    draw_button(window, assets->menu.down_sprite,
        scale.scaling, (sfVector2f){pos.down_x, pos.down_y});
    draw_button(window, assets->menu.audio_sprite,
        scale.scaling, (sfVector2f){pos.audio_x, pos.audio_y});
    draw_button(window, assets->menu.help_sprite,
        scale.scaling, (sfVector2f){pos.help_x, pos.help_y});
    draw_button(window, assets->menu.res_sprite,
    scale.scaling, (sfVector2f){pos.res_x, pos.res_y});
    draw_keybinds(assets, scale, window, pos);
}
