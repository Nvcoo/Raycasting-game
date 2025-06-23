/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_torch
*/

#include "utils.h"
#include "struct.h"

void init_torch(sfRenderWindow *window, assets_t *torch)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f position;

    torch->torch.t_texture = sfTexture_createFromFile("assets/tor.png", NULL);
    if (!torch->torch.t_texture)
        return;
    sfTexture_setSmooth(torch->torch.t_texture, sfFalse);
    torch->torch.t_sprite = sfSprite_create();
    sfSprite_setTexture(torch->torch.t_sprite, torch->torch.t_texture, sfTrue);
    sfSprite_setScale(torch->torch.t_sprite, (sfVector2f){10.0f, 10.0f});
    set_torch(torch);
    torch->torch.t_frame_rect = (sfIntRect){0, 0, torch->torch.t_width,
        torch->torch.t_height};
    sfSprite_setTextureRect(torch->torch.t_sprite, torch->torch.t_frame_rect);
    position.x = window_size.x - torch->torch.t_width - 450;
    position.y = window_size.y - torch->torch.t_height - 600;
    torch->torch.t_wobble_pos = 0.0f;
    torch->torch.t_movement = 10.0f;
    torch->torch.t_origin = position;
    sfSprite_setPosition(torch->torch.t_sprite, position);
}
