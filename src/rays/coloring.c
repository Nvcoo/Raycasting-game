/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** coloring
*/

#include "utils.h"

void coloring(ray_t ray, sfColor *color)
{
    if (ray.vertical_wall)
        *color = sfColor_fromRGB(52, 68, 84);
    else
        *color = sfColor_fromRGB(102, 118, 134);
}
