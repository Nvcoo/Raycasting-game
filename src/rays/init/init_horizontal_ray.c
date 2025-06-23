/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_horizontal_ray
*/

#include "utils.h"
#include "struct.h"

void init_horizontal_ray(Player_t player, float ray_angle,
    HorizontalData_t *ray_data)
{
    float aTan = -1 / tanf(ray_angle);

    if (ray_angle > M_PI) {
        ray_data->ray_y = (((int)player.y >> 6) << 6) - 0.0001;
        ray_data->ray_x = (player.y - ray_data->ray_y) * aTan + player.x;
        ray_data->y_offset = -TILE_SIZE;
        ray_data->x_offset = -ray_data->y_offset * aTan;
    } else if (ray_angle < M_PI) {
        ray_data->ray_y = (((int)player.y >> 6) << 6) + TILE_SIZE;
        ray_data->ray_x = (player.y - ray_data->ray_y) * aTan + player.x;
        x_offset_progress(&ray_data->x_offset, &ray_data->y_offset, &aTan);
    }
}
