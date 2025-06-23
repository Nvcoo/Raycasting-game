/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** set_player
*/

#include "utils.h"

void set_player(sfRectangleShape *square, float scaled_tile,
    sfVector2f position, sfTexture *texture)
{
    sfRectangleShape_setSize(square, (sfVector2f){scaled_tile * 1.2,
        scaled_tile * 1.2});
    sfRectangleShape_setPosition(square, position);
    sfRectangleShape_setTexture(square, texture, sfTrue);
}
