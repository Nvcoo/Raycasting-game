/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** horizontal_ray
*/

#include "utils.h"
#include "struct.h"

void available_horizontal_path(HorizontalData_t *data, int *depth)
{
    def_ray(&data->ray_x, &data->ray_y, &data->x_offset, &data->y_offset);
    (*depth)++;
}
