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
    torch->torch.t_frame_count = 8;
    torch->torch.t_columns = 4;
    torch->torch.t_width = 64;
    torch->torch.t_height = 64;
    torch->torch.t_current_frame = 0;
    torch->torch.t_frame_duration = 0.1f;
    torch->torch.t_time_since = 0.0f;
}
