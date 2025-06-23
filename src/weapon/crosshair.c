/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** crosshair
*/

#include "utils.h"
#include "struct.h"

void init_crosshair(sfRenderWindow *window, assets_t *crosshair)
{
    sfVector2u size;

    (void)window;
    crosshair->gun.cross_texture = sfTexture_createFromFile(
        "assets/crosshair.png", NULL);
    if (!crosshair->gun.cross_texture)
        return;
    crosshair->gun.cross_sprite = sfSprite_create();
    sfSprite_setTexture(crosshair->gun.cross_sprite,
        crosshair->gun.cross_texture, sfTrue);
    size = sfTexture_getSize(crosshair->gun.cross_texture);
    sfSprite_setOrigin(crosshair->gun.cross_sprite, (sfVector2f){size.x / 2.0f,
        size.y / 2.0f});
}

void draw_crosshair(sfRenderWindow *window, assets_t *crosshair)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f center = {(float)window_size.x / 2, (float)window_size.y / 2};
    float width;
    float height;
    float x_scale;
    float y_scale;
    float scale;

    sfSprite_setPosition(crosshair->gun.cross_sprite, center);
    width = 800.0f;
    height = 600.0f;
    x_scale = window_size.x / width;
    y_scale = window_size.y / height;
    scale = fminf(x_scale, y_scale);
    sfSprite_setScale(crosshair->gun.cross_sprite, (sfVector2f){scale * 0.3f,
        scale * 0.3f});
    sfRenderWindow_drawSprite(window, crosshair->gun.cross_sprite, NULL);
}
