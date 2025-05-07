/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** normalize_ray
*/

#include "utils.h"

float normalize_angle(float ray_angle)
{
    float result;

    ray_angle = fmod(ray_angle, 2 * M_PI);
    if (ray_angle < 0)
        ray_angle = ray_angle + 2 * M_PI;
    if (ray_angle > 2 * M_PI)
        ray_angle = ray_angle - 2 * M_PI;
    result = ray_angle;
    return result;
}
