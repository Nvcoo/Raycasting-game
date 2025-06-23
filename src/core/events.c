/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** events
*/

#include "utils.h"
#include "struct.h"

int events(sfRenderWindow *window, sfEvent event, Player_t *player,
    assets_t *assets)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        assets->gun.firing = true;
    else
        assets->gun.firing = false;
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyR))
        assets->gun.ammo_count = 121;
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
        player->show_map = !player->show_map;
    if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape)) {
            assets->state = MENU;
            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
        }
    return 0;
}
