/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** utils
*/

#ifndef INCLUDED_UTILS_H
    #define INCLUDED_UTILS_H

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window/VideoMode.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Window/Event.h>
    #include <math.h>
    #include <stdio.h>
    #include "struct.h"
    #include <stdbool.h>

    #define TILE_SIZE 64
    #define MAP_WIDTH 24
    #define MAP_HEIGHT 24
    #define FOV (M_PI * 0.3) //originally *0.4
    #define NUM_RAYS 1920
    #define SMALL_RES_RAYS 800
    #define P2 (M_PI / 2)
    #define P3 (3 * M_PI / 2)
    #define PI 3.141592

extern const int map[MAP_HEIGHT][MAP_WIDTH];
void draw_map(sfRenderWindow *window);
void init_player(Player_t *player);
int is_wall(int x, int y);
ray_t cast_single_ray(Player_t player, float ray_angle, sfRenderWindow *win);
void cast_all_rays(sfRenderWindow *window, Player_t *player);
void draw_player(sfRenderWindow *window, Player_t *player);
void draw_floor_and_ceiling(sfRenderWindow *window);
void render_wall_column(sfRenderWindow *window, int column,
    float wall_height, sfColor color);
void update_player(Player_t *player);
sfRectangleShape *grass(sfRenderWindow *window);
void draw_minimap(sfRenderWindow *window, Player_t *player);
void drawSky(sfRenderWindow *window, sfTexture *sky_texture, Player_t *player);
void ray_equivalence(float *ray_x, float *ray_y, int *depth,
    Player_t *player);
void ray_progress(int *move_x, int *move_y, float *ray_x, float *ray_y);
void def_ray(float *ray_x, float *ray_y, float *x_offset,
    float *y_offset);
void x_offset_progress(float *x_offset, float *y_offset, float *aTan);
void y_offset_progress(float *x_offset, float *y_offset, float *nTan);
void choose_ray(float horizontal_dist, float vertical_dist, ray_t *result);
float normalize_angle(float ray_angle);
void coloring(ray_t ray, sfColor *color);
void forwards(float x_update, float y_update, Player_t *player, float step);
void left_right(float x_update, float y_update, Player_t *player, float step);
void draw_tiles(int height, int width, sfRectangleShape *tile);
float handle_vertical_ray(Player_t player, float ray_angle);
float handle_horizontal_ray(Player_t player, float ray_angle);
void draw_ceiling(sfRenderWindow* window, const int horizon,
    const float range);
void draw_floor(sfRenderWindow *window, const int horizon, const float range);
void init_torch(sfRenderWindow *window, assets_t *torch);
void update_torch(sfRenderWindow *window, assets_t *torch, sfClock *clock);
void destroy_torch(assets_t *torch);
void t_animation_math(assets_t *torch, int *column, int *row);
void set_torch(assets_t *torch);
void set_gun(assets_t *gun);
void g_animation_math(assets_t *gun, int *column, int *row);
void init_gun(sfRenderWindow *window, assets_t *gun);
void update_gun(sfRenderWindow *window, assets_t *gun, sfClock *clock);
void destroy_gun(assets_t *gun);
void minimap_layer(sfRenderWindow *window);
void draw_crosshair(sfRenderWindow *window, assets_t *crosshair);
void init_crosshair(sfRenderWindow *window, assets_t *crosshair);
void ammo_text(assets_t *assets);

#endif
