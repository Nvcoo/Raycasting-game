/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** vertical_ray
*/

#include "utils.h"
#include "struct.h"

void available_vertical_path(VerticalData_t *data, int *depth)
{
    def_ray(&data->ray_x, &data->ray_y, &data->x_offset, &data->y_offset);
    (*depth)++;
}
