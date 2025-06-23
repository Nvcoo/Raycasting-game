/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** buttons_scale
*/

#include "utils.h"
#include "struct.h"

scale_t calculate_scales(assets_t *assets, sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2u bg_size = sfTexture_getSize(assets->menu.menu_bg_texture);
    float buttons_scale = (float)window_size.x / 800;
    scale_t scales = {
        .scale = {(float)window_size.x / bg_size.x,
            (float)window_size.y / bg_size.y},
        .scaling = {buttons_scale * 0.5f, buttons_scale * 0.5f}
    };

    return scales;
}
