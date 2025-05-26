/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** weapon
*/

#include "utils.h"
#include "struct.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

void init_gun(sfRenderWindow *window, assets_t *gun)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f position;

    gun->g_texture = sfTexture_createFromFile("assets/gun.png", NULL);
    if (!gun->g_texture)
        return;
    sfTexture_setSmooth(gun->g_texture, sfFalse);
    gun->g_sprite = sfSprite_create();
    sfSprite_setTexture(gun->g_sprite, gun->g_texture, sfTrue);
    sfSprite_setScale(gun->g_sprite, (sfVector2f){2.5f, 2.5f});
    set_gun(gun);
    gun->g_frame_rect = (sfIntRect){10, 0, gun->g_width, gun->g_height};
    sfSprite_setTextureRect(gun->g_sprite, gun->g_frame_rect);
    position.x = window_size.x - gun->g_width - 1300;
    position.y = window_size.y - gun->g_height - 140;
    gun->g_wobble_pos = 0.0f;
    gun->g_movement = 10.0f;
    gun->g_origin = position;
    sfSprite_setPosition(gun->g_sprite, position);
}

void toggle_condition(assets_t *gun, float *elapsed)
{
    int column;
    int row;

    if (gun->firing) {
        gun->g_time_since += *elapsed;
        if (gun->g_time_since >= gun->g_frame_duration) {
            g_animation_math(gun, &column, &row);
        }
    } else {
        gun->g_frame_rect.left = 0;
        gun->g_frame_rect.top = 0;
        sfSprite_setTextureRect(gun->g_sprite, gun->g_frame_rect);
    }
}

void update_gun(sfRenderWindow *window, assets_t *gun, sfClock *clock)
{
    float elapsed = sfTime_asSeconds(sfClock_restart(clock));
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f next_pos;
    float offset;

    toggle_condition(gun, &elapsed);
    gun->g_origin.x = window_size.x - gun->g_width - 1300;
    gun->g_origin.y = window_size.y - gun->g_height - 140;
    gun->g_wobble_pos += elapsed * 8.0f;
    if (gun->g_wobble_pos >= 2 * M_PI)
        gun->g_wobble_pos -= 2 * M_PI;
    offset = sinf(gun->g_wobble_pos) * gun->g_movement;
    next_pos = gun->g_origin;
    next_pos.y += offset;
    sfSprite_setPosition(gun->g_sprite, next_pos);
}

void destroy_gun(assets_t *gun)
{
    if (gun->g_sprite)
        sfSprite_destroy(gun->g_sprite);
    if (gun->g_texture)
        sfTexture_destroy(gun->g_texture);
}
