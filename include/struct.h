/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** struct
*/

#ifndef INCLUDED_STRUCT_H
    #define INCLUDED_STRUCT_H

    #include <SFML/Audio/Types.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Event.h>
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
} torch_t;

typedef struct {
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
    int ammo_count;
    sfSound *sound;
} gun_t;

typedef struct {
    sfTexture *menu_bg_texture;
    sfTexture *start_bg_texture;
    sfTexture *leave_bg_texture;
    sfTexture *up_texture;
    sfTexture *down_texture;
    sfTexture *audio_texture;
    sfTexture *help_texture;
    sfTexture *res_texture;
    sfTexture *key_texture;
    sfSprite *menu_bg_sprite;
    sfSprite *start_bg_sprite;
    sfSprite *leave_bg_sprite;
    sfSprite *up_sprite;
    sfSprite *down_sprite;
    sfSprite *audio_sprite;
    sfSprite *help_sprite;
    sfSprite *res_sprite;
    sfSprite *key_sprite;
    bool show_help;
} menu_t;

typedef struct {
    sfFont *health_font;
    sfText *health_text;
    sfTexture *bottom_texture;
    sfSprite *bottom_sprite;
    sfFont *stamina_font;
    sfText *stamina_text;
} hud_t;

typedef struct {
    torch_t torch;
    gun_t gun;
    menu_t menu;
    hud_t hud;
    sfMusic *bg_music;
    sfMusic *torch_music;
    bool is_fullscreen;
    State_t state;
} assets_t;

typedef struct {
    sfEvent *event;
    assets_t *assets;
    Player_t *player;
} core_t;

typedef struct {
    sfVector2f scale;
    sfVector2f scaling;
} scale_t;

typedef struct {
    float start_x;
    float start_y;
    float quit_x;
    float quit_y;
    float up_x;
    float up_y;
    float down_x;
    float down_y;
    float audio_x;
    float audio_y;
    float help_x;
    float help_y;
    float res_x;
    float res_y;
    float key_x;
    float key_y;
} menu_pos_t;

typedef struct {
    sfVector2u start_size;
    sfVector2u leave_size;
    sfVector2u up_size;
    sfVector2u down_size;
    sfVector2u audio_size;
    sfVector2u help_size;
    sfVector2u res_size;
    sfVector2u key_size;
} texture_size_t;

#endif
