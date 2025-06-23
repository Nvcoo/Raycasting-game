/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** torch
*/

#include "utils.h"
#include "struct.h"

void update_torch(sfRenderWindow *window, assets_t *torch, sfClock *clock)
{
    float elapsed = sfTime_asSeconds(sfClock_restart(clock));
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f next_pos;
    int column;
    int row;
    float offset;

    torch->torch.t_time_since += elapsed;
    if (torch->torch.t_time_since >= torch->torch.t_frame_duration)
        t_animation_math(torch, &column, &row);
    torch->torch.t_origin.x = window_size.x - torch->torch.t_width - 450;
    torch->torch.t_origin.y = window_size.y - torch->torch.t_height - 600;
    torch->torch.t_wobble_pos += elapsed * 8.0f;
    if (torch->torch.t_wobble_pos >= 2 * M_PI)
        torch->torch.t_wobble_pos -= 2 * M_PI;
    offset = sinf(torch->torch.t_wobble_pos) * torch->torch.t_movement;
    next_pos = torch->torch.t_origin;
    next_pos.y += offset;
    sfSprite_setPosition(torch->torch.t_sprite, next_pos);
}
