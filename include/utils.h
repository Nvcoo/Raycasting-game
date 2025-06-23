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
    #include <SFML/Audio/Music.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/Window/Event.h>
    #include <math.h>
    #include <stdio.h>
    #include "struct.h"
    #include <stdbool.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Vector3.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>


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
void init_ammo_text(assets_t *assets);
void ammo_text(assets_t *assets, sfRenderWindow *window);
int game_loop(sfRenderWindow *window);
void init_game(Player_t *player, assets_t *assets, sfRenderWindow *window);
int events(sfRenderWindow *window, sfEvent event, Player_t *player,
    assets_t *assets);
void game_functions(Player_t *player, sfRenderWindow *window,
    assets_t *assets);
void mouse_rotation(sfRenderWindow *window, Player_t *player);
void relative_pause(Player_t *player, sfRenderWindow *window);
void resolution_view(sfRenderWindow *window);
void destroy_assets(assets_t *assets, sfClock *torch_clock,
    sfClock *gun_clock);
void toggle_condition(assets_t *gun, float *elapsed);
void init_horizontal_ray(Player_t player, float ray_angle,
    HorizontalData_t *ray_data);
void init_vertical_ray(Player_t player, float ray_angle,
    VerticalData_t *ray_data);
void available_horizontal_path(HorizontalData_t *data, int *depth);
void available_vertical_path(VerticalData_t *data, int *depth);
void set_player(sfRectangleShape *square, float scaled_tile,
    sfVector2f position, sfTexture *texture);
void rotation(Player_t *player);
void adjust_map(MapParameters_t *params);
void floor_coloring(sfColor *color, float shade);
void ceiling_coloring(sfColor *color, float shade);
void init_health_text(assets_t *assets);
void health_text(assets_t *assets, sfRenderWindow *window);
void init_bottom_layer(assets_t *assets);
void update_bottom_layer(assets_t *assets, sfRenderWindow *window);
void destroy_bottom_hud(assets_t *assets);
void init_stamina_text(assets_t *assets);
void stamina_text(assets_t *assets, sfRenderWindow *window);
void draw_menu(assets_t *assets, sfRenderWindow *window);
void init_menu(assets_t *assets);
void set_bg(assets_t *assets, sfVector2f scale, sfRenderWindow *window);
void init_menu(assets_t *assets);
void handle_menu(sfEvent *event, assets_t *assets, sfRenderWindow *window);
void save_game(assets_t *assets);
menu_pos_t calculate_pos(assets_t *assets, sfRenderWindow *window,
    scale_t scale);
scale_t calculate_scales(assets_t *assets, sfRenderWindow *window);
int load_game(void);
void set_key(assets_t *assets, sfVector2f buttons_scaling,
    float key_x, float key_y);
void set_up_buttons(sfSprite *sprite, sfVector2f scale, sfVector2f pos);

#endif
