/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** destroy_torch
*/

#include "utils.h"
#include "struct.h"

void destroy_torch(assets_t *torch)
{
    if (torch->torch.t_sprite)
        sfSprite_destroy(torch->torch.t_sprite);
    if (torch->torch.t_texture)
        sfTexture_destroy(torch->torch.t_texture);
}
