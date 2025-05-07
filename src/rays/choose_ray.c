/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** choose_ray
*/

#include "utils.h"
#include "struct.h"

void choose_ray(float horizontal_dist, float vertical_dist, ray_t *result)
{
    if (horizontal_dist < vertical_dist) {
        result->distance = horizontal_dist;
        result->vertical_wall = sfFalse;
    } else {
        result->distance = vertical_dist;
        result->vertical_wall = sfTrue;
    }
}
