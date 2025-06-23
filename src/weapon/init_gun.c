/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_gun
*/

#include "utils.h"
#include "struct.h"

void prep_gun(assets_t *gun)
{
    sfTexture_setSmooth(gun->gun.g_texture, sfFalse);
    gun->gun.g_sprite = sfSprite_create();
    sfSprite_setTexture(gun->gun.g_sprite, gun->gun.g_texture, sfTrue);
    sfSprite_setScale(gun->gun.g_sprite, (sfVector2f){2.7f, 2.7f});
    set_gun(gun);
}

void set_gun_sound(sfSoundBuffer *buffer, assets_t *gun)
{
    buffer = sfSoundBuffer_createFromFile("assets/gun.ogg");
    gun->gun.sound = sfSound_create();
    sfSound_setBuffer(gun->gun.sound, buffer);
    sfSound_setLoop(gun->gun.sound, sfTrue);
}

void init_gun(sfRenderWindow *window, assets_t *gun)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f position;
    sfSoundBuffer *buffer = NULL;

    gun->gun.g_texture = sfTexture_createFromFile("assets/gun.png", NULL);
    if (!gun->gun.g_texture)
        return;
    prep_gun(gun);
    gun->gun.g_frame_rect = (sfIntRect){10, 0, gun->gun.g_width,
        gun->gun.g_height};
    sfSprite_setTextureRect(gun->gun.g_sprite, gun->gun.g_frame_rect);
    position.x = window_size.x - gun->gun.g_width - 1550;
    position.y = window_size.y - gun->gun.g_height - 140;
    gun->gun.g_wobble_pos = 0.0f;
    gun->gun.g_movement = 10.0f;
    gun->gun.g_origin = position;
    sfSprite_setPosition(gun->gun.g_sprite, position);
    set_gun_sound(buffer, gun);
}
