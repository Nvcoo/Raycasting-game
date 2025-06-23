/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** relative_pause
*/

#include "utils.h"
#include "struct.h"

void relative_pause(Player_t *player, sfRenderWindow *window)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    sfRectangleShape *blur = NULL;

    if (!player->show_map)
        return;
    blur = sfRectangleShape_create();
    sfRectangleShape_setSize(blur, (sfVector2f){size.x, size.y});
    sfRectangleShape_setPosition(blur, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(blur, sfColor_fromRGBA(0, 0, 0, 180));
    sfRenderWindow_drawRectangleShape(window, blur, NULL);
    draw_minimap(window, player);
    sfRectangleShape_destroy(blur);
}
