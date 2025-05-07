/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** main
*/

#include "struct.h"
#include "utils.h"

void mouse_rotation(sfRenderWindow *window, Player_t *player)
{
    sfVector2i center = {400, 300};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    int x_change = mouse_pos.x - center.x;
    float sensitivity = 0.0002f;

    player->angle += x_change * sensitivity;
    sfMouse_setPosition(center, (sfWindow *)window);
    sfWindow_setMouseCursorVisible((sfWindow *)window, sfFalse);
}

static void cleanup_background(sfRectangleShape *floor)
{
    sfRectangleShape_destroy(floor);
}

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

int events(sfRenderWindow *window, sfEvent event, Player_t *player,
    sfRectangleShape *ceiling)
{
    sfRectangleShape *floor = NULL;

    floor = grass(window);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyM)
            player->show_map = !player->show_map;
    }
    update_player(player);
    mouse_rotation(window, player);
    sfRenderWindow_clear(window, sfBlack);
    draw_floor_and_ceiling(window, ceiling, floor);
    cast_all_rays(window, player);
    relative_pause(player, window);
    sfRenderWindow_display(window);
    return 0;
}

static void resolution_view(sfRenderWindow *window)
{
    sfView *view;
    sfVector2u window_size = sfRenderWindow_getSize(window);

    view = sfView_createFromRect((sfFloatRect)
    {0, 0, window_size.x, window_size.y});
    sfRenderWindow_setView(window, view);
    sfView_destroy(view);
}

int game_loop(sfRenderWindow *window, sfTexture *sky_texture)
{
    sfEvent event;
    Player_t player;
    sfRectangleShape *ceiling = NULL;

    init_player(&player);
    while (sfRenderWindow_isOpen(window)) {
        ceiling = sky(window, sky_texture, &player);
        events(window, event, &player, ceiling);
        resolution_view(window);
        sfRectangleShape_destroy(ceiling);
    }
    return 0;
}

static void cleanup_window(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
}

int main(void)
{
    sfRectangleShape *floor = NULL;
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfTexture *sky_texture = sfTexture_createFromFile("assets/sunset.png",
        NULL);

    window = sfRenderWindow_create(mode, "3D", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    sfRenderWindow_setFramerateLimit(window, 60);
    game_loop(window, sky_texture);
    sfTexture_destroy(sky_texture);
    cleanup_background(floor);
    cleanup_window(window);
    return 0;
}
