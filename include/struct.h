/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** struct
*/

#ifndef INCLUDED_STRUCT_H
    #define INCLUDED_STRUCT_H

    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
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

typedef struct {
    sfRenderWindow *window;
    sfRectangleShape *tile;
    sfVector2f offset;
    float scaled_tile;
} MapParameters_t;

typedef enum {
    MENU,
    GAME
} State_t;

typedef struct {
    sfTexture *t_texture;
    sfSprite *t_sprite;
    sfIntRect t_frame_rect;
    int t_frame_count;
    int t_columns;
    int t_current_frame;
    float t_frame_duration;
    float t_time_since;
    int t_width;
    int t_height;
    float t_wobble_pos;
    float t_movement;
    sfVector2f t_origin;

    sfTexture *g_texture;
    sfSprite *g_sprite;
    sfIntRect g_frame_rect;
    int g_frame_count;
    int g_columns;
    int g_current_frame;
    float g_frame_duration;
    float g_time_since;
    int g_width;
    int g_height;
    float g_wobble_pos;
    float g_movement;
    sfVector2f g_origin;
    bool firing;
    sfSprite *cross_sprite;
    sfTexture *cross_texture;
    sfFont *ammo_font;
    sfText *ammo_text;
} assets_t;

#endif
