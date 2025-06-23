/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** torch_math
*/

#include "utils.h"
#include "struct.h"

void t_animation_math(assets_t *torch, int *column, int *row)
{
    torch->torch.t_current_frame =
        (torch->torch.t_current_frame + 1) % torch->torch.t_frame_count;
    *column = torch->torch.t_current_frame % torch->torch.t_columns;
    *row = torch->torch.t_current_frame / torch->torch.t_columns;
    torch->torch.t_frame_rect.left = *column * torch->torch.t_width;
    torch->torch.t_frame_rect.top = *row * torch->torch.t_height;
    sfSprite_setTextureRect(torch->torch.t_sprite, torch->torch.t_frame_rect);
    torch->torch.t_time_since = 0.0f;
}
