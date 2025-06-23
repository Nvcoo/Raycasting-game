/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** main
*/

#include "utils.h"

static void cleanup_window(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
}

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "3D", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    sfRenderWindow_setFramerateLimit(window, 60);
    game_loop(window);
    cleanup_window(window);
    return 0;
}
