/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** vertical_ray
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

void available_vertical_path(VerticalData_t *data, int *depth)
{
    def_ray(&data->ray_x, &data->ray_y, &data->x_offset, &data->y_offset);
    (*depth)++;
}

float handle_vertical_ray(Player_t player, float ray_angle)
{
    int move_x;
    int move_y;
    int depth = 0;
    float dist = INFINITY;
    VerticalData_t data;

    init_vertical_ray(player, ray_angle, &data);
    if (ray_angle == 0 || (ray_angle <= PI && ray_angle >= PI))
        ray_equivalence(&data.ray_x, &data.ray_y, &depth, &player);
    while (depth < 8) {
        ray_progress(&move_x, &move_y, &data.ray_x, &data.ray_y);
        if (move_x >= 0 && move_x < MAP_WIDTH && move_y >= 0 &&
            move_y < MAP_HEIGHT && map[move_y][move_x] == 1) {
            dist = hypotf(data.ray_x - player.x, data.ray_y - player.y);
            break;
        } else
            available_vertical_path(&data, &depth);
    }
    return dist;
}
