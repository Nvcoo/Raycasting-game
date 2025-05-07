/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** cast_single_ray
*/

#include "struct.h"
#include "utils.h"

ray_t cast_single_ray(Player_t player, float ray_angle, sfRenderWindow *win)
{
    float vertical_dist = INFINITY;
    float horizontal_dist = INFINITY;
    ray_t result;

    (void)win;
    ray_angle = normalize_angle(ray_angle);
    horizontal_dist = handle_horizontal_ray(player, ray_angle);
    vertical_dist = handle_vertical_ray(player, ray_angle);
    choose_ray(horizontal_dist, vertical_dist, &result);
    return result;
}
