/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** torch_presets
*/

#include "utils.h"
#include "struct.h"

void set_torch(assets_t *torch)
{
    torch->t_frame_count = 8;
    torch->t_columns = 4;
    torch->t_width = 64;
    torch->t_height = 64;
    torch->t_current_frame = 0;
    torch->t_frame_duration = 0.1f;
    torch->t_time_since = 0.0f;
}

void t_animation_math(assets_t *torch, int *column, int *row)
{
    torch->t_current_frame =
        (torch->t_current_frame + 1) % torch->t_frame_count;
    *column = torch->t_current_frame % torch->t_columns;
    *row = torch->t_current_frame / torch->t_columns;
    torch->t_frame_rect.left = *column * torch->t_width;
    torch->t_frame_rect.top = *row * torch->t_height;
    sfSprite_setTextureRect(torch->t_sprite, torch->t_frame_rect);
    torch->t_time_since = 0.0f;
}
