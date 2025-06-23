/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** handle_vertical_ray
*/

#include "utils.h"
#include "struct.h"

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
