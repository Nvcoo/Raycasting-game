/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** buttons_pos
*/

#include "utils.h"
#include "struct.h"

void set_main_pos(menu_pos_t *pos, sfVector2u win_size, scale_t scale,
    texture_size_t tex)
{
    pos->start_x = (win_size.x - (tex.start_size.x * scale.scaling.x)) / 2;
    pos->start_y = (win_size.y * 0.75) -
        (tex.start_size.y * scale.scaling.y) / 2;
    pos->quit_x = (win_size.x - (tex.leave_size.x * scale.scaling.x)) / 2;
    pos->quit_y = (win_size.y * 0.25) - (tex.leave_size.y * scale.scaling.y)
        / 2;
}

menu_pos_t button_pos(sfVector2u win_size, scale_t scale, texture_size_t tex)
{
    menu_pos_t pos;

    set_main_pos(&pos, win_size, scale, tex);
    pos.up_x = win_size.x * 0.05;
    pos.up_y = win_size.y * 0.25 - (tex.up_size.y * scale.scaling.y) / 2;
    pos.down_x = win_size.x * 0.05;
    pos.down_y = win_size.y * 0.75 - (tex.down_size.y * scale.scaling.y) / 2;
    pos.audio_x = win_size.x * 0.05;
    pos.audio_y = win_size.y * 0.5 - (tex.audio_size.y * scale.scaling.y) / 2;
    pos.help_x = win_size.x * 0.44;
    pos.help_y = win_size.y * 0.5 - (tex.audio_size.y * scale.scaling.y) / 2;
    pos.res_x = win_size.x * 0.75;
    pos.res_y = win_size.y * 0.5 - (tex.res_size.y * scale.scaling.y) / 2;
    pos.key_x = win_size.x * 0.15;
    pos.key_y = win_size.y *0.75 - (tex.key_size.y * scale.scaling.y) / 2;
    return pos;
}

menu_pos_t calculate_pos(assets_t *assets, sfRenderWindow *window,
    scale_t scale)
{
    sfVector2u win_size = sfRenderWindow_getSize(window);
    texture_size_t tex = {
        .start_size = sfTexture_getSize(assets->menu.start_bg_texture),
        .leave_size = sfTexture_getSize(assets->menu.leave_bg_texture),
        .up_size = sfTexture_getSize(assets->menu.up_texture),
        .down_size = sfTexture_getSize(assets->menu.down_texture),
        .audio_size = sfTexture_getSize(assets->menu.audio_texture),
        .help_size = sfTexture_getSize(assets->menu.help_texture),
        .res_size = sfTexture_getSize(assets->menu.res_texture),
        .key_size = sfTexture_getSize(assets->menu.key_texture)
    };

    return button_pos(win_size, scale, tex);
}
