/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** mouse
*/

#include "utils.h"
#include "struct.h"

void mouse_rotation(sfRenderWindow *window, Player_t *player)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2i center = {window_size.x / 2, window_size.y / 2};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    int x_change = mouse_pos.x - center.x;
    float sensitivity = 0.0002f;

    if (mouse_pos.x >= 0 && mouse_pos.x < (int)window_size.x &&
        mouse_pos.y >= 0 && mouse_pos.y < (int)window_size.y) {
        player->angle += x_change * sensitivity;
        sfMouse_setPosition(center, (sfWindow *)window);
    }
    sfWindow_setMouseCursorVisible((sfWindow *)window, sfFalse);
}
