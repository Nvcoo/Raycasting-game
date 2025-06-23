/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** resolution_view
*/

#include "utils.h"

void resolution_view(sfRenderWindow *window)
{
    sfView *view;
    sfVector2u window_size = sfRenderWindow_getSize(window);

    view = sfView_createFromRect((sfFloatRect)
    {0, 0, window_size.x, window_size.y});
    sfRenderWindow_setView(window, view);
    sfView_destroy(view);
}
