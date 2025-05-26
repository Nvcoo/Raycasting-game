/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** torch
*/

#include "utils.h"
#include "struct.h"

void init_torch(sfRenderWindow *window, assets_t *torch)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f position;

    torch->t_texture = sfTexture_createFromFile("assets/torch.png", NULL);
    if (!torch->t_texture)
        return;
    sfTexture_setSmooth(torch->t_texture, sfFalse);
    torch->t_sprite = sfSprite_create();
    sfSprite_setTexture(torch->t_sprite, torch->t_texture, sfTrue);
    sfSprite_setScale(torch->t_sprite, (sfVector2f){8.0f, 8.0f});
    set_torch(torch);
    torch->t_frame_rect = (sfIntRect){0, 0, torch->t_width, torch->t_height};
    sfSprite_setTextureRect(torch->t_sprite, torch->t_frame_rect);
    position.x = window_size.x - torch->t_width - 500;
    position.y = window_size.y - torch->t_height - 300;
    torch->t_wobble_pos = 0.0f;
    torch->t_movement = 10.0f;
    torch->t_origin = position;
    sfSprite_setPosition(torch->t_sprite, position);
}

void update_torch(sfRenderWindow *window, assets_t *torch, sfClock *clock)
{
    float elapsed = sfTime_asSeconds(sfClock_restart(clock));
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f next_pos;
    int column;
    int row;
    float offset;

    torch->t_time_since += elapsed;
    if (torch->t_time_since >= torch->t_frame_duration)
        t_animation_math(torch, &column, &row);
    torch->t_origin.x = window_size.x - torch->t_width - 500;
    torch->t_origin.y = window_size.y - torch->t_height - 300;
    torch->t_wobble_pos += elapsed * 8.0f;
    if (torch->t_wobble_pos >= 2 * M_PI)
        torch->t_wobble_pos -= 2 * M_PI;
    offset = sinf(torch->t_wobble_pos) * torch->t_movement;
    next_pos = torch->t_origin;
    next_pos.y += offset;
    sfSprite_setPosition(torch->t_sprite, next_pos);
}

void destroy_torch(assets_t *torch)
{
    if (torch->t_sprite)
        sfSprite_destroy(torch->t_sprite);
    if (torch->t_texture)
        sfTexture_destroy(torch->t_texture);
}
