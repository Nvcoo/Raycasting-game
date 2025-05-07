/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** cast_all_rays
*/

#include "struct.h"
#include "utils.h"

void cast_all_rays(sfRenderWindow *window, Player_t *player)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    int width = window_size.x;
    int height = window_size.y;
    float ray_angle = 0;
    float fish_eye = 0;
    float wall_height = 0;
    ray_t ray;
    sfColor color;

    if (wall_height == 1)
        printf("How does that even happen\n");
    for (int i = 0; i < width; i++) {
        ray_angle = player->angle - (FOV / 2.0f) + (i * (FOV / width));
        ray = cast_single_ray(*player, ray_angle, window);
        fish_eye = ray.distance * cosf(ray_angle - player->angle) * 1;
        wall_height = (TILE_SIZE / fish_eye) * ((float)height / 2);
        wall_height *= 1.1;
        coloring(ray, &color);
        render_wall_column(window, i, wall_height, color);
    }
}
