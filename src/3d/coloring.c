/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** coloring
*/

#include "utils.h"

void ceiling_coloring(sfColor *color, float shade)
{
        *color = sfColor_fromRGB(195, 230, 255);
        color->r *= shade;
        color->g *= shade;
        color->b *= shade;
}

void floor_coloring(sfColor *color, float shade)
{
    *color = sfColor_fromRGB(155, 165, 180);
    color->r *= shade;
    color->g *= shade;
    color->b *= shade;
}
