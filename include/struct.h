/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** struct
*/

#ifndef INCLUDED_STRUCT_H
    #define INCLUDED_STRUCT_H

    #include <stdbool.h>

typedef struct {
    float x;
    float y;
    float angle;
    bool show_map;
} Player_t;

typedef struct {
    float distance;
    bool vertical_wall;
} ray_t;

typedef struct {
    float ray_x;
    float ray_y;
    float x_offset;
    float y_offset;
} HorizontalData_t;

typedef struct {
    float ray_x;
    float ray_y;
    float x_offset;
    float y_offset;
} VerticalData_t;

#endif
