/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** horizontal_ray
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

void available_horizontal_path(HorizontalData_t *data, int *depth)
{
    def_ray(&data->ray_x, &data->ray_y, &data->x_offset, &data->y_offset);
    (*depth)++;
}

float handle_horizontal_ray(Player_t player, float ray_angle)
{
    int move_x;
    int move_y;
    int depth = 0;
    float dist = INFINITY;
    HorizontalData_t data;

    init_horizontal_ray(player, ray_angle, &data);
    if (ray_angle == 0 || (ray_angle <= PI && ray_angle >= PI))
        ray_equivalence(&data.ray_x, &data.ray_y, &depth, &player);
    while (depth < 8) {
        ray_progress(&move_x, &move_y, &data.ray_x, &data.ray_y);
        if (move_x >= 0 && move_x < MAP_WIDTH && move_y >= 0 &&
            move_y < MAP_HEIGHT && map[move_y][move_x] == 1) {
            dist = hypotf(data.ray_x - player.x, data.ray_y - player.y);
            break;
        } else
            available_horizontal_path(&data, &depth);
    }
    return dist;
}
