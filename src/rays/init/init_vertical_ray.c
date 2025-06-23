/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_vertical_ray
*/

#include "utils.h"
#include "struct.h"

void init_vertical_ray(Player_t player, float ray_angle,
    VerticalData_t *ray_data)
{
    float nTan = -tanf(ray_angle);

    if (ray_angle > M_PI_2) {
        ray_data->ray_x = (((int)player.x >> 6) << 6) - 0.0001;
        ray_data->ray_y = (player.x - ray_data->ray_x) * nTan + player.y;
        ray_data->x_offset = -TILE_SIZE;
        ray_data->y_offset = -ray_data->x_offset * nTan;
    }
    if (ray_angle < M_PI_2 || ray_angle > 3 * M_PI_2) {
        ray_data->ray_x = (((int)player.x >> 6) << 6) + TILE_SIZE;
        ray_data->ray_y = (player.x - ray_data->ray_x) * nTan + player.y;
        y_offset_progress(&ray_data->x_offset, &ray_data->y_offset, &nTan);
    }
}
